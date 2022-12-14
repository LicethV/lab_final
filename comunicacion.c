//Configuracion de parametros

#include <stdio.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>

#define ECHOMAX 255 

void DieWithError(char *errorMessage);


int main(int argc, char *argv[]) 
{
	int sock;
	struct sockaddr_in echoServAddr;
	struct sockaddr_in fromAddr;
	unsigned short echoServPort; 
	unsigned int fromSize;
	char *servlP;
	char *echoString; 
	char echoBuffer[ECHOMAX+1];
        int echoStringLen; 
	int respStringLen; 

	if ((argc < 3) || (argc > 4)) 
	{
		
		fprintf(stderr,"Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]); 
		exit(1);
	}
	
	servlP = argv[1] ; //Direccion IP del servidor
	echoString = argv[2] ; 	//Cadena para hacer echo

	if ((echoStringLen = strlen(echoString)) > ECHOMAX) 
	DieWithError("Echo word too long"); 	

	if (argc == 4) 
		echoServPort = atoi(argv[3]) ; 
	else
		echoServPort = 7;

	//Creacion y configuracion de Sockets
	if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
		DieWithError( "socket () failed") ;

	//v
	//v
	//v
	//Construccion de estructuras de direcciones del servidor
	memset(&echoServAddr, 0, sizeof(echoServAddr)); 	
	echoServAddr.sin_family = AF_INET; 
	echoServAddr.sin_addr.s_addr = inet_addr(servlP);
	echoServAddr.sin_port = htons(echoServPort);

	//Envio de cadena al servidor
	if (sendto(sock, echoString, echoStringLen, 0, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) != echoStringLen) 
	DieWithError("sendto() sent a different number of bytes than expected\n"); 
	
	//Recibir una respuesta
	fromSize = sizeof(fromAddr) ;
	
	if ((respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 0,(struct sockaddr *) &fromAddr, &fromSize)) != echoStringLen)

		DieWithError("recvfrom() failed") ; 

	if (echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr) 
	{

		fprintf(stderr,"Error: received a packet from unknown source.\n");
		exit(1); 
	}

	echoBuffer[respStringLen] = '\0' ;
	printf("Received: %s\n", echoBuffer);
	close(sock); 
	exit(0);
}

void DieWithError (char *errorMessage)
{
	printf("\n%s\n", errorMessage);
	exit(1);
}	
