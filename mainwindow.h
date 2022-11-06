#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>
#include "authenticationform.h"
#include "administratorform.h"
#include "userform.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    AuthenticationForm * authWidget;
    AdministratorForm * adminWidget;
    UserForm * userWidget;

    QMap<QString, User> * users;

    enum AppMode{
        Authentication,
        SignUp,
        Administrator,
        Users
    };
};
#endif // MAINWINDOW_H
