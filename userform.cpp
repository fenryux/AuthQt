#include "userform.h"
#include "ui_userform.h"

UserForm::UserForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm)
{
    ui->setupUi(this);

    connect(ui->blockedCheckBox, &QCheckBox::stateChanged, this,
            [this](int state){ currentUser.setBlocked(state);});
    connect(ui->selectedUser, &QComboBox::currentTextChanged, this,
            [this](const QString& user){ ui->blockedCheckBox->setEnabled(UserDAO::value(user).isBlocked());});
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::toAuthPageButtonClicked(){
    emit toAuthPage();
}

void UserForm::receiveAuthenticatedUser(User user){
    emit setWidgetActive(this);
    ui->selectedUser->addItems(UserDAO::keys());
    currentUser = user;

    if(!currentUser.isRoot()){
        ui->selectedUser->setEnabled(false);
        ui->blockedCheckBox->setEnabled(false);
    }

    ui->currentUserLabel->setText("Current user: " + currentUser.getLogin());
}
