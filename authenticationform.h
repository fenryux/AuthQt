#ifndef AUTHENTICATIONFORM_H
#define AUTHENTICATIONFORM_H

#include <QWidget>

namespace Ui {
class AuthenticationForm;
}

class AuthenticationForm : public QWidget
{
    Q_OBJECT
public:
    explicit AuthenticationForm(QWidget *parent = nullptr);
    ~AuthenticationForm();

public slots:
    void loginSlot();
    void signUpSlot();

signals:
    void loginClicked(QString login, QString password);
    void signUpClicked();

private:
    Ui::AuthenticationForm *ui;
};

#endif // AUTHENTICATIONFORM_H
