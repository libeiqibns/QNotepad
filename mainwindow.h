#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include "finddialog.h"
#include "highlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void on_textEdit_change();
    void on_find_next(QString );
    void on_find_prev(QString);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_QNotePad_triggered();

    void on_actionselect_all_Ctrl_A_triggered();

    void on_actionCut_Ctrl_X_triggered();

    void on_actionCopy_Ctrl_C_triggered();

    void on_actionPaste_Ctrl_V_triggered();

    void on_actionUndo_Ctrl_Z_triggered();

    void on_actionRedo_Shift_Ctrl_Z_triggered();

    bool on_actionNew_Ctrl_N_triggered();

    bool on_actionOpen_Shift_Ctrl_N_triggered();

    bool on_actionSave_Ctrl_S_triggered();

    bool on_actionSave_as_Shift_Ctrl_S_triggered();

    void on_actionFind_Ctrl_F_triggered();

private:
    Ui::MainWindow *ui;
    Highlighter *highlighter;
    QString open_file;
    bool unsaved_change;
    FindDialog *find_dialog;

    void setupEditor();
    QMessageBox::StandardButton check_unsaved_changes();
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
