#include "createpost.h"
#include "ui_createpost.h"
#include "SocialMediaApp.h"

createpost::createpost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createpost)
{
    ui->setupUi(this);
    setWindowTitle("Create Post");


}

createpost::~createpost()
{
    delete ui;
}

void createpost::on_share_clicked()
{
    QString selectedType = ui->comboBox->currentText();
    QString selectedActivity = ui->textEdit->toPlainText();
    QString selectedDescription = ui->textEdit_2->toPlainText();
    string type = selectedType.toStdString();
    string activity = selectedActivity.toStdString();
    string description = selectedDescription.toStdString();
    Facebook.addPost(type,activity,description);
    close();
}

