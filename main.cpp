/*
mlDict, Qt Based UI for Malayalam-Malayalam dictionary, based on data from olam.in
Copyright (C) 2013  Prime Jyothi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
