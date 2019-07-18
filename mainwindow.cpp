#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QTextDocument>

void MainWindow::on_textEdit_change()
{
//    QMessageBox::information(this,"","text changed");
    unsaved_change = true;
    this->setWindowTitle(open_file == "" ? "New File": open_file + " (unsaved changes)");
}

void MainWindow::on_find_next(QString search_string)
{
//    QMessageBox::information(this,"","next clicked");
    ui->textEdit->find(search_string);
}

void MainWindow::on_find_prev(QString search_string)
{
//    QMessageBox::information(this,"","prev clicked");
    ui->textEdit->find(search_string,QTextDocument::FindBackward);
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
    setupEditor();
    setCentralWidget(ui->textEdit);
    ui->statusBar->addPermanentWidget(ui->label);
    this->setWindowTitle("New File");
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(on_textEdit_change()));
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

bool MainWindow::on_actionNew_Ctrl_N_triggered()
{
    QMessageBox::StandardButton reply = check_unsaved_changes();
    if (reply == QMessageBox::Yes) on_actionSave_Ctrl_S_triggered();
    else if (reply == QMessageBox::No){;}
    else  return false;
    open_file = "";
    ui->textEdit->setPlainText("");
    this->setWindowTitle("New File");
    unsaved_change = false;
    return true;
}

bool MainWindow::on_actionOpen_Shift_Ctrl_N_triggered()
{
    QMessageBox::StandardButton reply = check_unsaved_changes();
    if (reply == QMessageBox::Yes) on_actionSave_Ctrl_S_triggered();
    else if (reply == QMessageBox::No){;}
    else  return false;
    QString file_name = QFileDialog::getOpenFileName(this,"Open File", QDir::rootPath());
    QFile file(file_name);
    if (!file.open(QFile::Text | QFile::ReadOnly)){
        if (file_name != "") QMessageBox::warning(this,"Error","Cannot open file" + file_name);
        return false;
    }
    open_file = file_name;
    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    this->setWindowTitle(open_file);
    file.close();
    unsaved_change = false;
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
    out << ui->textEdit->toPlainText();
    file.flush();
    file.close();
    this->setWindowTitle(open_file);
    unsaved_change = false;
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
    out << ui->textEdit->toPlainText();
    this->setWindowTitle(open_file);
    file.flush();
    file.close();
    this->setWindowTitle(open_file);
    unsaved_change = false;
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

    ui->textEdit->setFont(font);

    highlighter = new Highlighter(ui->textEdit->document());
}

QMessageBox::StandardButton MainWindow::check_unsaved_changes()
{
    if (!unsaved_change) return QMessageBox::No;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Save changes"
                                                              ,"Current file has unsaved changes. Save Now?"
                                                              ,QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
                                                              ,QMessageBox::Cancel);

    return reply;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply = check_unsaved_changes();
    if (reply == QMessageBox::Yes) {
        if (on_actionSave_Ctrl_S_triggered()){
            event->accept();
        } else {
            event->ignore();
        }
    }
    else if (reply == QMessageBox::No){
        event->accept();
    }
    else{
        event->ignore();
    }
}

