#ifndef QPAINTLABEL_H
#define QPAINTLABEL_H

#include "QWidget"
#include "QLabel"
#include "QRubberBand"

class QPaintLabel : public QLabel {
    Q_OBJECT
public:
    QPaintLabel();
    QRubberBand* rubberBand;
    QPoint origin;
private:
    QPainter* p;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //void paintEvent(QPaintEvent* event);
signals:
    void notifyMouse(QPoint origin, QPoint lastPos);
};

#endif // QPAINTLABEL_H
