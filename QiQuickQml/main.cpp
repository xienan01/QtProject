#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml>
#include "colorMaker.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    //在qml中使用c++的两种方法
    //1、让qml能够访问c++的类对象
    //qmlRegisterType<ColorMaker>("an.qt.ColorMaker", 1, 0, "ColorMaker");

    //2、将c++对象注册为一个属性， 使用setContextProperty qml中不需要导入包
//    QQuickView viewer;
//    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));
//    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
//    viewer.rootContext()->setContextProperty("colorMaker", new ColorMaker());
//    viewer.setSource(QUrl("qrc:/main.qml"));
//    viewer.show();
    //3、使用QQmlApplicationEngine+windows结构
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("ColorMaker", new ColorMaker());
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
