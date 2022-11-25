#include "authenticationform.h"
#include "./ui_authenticationform.h"

#include <qmessagebox.h>

AuthenticationForm::AuthenticationForm(QWidget *parent, UserDAO * userDAO) :
    QWidget(parent),
    userDAO(userDAO),
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
    QString password = ui->passwordLineEdit->text();

    if(!userDAO->authenticateUser(login, password)){
        attempts++;
        if(attempts == 3){
            QMessageBox::warning(this, "Warning!",
                                       "Over attempts limit!");
            QCoreApplication::exit();
        }
        else
            QMessageBox::warning(this, "Warning!",
                                       "Invalid login or password! Attempts left: " + QString::number(attempts));
        ui->passwordLineEdit->text().clear();
        return;
    }

    emit userAuthenticated(login);
}

void AuthenticationForm::signUpSlot(){
    emit signUpClicked();
}
