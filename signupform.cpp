#include "signupform.h"
#include "ui_signupform.h"

SignUpForm::SignUpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpForm)
{
    ui->setupUi(this);

    ui->signUpPushButton->setEnabled(false);

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
    emit sendUserData(ui->loginLineEdit->text(), ui->passwordLineEdit->text());
}

void SignUpForm::signUp(){
    emit setWidgetActive(this);
}
