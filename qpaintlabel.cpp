#include "qpaintlabel.h"
#include "QPainter"
#include "QRect"
#include "QPaintEvent"
#include "QDebug"
#include "specialrubberband.h"

QPaintLabel::QPaintLabel() : QLabel() {
    rubberBand = new SpecialRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setStyleSheet("selection-background-color: rgba(255, 255, 255, 128);border-color: red;");
    this->setWindowFlags(this->windowFlags() | Qt::Window);
}

void QPaintLabel::mousePressEvent(QMouseEvent *event) {
    origin = event->pos();
    QPoint currentPos = event->pos();

    rubberBand->setGeometry(QRect(origin, event->pos()));
    rubberBand->show();
}

void QPaintLabel::mouseMoveEvent(QMouseEvent *event) {
    rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
}

void QPaintLabel::mouseReleaseEvent(QMouseEvent *event) {
    emit notifyMouse(origin, event->pos());
    rubberBand->hide();
}

