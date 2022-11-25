#include "userform.h"
#include "ui_userform.h"

UserForm::UserForm(QWidget *parent, UserDAO * userDAO) :
    QWidget(parent),
    ui(new Ui::UserForm),
    userDAO(userDAO)
{
    ui->setupUi(this);

    connect(ui->blockedCheckBox, &QCheckBox::stateChanged, this,
            [this](int state){ currentUser.setBlocked(state);});
    connect(ui->selectedUser, &QComboBox::currentTextChanged, this,
            [this, userDAO](const QString& user){ ui->blockedCheckBox->setEnabled(userDAO->value(user).isBlocked());});
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::toAuthPage(){
    emit toAuth();
}

void UserForm::receiveAuthenticatedUser(User user){
    ui->selectedUser->addItems(userDAO->keys());
    currentUser = user;

    if(!currentUser.isRoot()){
        ui->selectedUser->setEnabled(false);
        ui->blockedCheckBox->setEnabled(false);
    }

    ui->currentUserLabel->setText("Current user: " + currentUser.getLogin());
}
