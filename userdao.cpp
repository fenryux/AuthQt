#include "userdao.h"
#include <qmessagebox.h>

UserDAO::UserDAO(QWidget * parent): parent(parent)
{}

void UserDAO::read(const QString& filePath) {
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(parent, "Warning!", "Cannot open file: " + file.errorString());
        return;
    }
}

void UserDAO::write(const QString& filePath, const QMap<QString ,User>& users) {

}

void UserDAO::save(const QMap<QString, User>& users) {

}

void UserDAO::saveAs(const QMap<QString, User>& users){

}
