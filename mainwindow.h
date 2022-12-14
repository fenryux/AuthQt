#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>
#include <QMessageBox>
#include "authenticationform.h"
#include "userform.h"
#include "signupform.h"
#include "userdao.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum AppMode{
        Authentication,
        SignUp,
        Users
    };

private:
    Ui::MainWindow *ui;
    AuthenticationForm * authWidget;
    SignUpForm * signUpWidget;
    UserForm * userWidget;

    const QString DEFAULT_FILEPATH = "../AuthQt/db.json";
    UserDAO * userDAO;

    void setupConnectsAndDAO();

};
#endif // MAINWINDOW_H
