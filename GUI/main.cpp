#include "widget.h"
#include "loginform.h"
#include <QApplication>
#include "vlchelper.h"
#include <QDebug>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");  // 解决中文乱码问题
    Widget w;
    LoginForm login;
    w.hide();
    login.show();
    login.connect(&login, SIGNAL(login(const QString&, const QByteArray&)),
                  &w, SLOT(on_show(const QString&, const QByteArray&)));// 当登录窗口发出登录信号的时候，主窗口会显示出来
    qDebug() << __FILE__ << "(" << __LINE__ << "):";
    int ret = a.exec();
    qDebug() << __FILE__ << "(" << __LINE__ << "):";
    return ret;
}
