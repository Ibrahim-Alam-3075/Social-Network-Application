#include "pagetimeline.h"
#include "ui_pagetimeline.h"
#include "post.h"

pagetimeline::pagetimeline(QWidget *parent, string name  , int n  ,Post** pos ) :
    QDialog(parent), name(name), n(n),p(pos),
    ui(new Ui::pagetimeline)
{
    ui->setupUi(this);
    setWindowTitle("Page Timeline");
    QString qstr = QString::fromStdString(name);
    ui->label->setText(qstr);

    for ( int i = 0 ;i< n ;i++)
    {
        string s = name +" "+ p[i]->getActivity();//+" "+ post[i]->viewPost();
        QString q = QString::fromStdString(s);
        QListWidgetItem *item = new QListWidgetItem(q);
        item->setTextColor(Qt::black);
        ui->listWidget->addItem(item);
      }
      connect(ui->listWidget, &QListWidget::itemPressed, this, &pagetimeline::onItemPressed);
}

pagetimeline::~pagetimeline()
{
    delete ui;
}
void pagetimeline::onItemPressed(QListWidgetItem *item) {

    int rowIndex = ui->listWidget->row(item);
    string *naMe = new string [n];
    for ( int i = 0 ;i< n ;i++)
    {
        naMe[i] = name;
    }
    post * posT = new post (this, rowIndex, p, naMe);
    posT->show();

}


void pagetimeline::on_back_clicked()
{
    close();
}

