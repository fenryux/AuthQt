#include "userdao.h"
#include <qmessagebox.h>

UserDAO::UserDAO(QWidget * parent): parent(parent)
{
    users = new QMap<QString, User>();
}

bool UserDAO::authenticateUser(const QString& login, const QString& password){
    if(users->contains(login) && users->value(login).getPassword() == password){
        return true;
    }
    return false;
}

bool UserDAO::contains(const QString& key){
    return users->contains(key);
}

bool UserDAO::insert(const QString& key, const User& user){
    if(!users->contains(key)){
        users->insert(key, user);
        return true;
    }
    else return false;
}

bool UserDAO::remove(const QString& key){
    if(users->contains(key)){
        users->remove(key);
        return true;
    }
    else return false;
}

bool UserDAO::read(const QString& filePath) {
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(parent, "Warning!",
                                     "Cannot open file: " + file.errorString());
        return false;
    }

    QJsonDocument jsonDocument = QJsonDocument::fromJson(file.readAll());

    if(!jsonDocument.array().isEmpty())
        *users = fromJsonToMap(jsonDocument.array());
    else{
        QMessageBox::warning(parent, "Warning!", "JSON file doesn't contain array!");
        return false;
    }

    return true;
}
// TODO: actually complete method
void UserDAO::write(const QString& filePath) {
    QFile file(filePath);

    if(!file.open(QIODevice::WriteOnly|QFile::Text)){
        QMessageBox::warning(parent, "Warning!",
                                     "Cannot open file: " + file.errorString());
        return;
    }
}

User UserDAO::value(const QString& key){
    return users->operator[](key);
}

QList<QString> UserDAO::keys(){
    return users->keys();
}

QList<User> UserDAO::values(){
    return users->values();
}

QMap<QString, User> UserDAO::fromJsonToMap(const QJsonArray& jsonArray){
    QMap<QString, User> userMap;

    for(const auto it: jsonArray){
        User user(it.toObject());
        userMap.insert(user.getLogin(), user);
    }

    return userMap;
}

QJsonArray UserDAO::toJsonArray(){
    QJsonArray jsonArray;

    for(const auto it: *users)
        jsonArray.push_back(it.toJsonObject());

    return jsonArray;
}

