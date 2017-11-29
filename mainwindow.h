#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screenshotmanager.h"
#include "QLabel"
#include "keypressthread.h"
#include "QPushButton"
#include "qpaintlabel.h"
#include "QNetworkReply"
#include  "QSystemTrayIcon"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    ScreenshotManager* scm;
    QPaintLabel* img;
    QPushButton* button;
    QPixmap a;
    void copyToClipBoard(QString url);
    QSystemTrayIcon* trayIcon;
    void trayIconAndActions();
private:
    Ui::MainWindow *ui;
    QPixmap sc;
    QString extractUrl(QByteArray content);
protected:
    KeyPressThread* thread;
private slots:
    void screenshotTaken();
    void mouseSelect(QPoint x, QPoint y);
    void sendRequest();
    void replyFinished(QNetworkReply*);
    void keyPressedHandle();
    void close();
signals:
    void notifyClose();
};

#endif // MAINWINDOW_H
