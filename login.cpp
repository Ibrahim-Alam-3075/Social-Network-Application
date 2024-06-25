#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <project.h>
#include "SocialMediaApp.h"
#include "menu.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("Login");
}

login::~login()
{
    delete ui;
}



void login::on_Continue_clicked()
{

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    string id = username.toStdString();

    if( password == "123"&&(Facebook.getUserByID(id)!= nullptr)) {

       QDate date = ui->dateEdit->date(); // Assuming dateEdit is your QDateEdit widget

      int day = date.day();
      int month = date.month();
      int year = date.year();

       Facebook.setCurrentSystemDate(day , month , year);
       Facebook.setCurrentUser(id);
       close();
        menu* m = new menu(this);
        m->show();


    }
    else {
        QMessageBox::warning(this,"Login", "Either Username or password is not correct");
    }


}

