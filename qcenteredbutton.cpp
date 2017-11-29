#include "qcenteredbutton.h"
#include <QtWidgets>
#include "QGroupBox"
#include "QVBoxLayout"
#include "QSpacerItem"
#include "QPushButton"

QCenteredButton::QCenteredButton(QWidget *parent) : QGroupBox(parent) {
    QHBoxLayout* theLayout = new QHBoxLayout;
    QSpacerItem* topSpacer = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button = new QPushButton("Hej");
    button->setFlat(false);
    button->setFixedSize(200,200);
    QSpacerItem* bottomSpacer = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Expanding);

    theLayout->addItem(topSpacer);
    theLayout->addWidget(button);
    theLayout->addItem(bottomSpacer);

    QGroupBox* mainGroupBox = new QGroupBox();
    mainGroupBox->setLayout(theLayout);

    QVBoxLayout* hLayout = new QVBoxLayout;
    QSpacerItem* leftpacer = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem* rightSpacer = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Expanding);

    hLayout->addItem(leftpacer);
    hLayout->addWidget(mainGroupBox);
    hLayout->addItem(rightSpacer);

    this->setLayout(hLayout);
}

QPushButton* QCenteredButton::getButton() {
    return this->button;
}

