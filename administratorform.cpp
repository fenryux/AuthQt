#include "administratorform.h"
#include "ui_administratorform.h"

AdministratorForm::AdministratorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdministratorForm)
{
    ui->setupUi(this);
}

AdministratorForm::~AdministratorForm()
{
    delete ui;
}
