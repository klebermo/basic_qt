#ifndef statusbar_hpp
#define statusbar_hpp

#include <QStatusBar>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>

class StatusBar : public QStatusBar {
public:
    StatusBar(QMainWindow * window);
};

#endif
