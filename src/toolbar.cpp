#include "toolbar.hpp"

ToolBar::ToolBar(QMainWindow * window, QMdiArea * mdiArea) {
    this->mdiArea = mdiArea;

    newAction = new QAction(QIcon("new.png"), "New");
    this->addAction(newAction);

    QObject::connect(newAction, &QAction::triggered, [&]() {
            QMdiSubWindow *subWindow1 = new QMdiSubWindow(nullptr);
            subWindow1->setWindowTitle("Novo documento");
            subWindow1->setWidget(new QTextEdit(subWindow1));
            this->mdiArea->addSubWindow(subWindow1);
            subWindow1->show();
    });

    openAction = new QAction(QIcon("open.png"), "Open");
    this->addAction(openAction);

    QObject::connect(openAction, &QAction::triggered, [&]() {
        QString file_name = QFileDialog::getOpenFileName(this, "Abrir documento", QDir::currentPath(), "Text files (*.txt);");
    });

    saveAction = new QAction(QIcon("save.png"), "Save");
    this->addAction(saveAction);

    QObject::connect(saveAction, &QAction::triggered, [&]() {
        if(true) {
            QMessageBox::information(this,"Message", "Você salvou o arquivo", QMessageBox::Ok);
        } else {
            QString file_name = QFileDialog::getSaveFileName(this, "Salvar documento", QDir::currentPath(), "Text files (*.txt);");
        }
    });
}
