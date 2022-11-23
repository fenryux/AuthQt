#ifndef AUTHENTICATIONFORM_H
#define AUTHENTICATIONFORM_H

#include <QWidget>
#include "userdao.h"

namespace Ui {
class AuthenticationForm;
}

class AuthenticationForm : public QWidget
{
    Q_OBJECT
public:
    explicit AuthenticationForm(QWidget *parent = nullptr, UserDAO * userDAO = nullptr);
    ~AuthenticationForm();

public slots:
    void loginSlot();
    void signUpSlot();

signals:
    void userAuthenticated(const QString& login);
    void setWidgetActive(QWidget * widget);
    void signUpClicked();

private:
    Ui::AuthenticationForm *ui;

    int attempts = 0;
    UserDAO * userDAO;
};

#endif // AUTHENTICATIONFORM_H
