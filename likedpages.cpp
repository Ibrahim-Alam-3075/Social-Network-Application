#include "likedpages.h"
#include <iostream>
#include "ui_likedpages.h"
#include "QListWidgetItem"
#include "SocialMediaApp.h"
#include "pagetimeline.h"


likedpages::likedpages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::likedpages)
{
    ui->setupUi(this);
    setWindowTitle("Liked Pages");
     int no = Facebook.getUserNoOfLkedPages();
    if (no <= 0 )
    {
        no = 1 ;
    }
      for ( int i = 0 ;i< no ;i++){
     string s =   Facebook.viewLikedPages(i);
     QString q = QString::fromStdString(s);

  QListWidgetItem *item = new QListWidgetItem(q);
  item->setTextColor(Qt::red);
  ui->listWidget->addItem(item);
    }

   connect(ui->listWidget, &QListWidget::itemPressed, this, &likedpages::onItemPressed);

}

likedpages::~likedpages()
{
    delete ui;
}
void likedpages::onItemPressed(QListWidgetItem *item) {

      int rowIndex = ui->listWidget->row(item);
      Post** posT = Facebook.getCurrentUserPagesPost(rowIndex);
      int no = Facebook.getCurrentUserNoOfPagesPost(rowIndex);
      string name = Facebook.viewLikedPagesName(rowIndex);
      pagetimeline* page = new pagetimeline ( this, name ,no ,posT );
      page->show();
//    //close();
}

void likedpages::on_ok_clicked()
{
    close ();
}

