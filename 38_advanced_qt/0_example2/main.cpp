#include <iostream>

#include <QtGui/QtGui>
#include <QApplication>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>

#include <QDir>

QImage blurImage(QImage source) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRect( 0, 0, source.width(), source.height()));
    return result;
}

void processSingleImage(QString sourceFile, QString destFile) {
    auto blurred = blurImage(QImage(sourceFile));
    blurred.save(destFile);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
// 1 ->
//    processSingleImage(R"(C:\Users\Alexander\Desktop\sb-project\38_advanced_qt\0_example2\image.jpg)",
//                       R"(C:\Users\Alexander\Desktop\sb-project\38_advanced_qt\0_example2\blurred_image.jpg)");

// 2 ->
    QDir sourceDir(R"(C:\Users\Alexander\Desktop\sb-project\38_advanced_qt\0_example2\non_blurred)");
    QDir destinationDir(R"(C:\Users\Alexander\Desktop\sb-project\38_advanced_qt\0_example2\blurred)");
    auto images = sourceDir.entryList(QStringList() << "*.jpg" << "*.JPG", QDir::Files);

    QElapsedTimer timer;
    timer.start();
    QList<QFuture<void>> handlers; // <- 3

    for (auto & fileName : images) {
//        processSingleImage(sourceDir.path() + "\\" + fileName,
//                           destinationDir.path() + "\\blurred_" + fileName);
// 3 ->
        handlers.append( QtConcurrent::run(processSingleImage,
                                           sourceDir.path() + "\\" + fileName,
                                           destinationDir.path() + "\\blurred_" + fileName));

    }
    for (auto & finish : handlers) {
        finish.waitForFinished();
    }

    std::cout << "Clack time: " << timer.elapsed() << " mseconds." << std::endl;
    return app.exec();
}
