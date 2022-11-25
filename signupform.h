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
    void toAuth();

public slots:
    void signUpClicked();
    void textEdited(const QString& text);
    void toAuthPage();

private:
    Ui::SignUpForm *ui;

    UserDAO * userDAO;
};

#endif // SIGNUPFORM_H
