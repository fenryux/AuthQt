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
    void read(const QString& filePath);
    void write(const QString& filePath, const QMap<QString, User>& users);
    void save(const QMap<QString, User>& users);
    void saveAs(const QMap<QString, User>& users);
    void insert(const QString& key, const User& user);
    void remove(const QString& key);
    bool contains(const QString& key);

private:
    QWidget * parent;
    QMap<QString, User> users;
};

#endif // USERDAO_H
