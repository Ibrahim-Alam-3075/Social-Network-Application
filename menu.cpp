#include "SocialMediaApp.h"
#include "menu.h"
#include "home.h"
#include "login.h"
#include "ui_menu.h"
#include "QPushButton"
#include "QHBoxLayout"
#include "friendlist.h"
#include "likedpages.h"
#include "timeline.h"
#include "createpost.h"
#include "memories.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    setWindowTitle("Navigation Menu");

      string n = Facebook.getCurrentUserName();
      n = "Greetings "+n+", What would you want to see !";
      QString qstr = QString::fromStdString(n);
      ui->greet->setText(qstr);
      ui->greet->setStyleSheet("color: red;");

}

menu::~menu()
{
    delete ui;
}



void menu::on_switchUser_clicked()
{
    close();
    login* l = new login (this);
    l->show();
}


void menu::on_viewFriendsList_clicked()
{
    FriendList* friends = new FriendList (this);
    friends->show();

}


void menu::on_viewLikedPages_clicked()
{
    likedpages * page = new likedpages(this);
    page->show();

}


void menu::on_viewHome_clicked()
{
   home * h = new home (this);
   h->show();

}


void menu::on_viewTimeline_clicked()
{
    timeline* time = new timeline ( this );
    time->show();
}


void menu::on_createPost_clicked()
{
    createpost* cp = new createpost(this);
    cp->show();

}


void menu::on_memories_clicked()
{
  memories * memory = new memories ( this );
  memory->show();
}

