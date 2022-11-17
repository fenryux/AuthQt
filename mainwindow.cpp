#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    authWidget = new AuthenticationForm();
    signUpWidget = new SignUpForm();
    userWidget = new UserForm();

    userDAO = new UserDAO(this);

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

    connect(authWidget, &AuthenticationForm::loginClicked, userDAO, &UserDAO::authenticateUser);
    connect(userDAO, &UserDAO::userAuthenticated, userWidget, &UserForm::receiveAuthenticatedUser);
    connect(userWidget, &UserForm::setWidgetActive, ui->widgetContainer, &QStackedWidget::setCurrentWidget);

    connect(authWidget, &AuthenticationForm::signUpClicked, signUpWidget, &SignUpForm::signUp);
    connect(signUpWidget, &SignUpForm::setWidgetActive, ui->widgetContainer, &QStackedWidget::setCurrentWidget);
    connect(signUpWidget, &SignUpForm::sendUserData, userDAO, &UserDAO::signUpUser);
    connect(userDAO, &UserDAO::userSignedUp, authWidget, &AuthenticationForm::userSignedUp);
    connect(authWidget, &AuthenticationForm::setWidgetActive, ui->widgetContainer, &QStackedWidget::setCurrentWidget);
//    connect(userDAO, &UserDAO::sendAuthenticatedUser, userWidget, &UserForm::setCurrentUser);
}

MainWindow::~MainWindow()
{
    delete authWidget;
    delete userWidget;
    delete userDAO;
    delete ui;
}
