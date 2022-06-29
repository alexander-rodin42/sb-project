#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One", window);
    QPushButton *button2 = new QPushButton("Two", window);
    QPushButton *button3 = new QPushButton("Three", window);
    QPushButton *button4 = new QPushButton("Four", window);
    QPushButton *button5 = new QPushButton("Five", window);

//    auto* layout = new QVBoxLayout(window);
//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    layout->addWidget(button3);
//    layout->addWidget(button4);
//    layout->addWidget(button5);

    auto* layout = new QGridLayout(window);
    layout->addWidget(button1, 0 , 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0, 1, 2);
    layout->addWidget(button4, 2, 0);
    layout->addWidget(button5, 2, 1);

//    button1->move(10, 10);
//    button2->move(10, 40);
//    button3->move(10, 70);
//    button4->move(10, 100);
//    button5->move(10, 130);

    //
    window->resize(150, 150);
    window->move(700, 500);
    window->show();

    return app.exec();
}
