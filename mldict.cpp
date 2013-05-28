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

#include "mldict.h"
#include "ui_mldict.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>



QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
QString helpText;

MlDict::MlDict(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MlDict)
{
    db.setDatabaseName("mlDict.sqlite");
    db.open();
    // qDebug() << "DB opened";
    ui->setupUi(this);
    helpText = ui->resultBox->toPlainText();
    // qDebug() << helpText;
}

MlDict::~MlDict()
{
    delete ui;
}

void MlDict::on_action_Quit_triggered()
{
    exit (0);
}

void MlDict::on_search_clicked()
{
    int i;
    // // qDebug("Button clicked");
    QString keyword = ui->searchTerm->text();
    if (keyword.isEmpty())
    {
        ui->resultBox->setPlainText(tr("Please enter a serach string"));
        ui->statusBar->showMessage(tr("Please enter a serach string"));
        return;
    }

    ui->resultBox->setPlainText(" ");
    ui->statusBar->showMessage(tr("Searching..."));
    QCoreApplication::processEvents();


    QSqlQuery qry;
    QString jj;
    if (ui->exactMatch->checkState())
    {
        jj = "select w.word, w.letter, w.root, w.literal, d.definition, r.rtype from word w, definition d, relation r where w.id = r.id_word and r.id_definition = d.id and w.word = '";
        jj.append(keyword);
        jj.append("'");
    }
    else
    {
        jj = "select w.word, w.letter, w.root, w.literal, d.definition, r.rtype from word w, definition d, relation r where w.id = r.id_word and r.id_definition = d.id and w.word like '";
        jj.append(keyword);
        jj.append("%'");
    }

    qry.prepare(jj);
    // qDebug () << jj;
    qry.exec();
    // qDebug("Executed");
    // // qDebug() << qry.size();

    QString resString = "";
    QString tmpRes;
    // // qDebug("before while");
    i = 0;
    while (qry.next())
    {
        i++;
        resString = "";
        // QString k = QString::fromUtf8("നാമം : ", -1);
        QString k;
        // qDebug () << qry.value(0).toString();
        resString.append(k);
        resString.append(qry.value(0).toString());
        resString.append("\n");


        tmpRes = qry.value(2).toString();
        if (! tmpRes.isEmpty())
        {
            k = QString::fromUtf8("    ഉൽപ്പത്തി : ", -1);
            resString.append(k);
            resString.append(tmpRes);
            resString.append("\n");
        }

        tmpRes = qry.value(3).toString();
        if (! tmpRes.isEmpty())
        {
            k = QString::fromUtf8("    പദാനുപദം : ", -1);
            resString.append(k);
            resString.append(tmpRes);
            resString.append("\n");
        }

        tmpRes = qry.value(4).toString();
        if (! tmpRes.isEmpty())
        {
            k = QString::fromUtf8("    വ്യാഖ്യാനം : ", -1);
            resString.append(k);
            resString.append("(");
            resString.append(qry.value(5).toString());
            resString.append(") ");
            resString.append(tmpRes);
            resString.append("\n");
        }

        resString.append("\n");


        ui->resultBox->append(resString);
        QCoreApplication::processEvents();
    }
    // qDebug () << "Found " << i << "rows";
    QString tmp;
    if (i == 0)
    {
        tmp = QString (tr ("No results Found for %1")) .arg(keyword);
        ui->resultBox->setPlainText(tr("No data found"));
        ui->statusBar->showMessage(tmp);
    }
    else
    {   tmp = QString (tr ("%1 Results Found for %2")) .arg(i) .arg(keyword);
        ui->statusBar->showMessage(tmp);
    }
}

void MlDict::on_searchTerm_returnPressed()
{
    MlDict::on_search_clicked();
}

void MlDict::on_action_About_triggered()
{
    ui->resultBox->setText(helpText);
}
