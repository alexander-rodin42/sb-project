#include <iostream>

#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>

class ColoredCircle : public QWidget
{
    Q_OBJECT
public:
    ColoredCircle() = default;
    ColoredCircle(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
public slots:
    void setGreen();
    void setYellow();
    void setRed();
private:
    QPixmap mCurrentCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
};

ColoredCircle::ColoredCircle(QWidget *parent)
{
    setParent(parent);
    setToolTip("Circle");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mGreenCircle = QPixmap("greenCircle.png");
    mYellowCircle = QPixmap("yellowCircle.png");
    mRedCircle = QPixmap("redCircle.png");
    mCurrentCircle = mGreenCircle;
    setGeometry(mCurrentCircle.rect());
}

void ColoredCircle::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawTiledPixmap(event->rect(), mCurrentCircle);
}

QSize ColoredCircle::sizeHint() const
{
    return QSize(150, 150);
}

QSize ColoredCircle::minimumSizeHint() const
{
    return sizeHint();
}

void ColoredCircle::setGreen()
{
    mCurrentCircle = mGreenCircle;
    update();
}

void ColoredCircle::setYellow()
{
    mCurrentCircle = mYellowCircle;
    update();
}

void ColoredCircle::setRed()
{
    mCurrentCircle = mRedCircle;
    update();
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *circle = new ColoredCircle(window);
    auto *slider = new QSlider(Qt::Horizontal);

    slider->setMaximum(0);
    slider->setMaximum(100);

    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, [slider, circle](int newValue)
    {
        if (newValue >= 0 && newValue <= 33)
        {
            circle->setGreen();
        }
        else if (newValue > 33 && newValue <= 66)
        {
            circle->setYellow();
        }
        else
        {
            circle->setRed();
        }
    });

    window->resize(170, 200);
    window->show();

    return app.exec();
}

#include "main.moc"