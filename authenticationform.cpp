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
    emit loginClicked(ui->loginLineEdit->text(), ui->passwordLineEdit->text());

    qDebug() << "Data send to authenticate:";
    qDebug() << "             login:    " + ui->loginLineEdit->text();
    qDebug() << "             password: " + ui->passwordLineEdit->text();
}

void AuthenticationForm::signUpSlot(){
    emit signUpClicked();
}
