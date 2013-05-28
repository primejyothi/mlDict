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

#ifndef MLDICT_H
#define MLDICT_H

#include <QMainWindow>

namespace Ui {
class MlDict;
}

class MlDict : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MlDict(QWidget *parent = 0);
    ~MlDict();
    
private slots:
    void on_action_Quit_triggered();

    void on_search_clicked();

    void on_searchTerm_returnPressed();
    void on_action_About_triggered();

private:
    Ui::MlDict *ui;
};

#endif // MLDICT_H
