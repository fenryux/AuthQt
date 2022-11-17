#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>
#include "user.h"

namespace Ui {
class UserForm;
}

class UserForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserForm(QWidget *parent = nullptr);
    ~UserForm();

signals:
    void setWidgetActive(QWidget * widget);

public slots:
    void receiveAuthenticatedUser(User user);

private:
    Ui::UserForm *ui;

    User currentUser;
};

#endif // USERFORM_H
