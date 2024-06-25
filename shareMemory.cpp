#include "shareMemory.h"
#include "ui_sharememory.h"
#include "SocialMediaApp.h"
#include "project.h"

shareMemory::shareMemory(QWidget *parent,Post* p) :
    QDialog(parent),post(p),
    ui(new Ui::shareMemory)
{
    ui->setupUi(this);
    setWindowTitle("Share Memory");
    ui->textEdit->setStyleSheet("background-color: yellow; color: black; font-size: 24pt; font-family: Arial;");
}

shareMemory::~shareMemory()
{
    delete ui;
}

void shareMemory::on_share_clicked()
{
    QString selectedDescription = ui->textEdit->toPlainText();
    string type = "shared";
    string activity = "a memory";
    string description = selectedDescription.toStdString();
    Facebook.shareMemory(type,activity,description,post);
    close();
}

