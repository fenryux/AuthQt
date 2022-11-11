#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>
#include <QMessageBox>
#include "authenticationform.h"
#include "userform.h"
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

public slots:
    void setApplicationMode(AppMode mode);

private:
    Ui::MainWindow *ui;
    AuthenticationForm * authWidget;
    UserForm * userWidget;

    const QString DEFAULT_FILEPATH = "../AuthQt/db.json";
    UserDAO * userDAO;

    void setupConnectsAndDAO();

};
#endif // MAINWINDOW_H
