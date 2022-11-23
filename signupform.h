#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include "userdao.h"

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr, UserDAO * userDAO = nullptr);
    ~SignUpForm();

signals:
    void sendUserData(const QString& login, const QString& password);
    void setWidgetActive(QWidget * widget);

public slots:
    void signUpClicked();
    void textEdited(const QString& text);
    void signUp();

private:
    Ui::SignUpForm *ui;
};

#endif // SIGNUPFORM_H
