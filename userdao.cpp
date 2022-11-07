#include "userdao.h"
#include <qmessagebox.h>

UserDAO::UserDAO(QWidget * parent): parent(parent)
{}

bool UserDAO::read(const QString& filePath) {
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(parent, "Warning!",
                                     "Cannot open file: " + file.errorString());
        return false;
    }

    QJsonDocument jsonDocument(QJsonDocument::fromJson(QByteArray(file.readAll())));

    if(!jsonDocument.array().isEmpty())
        users = fromJsonToMap(jsonDocument.array());
    else{
        QMessageBox::warning(parent, "Warning!", "JSON file doesn't contain array!");
        return false;
    }

    return true;
}

QMap<QString, User> UserDAO::fromJsonToMap(const QJsonArray& jsonArray){
    QMap<QString, User> userMap;

    for(const auto it: jsonArray){
        User user(it.toObject());
        userMap.insert(user.getLogin(), user);
    }

    return userMap;
}

void UserDAO::write(const QString& filePath) {

}

