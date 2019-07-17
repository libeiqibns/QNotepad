#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    open_file = "";
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_QNotePad_triggered()
{

}

void MainWindow::on_actionselect_all_Ctrl_A_triggered()
{
    ui->textEdit->selectAll();
}

void MainWindow::on_actionCut_Ctrl_X_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_Ctrl_C_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_Ctrl_V_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_Ctrl_Z_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_Shift_Ctrl_Z_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionNew_Ctrl_N_triggered()
{
    open_file = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_Shift_Ctrl_N_triggered()
{

}

void MainWindow::on_actionSave_Ctrl_S_triggered()
{

}

void MainWindow::on_actionSave_as_Shift_Ctrl_S_triggered()
{

}
