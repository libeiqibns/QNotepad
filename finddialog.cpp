#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_next, SIGNAL(clicked()),this,SLOT(set_find_next()));
    connect(ui->pushButton_prev, SIGNAL(clicked()),this,SLOT(set_find_prev()));
    connect(this,SIGNAL(find_next_clicked(QString)),parent,SLOT(on_find_next(QString)));
    connect(this,SIGNAL(find_prev_clicked(QString)),parent,SLOT(on_find_prev(QString)));
}

FindDialog::~FindDialog()
{
    disconnect(ui->pushButton_next, SIGNAL(clicked()),this,SLOT(set_find_next()));
    disconnect(ui->pushButton_prev, SIGNAL(clicked()),this,SLOT(set_find_prev()));
    disconnect(this,SIGNAL(find_next_clicked(QString)),parent(),SLOT(on_find_next(QString)));
    disconnect(this,SIGNAL(find_prev_clicked(QString)),parent(),SLOT(on_find_prev(QString)));
    delete ui;
}

void FindDialog::set_find_next()
{
    search_string = ui->lineEdit->text();
    emit find_next_clicked(search_string);
}

void FindDialog::set_find_prev()
{
    search_string = ui->lineEdit->text();
    emit find_prev_clicked(search_string);
}
