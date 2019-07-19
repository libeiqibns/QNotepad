#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>

void MainWindow::on_textEdit_change()
{
//    QMessageBox::information(this,"","text changed");
    unsaved_change = true;
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->unsaved_change = true;
}

void MainWindow::on_find_next(QString search_string)
{
//    QMessageBox::information(this,"","next clicked");
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->find(search_string);
}

void MainWindow::on_find_prev(QString search_string)
{
//    QMessageBox::information(this,"","prev clicked");
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->find(search_string,QTextDocument::FindBackward);
}

void MainWindow::on_text_cursor_move(QString & text)
{
    ui->label->setText(text);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    open_file = "";
    unsaved_change = false;
    ui->setupUi(this);
    setCentralWidget(ui->tabWidget);
    ui->statusBar->addPermanentWidget(ui->label);
    this->setWindowTitle("New File");


    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(new CodeEditor(this),"New File");

    setupEditor();
    connect(ui->tabWidget->currentWidget(),SIGNAL(textChanged()),this,SLOT(on_textEdit_change()));
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
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->selectAll();
}

void MainWindow::on_actionCut_Ctrl_X_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->cut();
}

void MainWindow::on_actionCopy_Ctrl_C_triggered()
{
   static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->copy();
}

void MainWindow::on_actionPaste_Ctrl_V_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->paste();
}

void MainWindow::on_actionUndo_Ctrl_Z_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->undo();
}

void MainWindow::on_actionRedo_Shift_Ctrl_Z_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->redo();
}

bool MainWindow::on_actionNew_Ctrl_N_triggered()
{
    open_file = "";
    ui->tabWidget->addTab(new CodeEditor(this),"New File" + QString::number(ui->tabWidget->currentIndex()));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    setupEditor();
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setPlainText("");
    this->setWindowTitle("New File" + QString::number(ui->tabWidget->currentIndex()));
    unsaved_change = false;
    setupEditor();
    connect(ui->tabWidget->currentWidget(),SIGNAL(textChanged()),this,SLOT(on_textEdit_change()));
    ui->label->setText("");
    return true;
}

bool MainWindow::on_actionOpen_Shift_Ctrl_N_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open File", QDir::rootPath());
    QFile file(file_name);
    if (!file.open(QFile::Text | QFile::ReadOnly)){
        if (file_name != "") QMessageBox::warning(this,"Error","Cannot open file" + file_name);
        return false;
    }
    open_file = file_name;
    QTextStream in(&file);
    ui->tabWidget->addTab(new CodeEditor(this),file_name);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->open_file = file_name;
    setupEditor();
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setPlainText(in.readAll());
    this->setWindowTitle(open_file);
    file.close();
    unsaved_change = false;
    setupEditor();
    connect(ui->tabWidget->currentWidget(),SIGNAL(textChanged()),this,SLOT(on_textEdit_change()));
    ui->label->setText("");
    return true;
}

bool MainWindow::on_actionSave_Ctrl_S_triggered()
{
    QFile file(open_file);
    if (!file.open(QFile::Text | QFile::WriteOnly)){
        return on_actionSave_as_Shift_Ctrl_S_triggered();
    }
    QTextStream out(&file);
    out << static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->toPlainText();
    file.flush();
    file.close();
    this->setWindowTitle(open_file);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->unsaved_change = false;
    return true;
}

bool MainWindow::on_actionSave_as_Shift_Ctrl_S_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Save as", QDir::rootPath());
    QFile file(file_name);
    if (!file.open(QFile::Text | QFile::WriteOnly)){
        if (file_name != "") QMessageBox::warning(this,"Error","Cannot save file" + file_name);
        return false;
    }
    open_file = file_name;
    QTextStream out(&file);
    out <<static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->toPlainText();
    this->setWindowTitle(open_file);
    file.flush();
    file.close();
    this->setWindowTitle(open_file);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->unsaved_change = false;
    return true;
}

void MainWindow::on_actionFind_Ctrl_F_triggered()
{
    find_dialog = new FindDialog(this);
    find_dialog->setAttribute(Qt::WA_DeleteOnClose);
    find_dialog->show();
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setFont(font);

    highlighter = new Highlighter(static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->document());
}

QMessageBox::StandardButton MainWindow::check_unsaved_changes()
{
    if (!static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->unsaved_change) return QMessageBox::No;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Save changes"
                                                              ,"Current file has unsaved changes. Save Now?"
                                                              ,QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
                                                              ,QMessageBox::Cancel);

    return reply;

}

void MainWindow::closeEvent(QCloseEvent *event)
{
//    QMessageBox::StandardButton reply = check_unsaved_changes();
//    if (reply == QMessageBox::Yes) {
//        if (on_actionSave_Ctrl_S_triggered()){
//            event->accept();
//        } else {
//            event->ignore();
//        }
//    }
//    else if (reply == QMessageBox::No){
//        event->accept();
//    }
//    else{
//        event->ignore();
//    }
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->setCurrentIndex(index);
    QMessageBox::StandardButton reply = check_unsaved_changes();
    if (reply == QMessageBox::Yes) {
        if (on_actionSave_Ctrl_S_triggered()){
            ;
        } else {
            return;
        }
    }
    else if (reply == QMessageBox::No){
        ;
    }
    else{
        return;
    }
    ui->tabWidget->removeTab(index);
}
