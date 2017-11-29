#ifndef QCENTEREDBUTTON_H
#define QCENTEREDBUTTON_H

#include "QGroupBox"
#include <QWidget>
#include "QPushButton"

class QCenteredButton : public QGroupBox {
    Q_OBJECT
public:
    QCenteredButton(QWidget* parent = 0);
    QPushButton* getButton();
private:
    QPushButton* button;
};

#endif // QCENTEREDBUTTON_H
