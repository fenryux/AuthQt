#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    userDAO = new UserDAO(this);

    authWidget = new AuthenticationForm(this, userDAO);
    signUpWidget = new SignUpForm(this, userDAO);
    userWidget = new UserForm(this, userDAO);


    setupConnectsAndDAO();

    ui->widgetContainer->addWidget(authWidget);
    ui->widgetContainer->addWidget(signUpWidget);
    ui->widgetContainer->addWidget(userWidget);

    ui->widgetContainer->setCurrentIndex(Authentication);
}

void MainWindow::setupConnectsAndDAO(){
    if(!userDAO->read(DEFAULT_FILEPATH)){
        QMessageBox::warning(this, "Error!", "Corrupted file!");
        return;
    }

    connect(userWidget, &UserForm::setWidgetActive, ui->widgetContainer, &QStackedWidget::setCurrentWidget);
    connect(authWidget, &AuthenticationForm::setWidgetActive, ui->widgetContainer, &QStackedWidget::setCurrentWidget);
    connect(signUpWidget, &SignUpForm::setWidgetActive, ui->widgetContainer, &QStackedWidget::setCurrentWidget);

    connect(authWidget, &AuthenticationForm::loginClicked, userDAO, &UserDAO::authenticateUser);
    connect(signUpWidget, &SignUpForm::sendUserData, userDAO, &UserDAO::signUpUser);

    connect(userDAO, &UserDAO::userAuthenticated, userWidget, &UserForm::receiveAuthenticatedUser);
    connect(userDAO, &UserDAO::userAdded, authWidget, &AuthenticationForm::userSignedUp);

    connect(authWidget, &AuthenticationForm::signUpClicked, signUpWidget, &SignUpForm::signUp);
    connect(userWidget, &UserForm::toAuthPage, this,
            [this](){ui->widgetContainer->setCurrentWidget(authWidget);});
}

MainWindow::~MainWindow()
{
    delete authWidget;
    delete userWidget;
    delete userDAO;
    delete ui;
}
