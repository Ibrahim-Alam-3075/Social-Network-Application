#include "post.h"
#include "ui_post.h"
#include "project.h"
#include "SocialMediaApp.h"
#include <iostream>
#include "QListWidgetItem"
#include "QMessageBox"

post::post(QWidget *parent) : QDialog(parent),ui(new Ui::post)
{
    ui->setupUi(this);
}

post::post(QWidget *parent, int rowIndex,Post**post,string*name) :QDialog(parent),ui(new Ui::post),rowInd(rowIndex),p(post),name(name)
{
 ui->setupUi(this);
 setWindowTitle("Post");
 string date =  p[rowInd]->getDate();
 QString qst = QString::fromStdString(date);
 ui->date->setText(qst);


 string s = name[rowInd] +" "+ p[rowInd]->getActivity();
 QString qString = QString::fromStdString(s);
 ui->textEdit->setText(qString);
 ui->textEdit->setStyleSheet("color: white;");
 ui->textEdit->setStyleSheet("background-color: red; padding: 5px; border: 1px solid black;");
 ui->textEdit->setReadOnly(true);
 ui->textEdit->setWordWrapMode(QTextOption::WordWrap);

 s = p[rowInd]->viewPost(name[rowInd]);
 qString = QString::fromStdString(s);
 ui->textEdit_2->setText(qString);
 ui->textEdit_2->setStyleSheet("color: white;");
 ui->textEdit_2->setStyleSheet("background-color: orange; padding: 5px; border: 1px solid black;");
 ui->textEdit_2->setReadOnly(true);
 ui->textEdit_2->setWordWrapMode(QTextOption::WordWrap);




 int noCom = p[rowInd]->getNumComments();

  for ( int j = 0 ;j< noCom ;j++)
  {
  string s = p[rowInd]->viewPostComments(j);
  std::cout << s << endl;
  QString q = QString::fromStdString(s);
  QListWidgetItem *item = new QListWidgetItem(q);
  item->setTextColor(Qt::red);
  ui->listWidget->addItem(item);
  }
  string com = "No of Comments: "+ to_string(noCom);
  QString qStr = QString::fromStdString(com);
  ui->noOfCom->setText(qStr);


    int nolikes = p[rowInd]->getNumLikes();
    cout << nolikes <<endl;
  for ( int i = 0 ;i< nolikes ;i++)
  {
   string s  = p[rowInd]->viewPostLikers(i);
   QString q = QString::fromStdString(s);
   QListWidgetItem *item = new QListWidgetItem(q);
   item->setTextColor(Qt::red);
   ui->listWidget_2->addItem(item);
   }
  }


post::~post()
{
    delete ui;
}

void post::on_exit_clicked()
{
    close();
}


void post::on_postComment_clicked()
{

    //Post** post = Facebook.viewHomeGetPost();
    int noCom = p[rowInd]->getNumComments();
    if ( noCom >= 10){
         QMessageBox::warning(this,"Comment", "The Post has reached its full limit of comments!");
    }else{
    QString text =ui->textEdit_3->toPlainText();
    string s = text.toStdString();
    string id = Facebook.getCurrentUserId();
    string name = Facebook.getCurrentUserName();
    cout << "t1"<< s << endl;
    p[rowInd]->addComment(id , name , s ,noCom);
    noCom++;
    p[rowInd]->setNumComments(noCom);
    ui->textEdit_3->clear();
    ui->textEdit_3->setFocus();

    }

}


void post::on_like_clicked()
{
    string name = Facebook.getCurrentUserName();
    int likes = p[rowInd]->getNumLikes();
    if ( likes >= 10)
    {
      QMessageBox::warning(this,"Likes", "The Post has reached its full limit of Likes!");
    }else if ( p[rowInd]->checkLiker(name)){

        QMessageBox::warning(this,"Likes", "You already likes this Post!");
    } else{
   string name = Facebook.getCurrentUserName();

   p[rowInd]->addLiker(name,likes);
   likes++;
   p[rowInd]->setNumLikes(likes);
    }

}

