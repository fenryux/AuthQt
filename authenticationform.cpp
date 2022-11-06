#include "authenticationform.h"
#include "./ui_authenticationform.h"

AuthenticationForm::AuthenticationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthenticationForm)
{
    ui->setupUi(this);

    connect(ui->loginPushButton, &QPushButton::clicked, this, &AuthenticationForm::loginSlot);
    connect(ui->signUpPushButton, &QPushButton::clicked, this, &AuthenticationForm::signUpSlot);
}

AuthenticationForm::~AuthenticationForm()
{
    delete ui;
}

void AuthenticationForm::loginSlot(){
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLabel->text();


}

void AuthenticationForm::signUpSlot(){

}
