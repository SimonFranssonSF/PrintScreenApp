#include "specialrubberband.h"
#include "QRubberBand"
#include "QPaintEvent"
#include "qpainter.h"
#include "QRgb"


SpecialRubberBand::SpecialRubberBand(Shape s, QWidget* p) : QRubberBand(s,p) {

}

void SpecialRubberBand::paintEvent(QPaintEvent* pe) {
    QColor backgroundColor = QColor(100,100,100);
    backgroundColor.setAlpha(60);
    QPainter customPainter(this);
    customPainter.setPen(QColor(255,0,0));
    customPainter.fillRect(rect(),backgroundColor);
    customPainter.drawRect(rect().adjusted(0, 0, -1, -1));
}
