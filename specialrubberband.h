#ifndef SPECIALRUBBERBAND_H
#define SPECIALRUBBERBAND_H

#include "QRubberBand"
#include "QWidget"

class SpecialRubberBand : public QRubberBand {
    Q_OBJECT
public:
    SpecialRubberBand(Shape s, QWidget* p);
protected:
    virtual void paintEvent(QPaintEvent *pe);
};

#endif // SPECIALRUBBERBAND_H
