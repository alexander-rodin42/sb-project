#include <QApplication>
#include <QRegularExpression>

#include <QVBoxLayout>

#include <QLineEdit>
#include <QLAbel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window(nullptr);
    QVBoxLayout vBox(&window);

    auto* lineEdit = new QLineEdit(&window);
    auto* label = new QLabel(&window);

    vBox.addWidget(lineEdit);
    vBox.addWidget(label);

    QWidget::connect(lineEdit, &QLineEdit::textEdited, [lineEdit, label](const QString& currentText) {
        QRegularExpression expression("^(\\+)[0-9]{11}$");

        if (expression.match(currentText).hasMatch()) {
            label->setText("Ok");
            label->setStyleSheet("QLabel {color : green}");
        }
        else {
            label->setText("Fail");
            label->setStyleSheet("QLabel {color : red}");
        }
    });


    window.show();
    return QApplication::exec();
}
