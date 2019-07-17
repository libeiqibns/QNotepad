#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

signals:
    void find_next_clicked(QString search_string);
    void find_prev_clicked(QString search_string);

private:
    Ui::FindDialog *ui;
    QString search_string;

private slots:
    void set_find_next();
    void set_find_prev();
};

#endif // FINDDIALOG_H
