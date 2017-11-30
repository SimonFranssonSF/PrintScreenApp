#include "qpaintlabel.h"
#include "QPainter"
#include "QRect"
#include "QPaintEvent"
#include "QDebug"
#include "specialrubberband.h"
#include "QPaintEvent"
#include "QApplication"
#include "QDesktopWidget"
#include "QScreen"

QPaintLabel::QPaintLabel(QWidget* p) : QLabel(p) {
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

void QPaintLabel::paintEvent(QPaintEvent *event) {
    QLabel::paintEvent(event);
    QPainter p(this);
    p.setBrush(QBrush(QColor(0,0,0,60)));
    p.setPen(QPen(QColor(0,0,0,60)));

    // which screen are we working with
    QPoint globalCursorPos = QCursor::pos();
    int activeScreen = qApp->desktop()->screenNumber(globalCursorPos);
    QScreen* screen = QGuiApplication::screens().at(activeScreen);
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    p.drawRect(0,0,width, height);

}
