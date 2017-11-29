#ifndef KEYPRESSTHREAD_H
#define KEYPRESSTHREAD_H

#include "QThread"
#include "QWidget"
#include "QLabel"
#include "screenshotmanager.h"

class KeyPressThread : public QThread {
    Q_OBJECT
public:
    KeyPressThread();
protected:
    void run();
signals:
    void notify();
};

#endif // KEYPRESSTHREAD_H
