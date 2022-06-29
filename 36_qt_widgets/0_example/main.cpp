#include <iostream>
#include <QApplication>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    auto *slider = new QSlider(Qt::Horizontal);
    auto *spinbox = new QSpinBox();
    slider->setMaximum(0);
    slider->setMaximum(100);
    spinbox->setMinimum(0);
    spinbox->setMaximum(100);
    //
    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);

    slider->resize(250, 50);
    slider->move(1000, 500);
    spinbox->resize(250, 50);
    spinbox->move(700, 500);

    slider->show();
    spinbox->show();

    app.exec();
}
