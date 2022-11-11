#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    authWidget = new AuthenticationForm();
    userWidget = new UserForm();

    userDAO = new UserDAO(this);

    setupConnectsAndDAO();

    ui->widgetContainer->addWidget(authWidget);
    // insert signup widget
    ui->widgetContainer->addWidget(userWidget);

    ui->widgetContainer->setCurrentIndex(Authentication);
}

void MainWindow::setupConnectsAndDAO(){
    if(!userDAO->read(DEFAULT_FILEPATH)){
        QMessageBox::warning(this, "Error!", "Corrupted file!");
        return;
    }

    connect(authWidget, &AuthenticationForm::loginClicked, userDAO, &UserDAO::authenticateUser);
    connect(userDAO, &UserDAO::userAuthenticated, this, &MainWindow::setApplicationMode);
//    connect(authWidget, &AuthenticationForm::signUpClicked, this, &MainWindow::setApplicationMode);
//    connect(userDAO, &UserDAO::sendAuthenticatedUser, userWidget, &UserForm::setCurrentUser);
}

MainWindow::~MainWindow()
{
    delete authWidget;
    delete userWidget;
    delete userDAO;
    delete ui;
}

void MainWindow::setApplicationMode(AppMode mode){

}
