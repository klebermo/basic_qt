#include "menu.hpp"

#include <iostream>

MenuBar::MenuBar(QMainWindow * window, QMdiArea * mdiArea) {
    this->mdiArea = mdiArea;
    fileMenu = new QMenu("Arquivo");

        QAction * newAction = new QAction("Novo");
        fileMenu->addAction(newAction);

        QObject::connect(newAction, &QAction::triggered, [&]() {
            QMdiSubWindow * subWindow1 = new QMdiSubWindow(nullptr);
            subWindow1->setWindowTitle("Novo documento");
            subWindow1->setWidget(new QTextEdit(subWindow1));
            this->mdiArea->addSubWindow(subWindow1);
            subWindow1->show();
        });

        QAction *newWindowAction = new QAction("Nova janela");
        fileMenu->addAction(newWindowAction);

        QObject::connect(newWindowAction, &QAction::triggered, [&]() {
            //
        });

        QAction *openAction = new QAction("Abrir");
        fileMenu->addAction(openAction);

        QObject::connect(openAction, &QAction::triggered, [&]() {
            QString file_name = QFileDialog::getOpenFileName(this, "Abrir documento", QDir::currentPath(), "Text files (*.txt);");
        });

        QAction *saveAction = new QAction("Salvar");
        fileMenu->addAction(saveAction);

        QObject::connect(saveAction, &QAction::triggered, [&]() {
            if(true) {
                QMessageBox::information(this,"Message", "Você salvou o arquivo", QMessageBox::Ok);
            } else {
                QString file_name = QFileDialog::getSaveFileName(this, "Salvar documento", QDir::currentPath(), "Text files (*.txt);");
            }
        });

        QAction *saveAsAction = new QAction("Salvar como");
        fileMenu->addAction(saveAsAction);

        QObject::connect(saveAsAction, &QAction::triggered, [&]() {
            QString file_name = QFileDialog::getSaveFileName(this, "Salvar documento", QDir::currentPath(), "Text files (*.txt);");
        });

        QAction *closeAction = new QAction("Fechar");
        fileMenu->addAction(closeAction);

        QObject::connect(closeAction, &QAction::triggered, [&]() {
            if(!this->mdiArea->subWindowList().isEmpty()) {
                QMdiSubWindow * subWindow = this->mdiArea->currentSubWindow();
                subWindow->close();
                this->mdiArea->removeSubWindow(subWindow);
            }
        });

        fileMenu->addSeparator();

        QAction *configPageAction = new QAction("Configurar página");
        fileMenu->addAction(configPageAction);

        QAction *printAction = new QAction("Imprimir");
        fileMenu->addAction(printAction);

        fileMenu->addSeparator();

        QAction *quitAction = new QAction("Sair");
        fileMenu->addAction(quitAction);

        QObject::connect(quitAction, &QAction::triggered, [&]() {
            exit(1);
        });

    editarMenu = new QMenu("Editar");

        QAction *undoAction = new QAction("Desfazer");
        editarMenu->addAction(undoAction);

        QAction *redoAction = new QAction("Refazer");
        editarMenu->addAction(redoAction);

        editarMenu->addSeparator();

        QAction *cutAction = new QAction("Recortar");
        editarMenu->addAction(cutAction);

        QAction *copyAction = new QAction("Copiar");
        editarMenu->addAction(copyAction);

        QAction *pasteAction = new QAction("Colar");
        editarMenu->addAction(pasteAction);

        QAction *deleteAction = new QAction("Excluir");
        editarMenu->addAction(deleteAction);

        editarMenu->addSeparator();

        QAction *findAction = new QAction("Localizar");
        editarMenu->addAction(findAction);

        QAction *replaceAction = new QAction("Substituir");
        editarMenu->addAction(replaceAction);

        editarMenu->addSeparator();

        QAction *selectAllAction = new QAction("Selecionar tudo");
        editarMenu->addAction(selectAllAction);
    
    formatarMenu = new QMenu("Formatar");

        QAction *lineBreakAction = new QAction("Quebrar automática de linha");
        formatarMenu->addAction(lineBreakAction);

        QAction *fontAction = new QAction("Fonte");
        formatarMenu->addAction(fontAction);

    exibirMenu = new QMenu("Exibir");

        QAction *zoomAction = new QAction("Zoom");
        exibirMenu->addAction(zoomAction);

        QAction *statusAction = new QAction("Barra de status");
        exibirMenu->addAction(statusAction);

    helpMenu = new QMenu("Ajuda");

        QAction *aboutAction = new QAction("Sobre");
        helpMenu->addAction(aboutAction);
        
        QObject::connect(aboutAction, &QAction::triggered, [&]() {
            QDialog dialog;

            dialog.setWindowTitle("About");
            dialog.setFixedSize(480, 640);

            QLabel *label = new QLabel("This is my application", this);
            label->setAlignment(Qt::AlignCenter);

            QVBoxLayout *layout = new QVBoxLayout(&dialog);
            layout->addWidget(label);

            QPushButton *okButton = new QPushButton("OK", &dialog);
            QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
            layout->addWidget(okButton);

            dialog.setLayout(layout);
            dialog.exec();
        });
}

QMenu * MenuBar::getFileMenu() {
    return fileMenu;
}

QMenu * MenuBar::getEditarMenu() {
    return editarMenu;
}

QMenu * MenuBar::getFormatarMenu() {
    return formatarMenu;
}

QMenu * MenuBar::getExibirMenu() {
    return exibirMenu;
}

QMenu * MenuBar::getHelpMenu() {
    return helpMenu;
}
