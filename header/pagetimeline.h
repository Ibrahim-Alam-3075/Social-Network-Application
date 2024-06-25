#ifndef PAGETIMELINE_H
#define PAGETIMELINE_H

#include <QDialog>
#include "project.h"
#include <string>
#include "QListWidgetItem"

namespace Ui {
class pagetimeline;
}

class pagetimeline : public QDialog
{
    Q_OBJECT

public:
    explicit pagetimeline(QWidget *parent = nullptr, string name = "" , int n = 0 ,Post** pos = nullptr );
    ~pagetimeline();

private slots:
    void on_back_clicked();

private:
    Ui::pagetimeline *ui;
    void onItemPressed(QListWidgetItem *item);
    Post** p;
    int n;
    string name;
};

#endif // PAGETIMELINE_H
