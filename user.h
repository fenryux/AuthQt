#ifndef USER_H
#define USER_H

#include <QtCore/qstring.h>
#include <qjsonobject.h>

class User
{
private:
    QString login;
    QString password;
    bool blocked;
    bool root;

public:
    User(const QString& login, const QString& password, const bool& blocked, const bool& root);
    User(const QJsonObject& jsonObject);
    User(const User& other);
    User();
    ~User();

    void setLogin(const QString& login);
    void setPassword(const QString& password);
    bool isBlocked() const;
    bool isRoot() const;
    QString getLogin() const;
    QString getPassword() const;
    QJsonObject toJsonObject() const;
};

#endif // USER_H
