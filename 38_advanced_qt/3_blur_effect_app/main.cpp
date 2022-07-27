#include <QApplication>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>

#include <QFileDialog>

#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QPainter>

QImage blurImage(QImage source, const int& blurRadius) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRect( 0, 0, source.width(), source.height()));
    return result;
}



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window(nullptr);
    QVBoxLayout vBox(&window);

    auto* label = new QLabel(&window);
    auto* slider = new QSlider(&window);
    auto* openFileButton = new QPushButton( "Open", &window);

    vBox.addWidget(label);
    vBox.addWidget(slider);
    vBox.addWidget(openFileButton);
    //
    label->setMinimumSize(800, 640);
    QSizePolicy sizePolicyLabel(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicyLabel.setHorizontalStretch(1);
    sizePolicyLabel.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setSizePolicy(sizePolicyLabel);
    //
    slider->setMinimum(0);
    slider->setMaximum(10);
    slider->setOrientation(Qt::Horizontal);
    QSizePolicy sizePolicySlider(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicySlider.setHorizontalStretch(1);
    sizePolicySlider.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
    slider->setSizePolicy(sizePolicySlider);
    //
    QSizePolicy sizePolicyOpenFileButton(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicyOpenFileButton.setHorizontalStretch(1);
    sizePolicyOpenFileButton.setHeightForWidth(openFileButton->sizePolicy().hasHeightForWidth());
    openFileButton->setSizePolicy(sizePolicyOpenFileButton);
    //
    QString filePath;
    QImage sourceImage;

    QObject::connect(openFileButton, &QPushButton::clicked, [&filePath, &sourceImage, label](){
        filePath = QFileDialog::getOpenFileName(nullptr,
                                                "Open file",
                                                "C:\\Users\\",
                                                "image files (* bmp, * jpg, * jpeg, * png)");

        sourceImage = QImage(filePath);

        label->setPixmap(QPixmap::fromImage(sourceImage).scaled(
                                    label->width(),
                                    label->height(), Qt::KeepAspectRatio));
    });
    //
    QObject::connect(slider, &QSlider::valueChanged, [&sourceImage, slider, label](int newValue){
        label->setPixmap(QPixmap::fromImage(blurImage(sourceImage, newValue)).scaled(
                                    label->width(),
                                    label->height(), Qt::KeepAspectRatio));
    });

    window.show();
    return QApplication::exec();
}
