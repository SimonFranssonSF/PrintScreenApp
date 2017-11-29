#include "screenshotmanager.h"
#include <windows.h>
#include <iostream>
#include <string>
#include "QScreen"
#include "QGuiApplication"
#include <QtWidgets>
#include "curl.h"
#include "QDebug"
//#include "cpprest/http_client.h"
//#include "cpprest/filestream.h"
//#include "cpprest/json.h"
#include "qnetwork.h"
#include "QtNetwork/QNetworkReply"
#include "QtNetwork/QNetworkAccessManager"


QPixmap ScreenshotManager::takeScreenshot() {
    QScreen *screen = QGuiApplication::primaryScreen();
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
