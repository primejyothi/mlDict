#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QDebug>
#include "mldict.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator mlDictTranslator;
    QString filename = QString("mldict_%1").arg(QLocale::system().name());
    filename = filename.toLower();
    qDebug () << filename;
    mlDictTranslator.load(filename);
    a.installTranslator(&mlDictTranslator);

    MlDict w;
    w.show();
    
    return a.exec();
}
