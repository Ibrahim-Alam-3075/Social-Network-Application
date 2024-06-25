#include "memories.h"
#include "ui_memories.h"
#include <string>
#include "SocialMediaApp.h"
#include "QVBoxLayout"
#include "QLabel"
#include <iostream>
#include <QDebug>
#include <project.h>
#include "post.h"
#include "QMessageBox"
#include "shareMemory.h"

memories::memories(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memories)
{
    ui->setupUi(this);
    setWindowTitle("Memories");
    string  name = Facebook.getCurrentUserName();
    string s = name + " - Memories" ;
    QString qstr = QString::fromStdString(s);
    ui->label->setText(qstr);

    int no = 0;
//    if (no <= 0 ){
//        no = 1 ;
//    }

   Post** post = Facebook.viewMemoryGetPost(no);


   for ( int i = 0 ;i< no ;i++){

       string s = name +" "+ post[i]->getActivity() + ", On this day(1 Year Ago) ";//+" "+ post[i]->viewPost();

       QString q = QString::fromStdString(s);
       QListWidgetItem *item = new QListWidgetItem(q);
       item->setTextColor(Qt::black);

       ui->listWidget->addItem(item);

     }
   connect(ui->listWidget, &QListWidget::itemPressed, this, &memories::onItemPressed);
}

memories::~memories()
{
    delete ui;
}
void memories::onItemPressed(QListWidgetItem *item) {

    int rowIndex = ui->listWidget->row(item);
    int no = 0;
    Post** posT = Facebook.viewMemoryGetPost(no);
    string *name = new string [no];
    for ( int i = 0 ;i< no ;i++)
    {
        name[i] = Facebook.getCurrentUserName();
    }
    post * p = new post (this, rowIndex, posT,name);
    p->show();
    //close();
}

void memories::on_back_clicked()
{
    close();
}


void memories::on_share_clicked()
{
    int no = 0 ;
    Post** posT = Facebook.viewMemoryGetPost(no);
    int rowIndex = 0;
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
        if (currentItem) {
            rowIndex = ui->listWidget->row(currentItem);
            //close();
         shareMemory * memoryShare = new shareMemory(this,posT[rowIndex]);
         memoryShare->show();

        } else {
            QMessageBox::warning(this,"Memories", "No item selected!");
        }

}

