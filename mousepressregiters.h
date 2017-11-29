#ifndef MOUSEPRESSREGITERS_H
#define MOUSEPRESSREGITERS_H

#include "QWidget"
#include "QEvent"
#include "QObject"

class MousePressRegiters : public QObject {
    Q_OBJECT
public:
    MousePressRegiters(){};
    virtual ~MousePressRegiters() {};
protected:
    bool eventFilter(QObject* obj, QEvent* event);
signals:
    void notifyMouse(int x, int y);
};

#endif // MOUSEPRESSREGITERS_H
