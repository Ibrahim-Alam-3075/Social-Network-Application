#include "home.h"
#include "SocialMediaApp.h"
#include "QListWidgetItem"
#include "ui_home.h"
#include <string>
#include "QVBoxLayout"
#include "QLabel"
#include <iostream>
#include <QDebug>
#include <project.h>
#include "post.h"

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{

    ui->setupUi(this);
    setWindowTitle("Home");
    string s = Facebook.getCurrentUserName()+ " - Home Page" ;
    QString qstr = QString::fromStdString(s);
    ui->label->setText(qstr);

     int no = Facebook.getUserNoOfHomePost();
//    if (no <= 0 ){
//        no = 1 ;
//    }
    Post** post = Facebook.viewHomeGetPost();
    string * name  =  Facebook.viewHomeName();

    for ( int i = 0 ;i< no ;i++){

        string s = name[i] +" "+ post[i]->getActivity();//+" "+ post[i]->viewPost();
        QString q = QString::fromStdString(s);
        QListWidgetItem *item = new QListWidgetItem(q);
        item->setTextColor(Qt::black);

        ui->listWidget->addItem(item);


      }
     connect(ui->listWidget, &QListWidget::itemPressed, this, &home::onItemPressed);
}

home::~home()
{
    delete ui;
}
void home::onItemPressed(QListWidgetItem *item) {

    int rowIndex = ui->listWidget->row(item);
    Post** posT = Facebook.viewHomeGetPost();
    string * name  =  Facebook.viewHomeName();
    post * p = new post (this, rowIndex, posT,name);
    p->show();
    //close();
}



void home::on_back_clicked()
{
    close();
}

