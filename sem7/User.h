#ifndef USER_H
#define USER_H
#include <QString>

class User
{
    QString name;
public:
    User(QString name) { this->name = name;}
    QString getName() { return this->name;}
};

#endif // USER_H
