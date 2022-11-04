#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    authWidget = new AuthenticationForm();
    adminWidget = new AdministratorForm();
    userWidget = new UserForm();

    ui->widgetContainer->addWidget(authWidget);
    // insert signup widget
    ui->widgetContainer->addWidget(adminWidget);
    ui->widgetContainer->addWidget(userWidget);

    ui->widgetContainer->setCurrentIndex(Auth);
}

MainWindow::~MainWindow()
{
    delete ui;
}

