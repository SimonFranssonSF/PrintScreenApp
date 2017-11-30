#include "screenshotmanager.h"
#include <windows.h>
#include <iostream>
#include <string>
#include "QScreen"
#include "QGuiApplication"
#include <QtWidgets>
#include "QDebug"
//#include "cpprest/http_client.h"
//#include "cpprest/filestream.h"
//#include "cpprest/json.h"
#include "qnetwork.h"
#include "QtNetwork/QNetworkReply"
#include "QtNetwork/QNetworkAccessManager"
#include "QDesktopWidget"
#include "QWindow"

QPixmap ScreenshotManager::takeScreenshot() {
    // which screen are we working with
    QPoint globalCursorPos = QCursor::pos();
    int activeScreen = qApp->desktop()->screenNumber(globalCursorPos);
    qDebug() << activeScreen;

    //QScreen *screen = QGuiApplication::primaryScreen();
    QScreen* screen = QGuiApplication::screens().at(activeScreen);
    QPixmap originalPixmap = screen->grabWindow(0);
    return originalPixmap;
}

void ScreenshotManager::saveScreenshot() {

}


void ScreenshotManager::uploadScreenshot(QPixmap pixmap) {
    emit finished();
}

ScreenshotManager& ScreenshotManager::operator=(const ScreenshotManager& s) {
  return *this;
}
