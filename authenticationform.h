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

private:
    Ui::AuthenticationForm *ui;
};

#endif // AUTHENTICATIONFORM_H
