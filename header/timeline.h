#ifndef TIMELINE_H
#define TIMELINE_H

#include <QDialog>
#include "QListWidgetItem"

namespace Ui {
class timeline;
}

class timeline : public QDialog
{
    Q_OBJECT

public:
    explicit timeline(QWidget *parent = nullptr);
    ~timeline();

private slots:
    void on_back_clicked();

private:
    Ui::timeline *ui;
    void onItemPressed(QListWidgetItem *item);
};

#endif // TIMELINE_H
