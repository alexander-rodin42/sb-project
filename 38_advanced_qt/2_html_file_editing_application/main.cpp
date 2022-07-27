#include <QApplication>

#include <QPlainTextEdit>
#include <QWebEngineView>

#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window(nullptr);
    QHBoxLayout hBox(&window);

    //Plain text edit
    auto* plainTextEdit = new QPlainTextEdit(&window);
    hBox.addWidget(plainTextEdit);

    QSizePolicy sizePolicyTextEdit(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicyTextEdit.setHorizontalStretch(1);
    sizePolicyTextEdit.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
    plainTextEdit->setSizePolicy(sizePolicyTextEdit);

    //Web view
    auto* webView = new QWebEngineView(&window);
    hBox.addWidget(webView);

    QSizePolicy sizePolicyWebView(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicyWebView.setHorizontalStretch(1);
    sizePolicyWebView.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
    webView->setSizePolicy(sizePolicyWebView);

    QObject::connect(plainTextEdit, &QPlainTextEdit::textChanged, [plainTextEdit, webView](){
        webView->setHtml(plainTextEdit->toPlainText());
    });

    window.setWindowTitle("HTML editor");
    window.setMinimumSize(800, 640);
    window.show();
    return QApplication::exec();
}
