#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "qcenteredbutton.h"
#include "QObject"
#include "screenshotmanager.h"
#include "QLabel"
#include "keypressregister.h"
#include "QDebug"
#include "keypressthread.h"
#include "mousepressregiters.h"
#include "QPainter"
#include "qpaintlabel.h"
#include "QtNetwork/QNetworkReply"
#include "QtNetwork/QNetworkAccessManager"
#include "QUrlQuery"
#include "QBuffer"
#include "QJsonObject"
#include "QJsonDocument"
#include "QJsonArray"
#include "QClipboard"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setCentralWidget(buttonWidget);

    // Minimize the mainwindow so its not in the way
    this->showMinimized();
    this->hide();


    //show the System tray Icon trayIcon and fix its actions
    trayIconAndActions();

    // Setting up the screenshotManager
    scm = new ScreenshotManager();
    connect(scm, SIGNAL(finished()),
            this, SLOT(sendRequest()));

    // Modified label to include mouseEvents when selecting the area of the image that you want to upload.
    img = new QPaintLabel();
    connect(img, SIGNAL(notifyMouse(QPoint, QPoint)), this, SLOT(mouseSelect(QPoint, QPoint)));

    // Overloading QObjext eventfilter to listen for global keypress Snapshot,
    // this closes the app when screenshot is taken and selection is taken to be made
    KeyPressRegister* key = new KeyPressRegister();
    connect(key, SIGNAL(keyPressed()), this, SLOT(keyPressedHandle()));
    img->installEventFilter(key);

    // Thread listening for global keypresses even  when program is tabbed out
    thread = new KeyPressThread();
    connect(thread, SIGNAL(notify()), this, SLOT(screenshotTaken()));
    thread->start();
}

// When the mouseEvent in the QPaintLabel is clicked, that is, screenshot is selected, then crop the screenshot sc,
// call the uploadScreenshot function to upload it.
void MainWindow::mouseSelect(QPoint x, QPoint y) {
    a = sc.copy(QRect(x, y));
    img->setPixmap(a);
    scm->uploadScreenshot(sc);
    img->hide();
}

// Screenshot taken, that is, the hotkey alt + x has been pressed, grabs the screenshot and shows it in a fullscreen qpaintLabel.
void MainWindow::screenshotTaken() {
    sc = scm->takeScreenshot();
    QImage a = sc.toImage();
    QImage a2  = a.scaled(a.width(),a.height(), Qt::KeepAspectRatio);
    QPixmap a3 = QPixmap::fromImage(a2);
    img->setPixmap(a3);
    img->show();
    img->adjustSize();
    img->showFullScreen();
}

// Sends a request to api.imgur, the request is connected to signal/slot, so when it's finished the function replyFinished is called.
void MainWindow::sendRequest() {
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    a.save(&buffer, "PNG");
    QString imgBase64 = QString(byteArray.toBase64());

    QUrlQuery postData;
    postData.addQueryItem("Image", imgBase64);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    QNetworkRequest request(QUrl("https://api.imgur.com/3/image"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
        "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization",
        "ADD YOURSELF");
    manager->post(request, byteArray);
}

// extracts the content from the response calls extracts url, save's it in a string, then copys it to clipboard
void MainWindow::replyFinished(QNetworkReply* r) {
       QString contentType = r->header(QNetworkRequest::ContentTypeHeader).toString();
       QUrl redirectionTargetUrl = r->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
       QString url = extractUrl(r->readAll());
       qDebug() << url;
       copyToClipBoard(url);
}

// copys url to clipboard
void MainWindow::copyToClipBoard(QString url){
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(url);
}

// Extracts the Json response from imgur, returns a string containing the url to the uploaded image.
QString MainWindow::extractUrl(QByteArray content) {
    QString url;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(content);
    QJsonObject jsonObj = jsonDoc.object();
    QJsonValue val = jsonObj["data"];
    QJsonObject obj2 = val.toObject();
    QJsonValue valNested = obj2["link"];
    url = valNested.toString();
    return url;
}

void MainWindow::keyPressedHandle() {
    img->hide();
}

void MainWindow::trayIconAndActions() {
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/images/trayIcon.png"));
    trayIcon->setToolTip("ScreenshotApp: press alt + 4 take a screenshot");

    QMenu* menu = new QMenu(this);
    QAction* closeApp = new QAction("Close ScreenshotApp", this);
    connect(closeApp, SIGNAL(triggered()), this, SLOT(close()));
    menu->addAction(closeApp);
    trayIcon->setContextMenu(menu);
    trayIcon->show();
}

void MainWindow::close() {
    QApplication::quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
