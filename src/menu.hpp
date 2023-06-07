#ifndef menu_hpp
#define menu_hpp

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit>

class MenuBar : public QMenuBar {
private:
    QMenu *fileMenu;
    QMenu *editarMenu;
    QMenu *formatarMenu;
    QMenu *exibirMenu;
    QMenu *configuracoesMenu;
    QMenu *helpMenu;

    QMdiArea *mdiArea;
public:
    MenuBar(QMainWindow * window, QMdiArea * mdiArea);
    QMenu * getFileMenu();
    QMenu * getEditarMenu();
    QMenu * getFormatarMenu();
    QMenu * getExibirMenu();
    QMenu * getHelpMenu();
};

#endif
