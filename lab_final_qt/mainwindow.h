#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Valoresmotor_clicked();

    void on_Velocidad_textChanged();

    void on_Frecuencia_textChanged();

    void on_Voltaje_textChanged();

    void on_Temp_textChanged();

    void on_Time_textChanged();

    void on_Valores_Referencia_clicked();

    void on_VALORESTABLE_cellChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
