#ifndef LIKEDPAGES_H
#define LIKEDPAGES_H

#include <QDialog>
#include "QListWidgetItem"

namespace Ui {
class likedpages;
}

class likedpages : public QDialog
{
    Q_OBJECT

public:
    explicit likedpages(QWidget *parent = nullptr);
    ~likedpages();

private slots:
    void on_ok_clicked();
    void onItemPressed(QListWidgetItem *item);

private:
    Ui::likedpages *ui;
};

#endif // LIKEDPAGES_H
