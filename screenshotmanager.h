#ifndef SCREENSHOTMANAGER_H
#define SCREENSHOTMANAGER_H

#include "QWidget"
#include "QObject"
#include <windows.h>
#include "QPixmap"


class ScreenshotManager : public QObject {
    Q_OBJECT
public:
    ScreenshotManager(){};
    ScreenshotManager(QWidget* p): QObject(p){};
    ScreenshotManager(const ScreenshotManager &s);
    ScreenshotManager& operator=(const ScreenshotManager& s);
    QPixmap takeScreenshot();
    void saveScreenshot();
    void uploadScreenshot(QPixmap pixmap);
signals:
    void finished();
};

#endif // SCREENSHOTMANAGER_H
