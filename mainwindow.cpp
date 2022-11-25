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

    connect(authWidget, &AuthenticationForm::signUpClicked, this,
            [this](){ ui->widgetContainer->setCurrentWidget(signUpWidget); });
    connect(signUpWidget, &SignUpForm::toAuth, this,
            [this](){ ui->widgetContainer->setCurrentWidget(authWidget); });

    connect(authWidget, &AuthenticationForm::signUpClicked, this,
            [this](){ ui->widgetContainer->setCurrentWidget(signUpWidget); });
    connect(authWidget, &AuthenticationForm::userAuthenticated, this,
            [this](const QString& login){ userWidget->receiveAuthenticatedUser(userDAO->value(login));
                                          ui->widgetContainer->setCurrentWidget(userWidget); });
    connect(userWidget, &UserForm::toAuth, this,
            [this](){ ui->widgetContainer->setCurrentWidget(authWidget); });
}

MainWindow::~MainWindow()
{
    delete authWidget;
    delete userWidget;
    delete userDAO;
    delete ui;
}
