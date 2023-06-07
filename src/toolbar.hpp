#ifndef toolbar_hpp
#define toolbar_hpp

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit>

class ToolBar : public QToolBar {
private:
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;

    QMdiArea * mdiArea;
public:
    ToolBar(QMainWindow * window, QMdiArea * mdiArea);
};

#endif
