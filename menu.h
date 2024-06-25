#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_switchUser_clicked();

    void on_viewFriendsList_clicked();

    void on_viewLikedPages_clicked();

    void on_viewHome_clicked();

    void on_viewTimeline_clicked();

    void on_createPost_clicked();

    void on_memories_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
