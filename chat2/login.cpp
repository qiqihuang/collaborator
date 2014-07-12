#include "login.h"
#include "ui_login.h"
#include <QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_btn_login_clicked()
{
    QString sUsername = ui->edit_username->text();
    QString sPassword = ui->edit_password->text();
    if (sUsername.isEmpty()
            || sPassword.isEmpty())
    {
        QMessageBox::warning(this, "Login Failed", "Username or Password is empty");
    }
    this->accept();
}
