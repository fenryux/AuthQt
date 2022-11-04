#ifndef ADMINISTRATORFORM_H
#define ADMINISTRATORFORM_H

#include <QWidget>

namespace Ui {
class AdministratorForm;
}

class AdministratorForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdministratorForm(QWidget *parent = nullptr);
    ~AdministratorForm();

private:
    Ui::AdministratorForm *ui;
};

#endif // ADMINISTRATORFORM_H
