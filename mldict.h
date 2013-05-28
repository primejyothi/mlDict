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
