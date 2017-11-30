#ifndef QPAINTLABEL_H
#define QPAINTLABEL_H

#include "QWidget"
#include "QLabel"
#include "QRubberBand"
#include "QPaintEvent"
#include "QPainter"

class QPaintLabel : public QLabel {
    Q_OBJECT
public:
    QPaintLabel(QWidget* p = 0);
    QRubberBand* rubberBand;
    QPoint origin;
private:
    QPainter* p;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent* event);
signals:
    void notifyMouse(QPoint origin, QPoint lastPos);
};

#endif // QPAINTLABEL_H
