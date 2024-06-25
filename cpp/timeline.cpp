#include "timeline.h"
#include "ui_timeline.h"
#include "SocialMediaApp.h"
#include "project.h"
#include <iostream>
#include "post.h"

timeline::timeline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timeline)
{
    ui->setupUi(this);
     setWindowTitle("Timeline");
     string  name = Facebook.getCurrentUserName();
     string s = name + " - Timeline" ;
     QString qstr = QString::fromStdString(s);
     ui->label->setText(qstr);

     int no = Facebook.getUserNoOfPost();
//    if (no <= 0 ){
//        no = 1 ;
//    }

    Post** post = Facebook.viewTimelineGetPost();


    for ( int i = 0 ;i< no ;i++){

        cout << post[i]->getActivity();
        string s = name +" "+ post[i]->getActivity();//+" "+ post[i]->viewPost();
        std::cout << "Post" << s << endl;
        QString q = QString::fromStdString(s);
        QListWidgetItem *item = new QListWidgetItem(q);
        item->setTextColor(Qt::black);

        ui->listWidget->addItem(item);


      }
     connect(ui->listWidget, &QListWidget::itemPressed, this, &timeline::onItemPressed);


}

timeline::~timeline()
{
    delete ui;
}

void timeline::onItemPressed(QListWidgetItem *item) {

    int rowIndex = ui->listWidget->row(item);
    Post** posT = Facebook.viewTimelineGetPost();
    int no = Facebook.getUserNoOfPost();
    string *name = new string [no];
    for ( int i = 0 ;i< no ;i++){
        name[i] = Facebook.getCurrentUserName();
    }
    post * p = new post (this, rowIndex, posT,name);
    p->show();
    //close();
}

void timeline::on_back_clicked()
{
    close ();
}

