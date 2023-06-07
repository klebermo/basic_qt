#include <QApplication>
#include <QMainWindow>
#include <QMdiArea>

#include "menu.hpp"
#include "toolbar.hpp"
#include "statusbar.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("My Application");
    window.setWindowIcon(QIcon("icon.png"));
    window.resize(1280, 800);

    QMdiArea mdiArea(&window);
    mdiArea.setViewMode(QMdiArea::TabbedView);

    window.setCentralWidget(&mdiArea);

    MenuBar menuBar(&window, &mdiArea);
    window.menuBar()->addMenu(menuBar.getFileMenu());
    window.menuBar()->addMenu(menuBar.getEditarMenu());
    window.menuBar()->addMenu(menuBar.getFormatarMenu());
    window.menuBar()->addMenu(menuBar.getExibirMenu());
    window.menuBar()->addMenu(menuBar.getHelpMenu());

    ToolBar toolBar(&window, &mdiArea);
    window.addToolBar(&toolBar);

    StatusBar statusBar(&window);
    window.setStatusBar(&statusBar);

    window.show();

    return app.exec();
}
