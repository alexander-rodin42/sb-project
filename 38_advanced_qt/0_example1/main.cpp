#include <QtGui/QtGui>
#include <QApplication>

#include <QtWebEngineWidgets>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>

class BrowserTabWidget : public QWidget {
    Q_OBJECT

signals:
    void tabLoadFinished(QString tabTitle);

};

BrowserTabWidget* createNewBrowserWindow() {
    auto* browserWindow = new BrowserTabWidget;
    auto* urlLineEdit = new QLineEdit;
    auto* webView = new QWebEngineView;
    auto* vbox = new QVBoxLayout(browserWindow);

    vbox->addWidget(urlLineEdit);
    vbox->addWidget(webView);

    QObject::connect(urlLineEdit, &QLineEdit::returnPressed, [urlLineEdit, webView](){
        auto urlToOpen = urlLineEdit->text();
        webView->load(urlToOpen);
    });

    QObject::connect(webView, &QWebEngineView::loadFinished, [webView, browserWindow](bool ok){
        if (ok) {
            emit browserWindow->tabLoadFinished(webView->title());
        }
    });

    return browserWindow;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QTabWidget tabs;
    QPushButton newTabButton("+");

    tabs.setTabsClosable(true);
    tabs.setCornerWidget(&newTabButton, Qt::BottomLeftCorner);

    //add tab
    QObject::connect(&newTabButton, &QPushButton::clicked, [&tabs](){
        auto newTab = createNewBrowserWindow();

        QObject::connect(newTab, &BrowserTabWidget::tabLoadFinished, [&tabs](QString newTitle){
            tabs.setTabText(tabs.currentIndex(), newTitle);
            tabs.setWindowTitle(newTitle);
        });

        tabs.addTab(newTab, "tab " + QString::number(tabs.count() + 1));
    });

    //setWindowTitle
    QObject::connect(&tabs, &QTabWidget::currentChanged, [&tabs](int currentIndex){
        tabs.setWindowTitle(tabs.tabText(currentIndex));
    });

    newTabButton.click();

    //delete tab
    QObject::connect(&tabs, &QTabWidget::tabCloseRequested, [&tabs](int indexToRemove){
        if (tabs.count() > 1) {
            auto widgetToDelete = tabs.widget(indexToRemove);
            delete widgetToDelete;
        }
    });

    tabs.show();
    return QApplication::exec();
}

#include "main.moc"

/*
    //webView->setHtml("<H1>Hello world!</H1>");
    //webView->setUrl(QUrl("https://skillbox.ru"));
    //webView->show();
 */