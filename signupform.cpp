#include "signupform.h"
#include "ui_signupform.h"

#include <qmessagebox.h>

SignUpForm::SignUpForm(QWidget *parent, UserDAO * userDAO) :
    QWidget(parent),
    ui(new Ui::SignUpForm),
    userDAO(userDAO)
{
    ui->setupUi(this);

    ui->signUpPushButton->setEnabled(false);

    connect(ui->toAuthPagePushButton, &QPushButton::clicked, this, &SignUpForm::toAuthPage);
    connect(ui->signUpPushButton, &QPushButton::clicked, this, &SignUpForm::signUpClicked);
    connect(ui->loginLineEdit, &QLineEdit::textEdited, this, &SignUpForm::textEdited);
    connect(ui->passwordLineEdit, &QLineEdit::textEdited, this, &SignUpForm::textEdited);
    connect(ui->confirmLineEdit, &QLineEdit::textEdited, this, &SignUpForm::textEdited);
}

SignUpForm::~SignUpForm()
{
    delete ui;
}

void SignUpForm::textEdited(const QString& text){
    ui->signUpPushButton->setEnabled(ui->loginLineEdit->text() != "" &&
                                     ui->passwordLineEdit->text() == ui->confirmLineEdit->text() &&
                                     ui->passwordLineEdit->text() != "");
}

void SignUpForm::signUpClicked(){
    User user(ui->loginLineEdit->text(),
              ui->passwordLineEdit->text(),
              false,false);
    if(userDAO->insert(user.getLogin(), user)){
        emit toAuth();
        ui->loginLineEdit->clear();
        ui->passwordLineEdit->clear();
        ui->confirmLineEdit->clear();
    }
    else{
        QMessageBox::warning(this, "Warning!", "User already exists!");
        return;
    }
}

void SignUpForm::toAuthPage(){
    emit toAuth();
    ui->loginLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->confirmLineEdit->clear();
}
