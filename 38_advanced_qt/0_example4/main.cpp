#include <iostream>

#include <QApplication>
#include <QPushButton>

#include <QObject>

class MyClass : public QObject {
    Q_OBJECT

public:
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    void setAge(int nAge) { mAge = nAge; }
    int  age() { return mAge; }

signals:
    void ageChanged(int);

private:
    int mAge;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyClass hero;
    hero.setProperty("Height", 180);

    std::cout << "Height: " << hero.property("Height").toUInt() << std::endl;

    return QApplication::exec();
}

#include <main.moc>