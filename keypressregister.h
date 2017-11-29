#ifndef KEYPRESSREGISTER_H
#define KEYPRESSREGISTER_H

#include "QWidget"

class KeyPressRegister : public QObject {
    Q_OBJECT
public:
    KeyPressRegister();
protected:
    bool eventFilter(QObject* obj, QEvent* event);
signals:
    void keyPressed();
};

#endif // KEYPRESSREGISTER_H
