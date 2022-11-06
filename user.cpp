#include "user.h"

User::User()
{
    this->login = "";
    this->password = "";
    this->blocked = false;
    this->root = false;
}

User::User(const QString& login, const QString& password, const bool& blocked, const bool& root)
{
    this->login = login;
    this->password = password;
    this->blocked = blocked;
    this->root = root;
}

User::User(const User& other)
{
    this->login = other.getLogin();
    this->password = other.getPassword();
    this->blocked = other.isBlocked();
    this->root = other.isRoot();
}

User::~User(){}

void User::setLogin(const QString& login)
{
    this->login = login;
}

void User::setPassword(const QString& password)
{
    this->password = password;
}

bool User::isBlocked() const
{
    return blocked;
}

bool User::isRoot() const
{
    return root;
}

QString User::getLogin() const
{
    return login;
}

QString User::getPassword() const
{
    return password;
}
