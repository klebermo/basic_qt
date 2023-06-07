#include "statusbar.hpp"

StatusBar::StatusBar(QMainWindow * window) : QStatusBar(window) {
    QLabel * label1 = new QLabel("Pronto");
    label1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label1->setLineWidth(3);
    addPermanentWidget(label1);

    QLabel * label2 = new QLabel("");
    label2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label2->setLineWidth(3);
    label2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    addPermanentWidget(label2);

    QLabel * label3 = new QLabel("Caracteres: 0");
    label3->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label3->setLineWidth(3);
    addPermanentWidget(label3);

    setSizeGripEnabled(false);
}
