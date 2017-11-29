#include "mousepressregiters.h"
#include "QMouseEvent"
#include "QDebug"
#include "QObject"
#include "QPainter"
#include "QLabel"


bool MousePressRegiters::eventFilter(QObject* obj, QEvent* event) {
  if (event->type()==QEvent::MouseMove) {
      QMouseEvent* key = static_cast<QMouseEvent*>(event);
      QPoint p =  key->pos();
      emit notifyMouse(p.x(), p.y());

      return true;
  } else {
      return QObject::eventFilter(obj, event);
  }
  return false;
}
