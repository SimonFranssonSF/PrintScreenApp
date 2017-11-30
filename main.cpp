#include "winsock2.h"
#include "mainwindow.h"
#include <QApplication>

class WidgetToHideTaskBarIcon : public QWidget
{
public:
    WidgetToHideTaskBarIcon(QWidget *parent)
        : QWidget(parent, Qt::Dialog)
    {

    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    WidgetToHideTaskBarIcon widget(&w);
    w.hide();

    return a.exec();
}
