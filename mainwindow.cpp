#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sBoxX->setValue( ui->openGlWidget->getX() );
    ui->sBoxY->setValue( ui->openGlWidget->getY() );
    ui->sBoxRadius->setValue( ui->openGlWidget->getRadius() );
    ui->tButtonColor->setText( ui->openGlWidget->getColor().name() );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sBoxX_valueChanged(int arg1)
{
    ui->openGlWidget->setX( arg1 );
    ui->openGlWidget->updateGL();
}
void MainWindow::on_sBoxY_valueChanged(int arg1)
{
    ui->openGlWidget->setY( arg1 );
    ui->openGlWidget->updateGL();
}
void MainWindow::on_sBoxRadius_valueChanged(int arg1)
{
    ui->openGlWidget->setRadius( arg1 );
    ui->openGlWidget->updateGL();
}
void MainWindow::on_tButtonColor_clicked()
{
    const QColor & color = QColorDialog::getColor( ui->openGlWidget->getColor(), this );
    if ( !color.isValid() )
        return;

    ui->openGlWidget->setColor( color );
    ui->openGlWidget->updateGL();

    ui->tButtonColor->setText( ui->openGlWidget->getColor().name() );
}
