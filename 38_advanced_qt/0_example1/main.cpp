#include <QtGui/QtGui>
#include <QApplication>

//#include <QtWebEngineWidgets>
#include <QtWebEngineWidgets/qwebengineview.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto* webView = new QWebEngineView;
    webView->setHtml("<H1>Hello world!</H1>");
    webView->show();
    return QApplication::exec();
}

