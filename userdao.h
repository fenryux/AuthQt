#ifndef USERDAO_H
#define USERDAO_H

#include "user.h"
#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qfile.h>

class UserDAO
{
public:
    explicit UserDAO(QWidget * parent = nullptr);
    bool read(const QString& filePath);
    void write(const QString& filePath);
    User value(const QString& key);
    bool insert(const QString& key, const User& value);
    bool remove(const QString& key);
    QList<QString> keys();
    QList<User> values();
    bool contains(const QString& key);
    bool authenticateUser(const QString& login, const QString& password);

private:
    QWidget * parent;
    QMap<QString, User> * users;

    QMap<QString, User> fromJsonToMap(const QJsonArray& jsonArray);
    QJsonArray toJsonArray();
};

#endif // USERDAO_H
