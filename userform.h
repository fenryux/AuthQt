#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>
#include "user.h"
#include "userdao.h"

namespace Ui {
class UserForm;
}

class UserForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = nullptr, UserDAO * userDAO = nullptr);
    ~UserForm();

signals:
    void setWidgetActive(QWidget * widget);
    void toAuthPage();

public slots:
    void receiveAuthenticatedUser(User user);

private slots:
    void toAuthPageButtonClicked();

private:
    Ui::UserForm *ui;

    UserDAO * userDAO;
    User currentUser;
};

#endif // USERFORM_H
