#ifndef FRIENDLIST_H
#define FRIENDLIST_H
#include <QListWidgetItem>

#include <QDialog>

namespace Ui {
class FriendList;
}

class FriendList : public QDialog
{
    Q_OBJECT

public:
    explicit FriendList(QWidget *parent = nullptr);
    ~FriendList();

private slots:
    void on_ok_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::FriendList *ui;
};

#endif // FRIENDLIST_H
