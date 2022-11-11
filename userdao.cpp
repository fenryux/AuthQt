#include "userdao.h"
#include <qmessagebox.h>

UserDAO::UserDAO(QWidget * parent): parent(parent)
{}

void UserDAO::authenticateUser(QString login, QString password){
    if(users.contains(login) && users.value(login).getPassword() == password){
        emit userAuthenticated(users.value(login));
        // emit sendAuthenticatedUser(users.value(login));
    }
    else {
        QMessageBox::warning(parent, "Warning!", "Incorrect login or password!");
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

