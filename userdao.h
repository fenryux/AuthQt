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
    bool contains(const QString& key);
    void insert(const QString& key, const User& user);
    void remove(const QString& key);
    QList<QString> keys();
    QList<User> values();

private:
    QWidget * parent;
    QMap<QString, User> users;

    QMap<QString, User> fromJsonToMap(const QJsonArray& jsonArray);
};

#endif // USERDAO_H
