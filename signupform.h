#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr);
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
