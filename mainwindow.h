#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sBoxX_valueChanged(int);
    void on_sBoxY_valueChanged(int);
    void on_sBoxRadius_valueChanged(int);
    void on_tButtonColor_clicked();

private:
    Ui::MainWindow * ui;
};

#endif // MAINWINDOW_H
