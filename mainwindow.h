#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

    void on_actionNew_Ctrl_N_triggered();

    void on_actionOpen_Shift_Ctrl_N_triggered();

    void on_actionSave_Ctrl_S_triggered();

    void on_actionSave_as_Shift_Ctrl_S_triggered();

private:
    Ui::MainWindow *ui;
    QString open_file;
};

#endif // MAINWINDOW_H
