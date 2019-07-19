#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QString>

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    QString open_file;
    bool unsaved_change;

    CodeEditor(QWidget *parent = nullptr);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

signals:
    void cursor_position_change(QString &text);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void on_cursor_move();

private:
    QWidget *lineNumberArea;
};

#endif // CODEEDITOR_H
