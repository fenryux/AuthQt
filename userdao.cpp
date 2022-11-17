#include "userdao.h"
#include <qmessagebox.h>

UserDAO::UserDAO(QWidget * parent): parent(parent)
{}

void UserDAO::authenticateUser(const QString& login, const QString& password){
    if(users.contains(login) && users.value(login).getPassword() == password){
        emit userAuthenticated(users.value(login));
    }
    else {
        QMessageBox::warning(parent, "Warning!", "Incorrect login or password!");
        return;
    }
}

void UserDAO::signUpUser(const QString& login, const QString& password){
    if(!users.contains(login)){
        User newUser(login, password, false, false);
        users.insert(login, newUser);

        emit userSignedUp();
    }
    else{
        QMessageBox::warning(parent, "Warning!", "User already exits!");
        return;
    }
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
        users = fromJsonToMap(jsonDocument.array());
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

    for(const auto it: users)
        jsonArray.push_back(it.toJsonObject());

    return jsonArray;
}

