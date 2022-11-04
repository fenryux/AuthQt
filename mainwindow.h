#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "authenticationform.h"
#include "administratorform.h"
#include "userform.h"

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

    enum AppMode{
        Auth,
        SignUp,
        Admin,
        User
    };
};
#endif // MAINWINDOW_H
