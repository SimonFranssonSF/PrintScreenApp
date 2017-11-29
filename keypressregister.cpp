#include "keypressregister.h"
#include "QDebug"
#include "QObject"
#include "QKeyEvent"

KeyPressRegister::KeyPressRegister() : QObject()
{

}

// if any key is pressed, then the selectionwindow/screenshot should be closed without uploading.
bool KeyPressRegister::eventFilter(QObject* obj, QEvent* event) {
  if (event->type()==QEvent::KeyPress) {
      emit keyPressed();
      // QKeyEvent* key = static_cast<QKeyEvent*>(event);

      /*if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
          //Enter or return was pressed
          qDebug() << "Enter";
      } else {
          qDebug() << "not enter";
          return QObject::eventFilter(obj, event);
      }*/
      return true;
  } else {
      return QObject::eventFilter(obj, event);
  }
  return false;
}
