#include "friendlist.h"
#include "ui_friendlist.h"
#include "QListWidgetItem"
#include "SocialMediaApp.h"
#include <string>
#include <iostream>
using namespace std;

FriendList::FriendList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendList)
{
    ui->setupUi(this);
    setWindowTitle("Friends List");
      int no = Facebook.getUserNoOfFriend();
      if (no <= 0 ){
          no = 1 ;
      }
      for ( int i = 0 ;i< no ;i++){
       string s =   Facebook.viewFriendList(i);
       QString q = QString::fromStdString(s);

    QListWidgetItem *item = new QListWidgetItem(q);
    item->setTextColor(Qt::red);
    ui->listWidget->addItem(item);
      }



}

FriendList::~FriendList()
{
    delete ui;
}

void FriendList::on_ok_clicked()
{
close();
}



void FriendList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    string str = item->text().toStdString();
    string id;
    size_t startPos = str.find('u');
    if (startPos != string::npos && startPos + 1 < str.size() && isdigit(str[startPos + 1])) {
        size_t endPos = str.find_first_not_of("0123456789", startPos + 1);
        id = str.substr(startPos, endPos - startPos);
    }
     cout << Facebook.getUserNameByID(id);





}

