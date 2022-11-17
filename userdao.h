#ifndef USERDAO_H
#define USERDAO_H

#include "user.h"
#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qfile.h>

class UserDAO: public QObject
{
    Q_OBJECT
public:
    explicit UserDAO(QWidget * parent = nullptr);
    bool read(const QString& filePath);
    void write(const QString& filePath);
    bool contains(const QString& key);
    QList<QString> keys();
    QList<User> values();

public slots:
    void authenticateUser(const QString& login, const QString& password);
    void signUpUser(const QString& login, const QString& password);

signals:
    void userAuthenticated(User user);
    void userSignedUp();

private:
    QWidget * parent;
    QMap<QString, User> users;

    QMap<QString, User> fromJsonToMap(const QJsonArray& jsonArray);
    QJsonArray toJsonArray();
};

#endif // USERDAO_H
