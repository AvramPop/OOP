#ifndef MESSAGE_H
#define MESSAGE_H
#include "User.h"
#include <QDateTime>
#include <QString>



class Message
{
public:
        QString mess;
        User *user;
        QDateTime time;
        Message(QString message, User* user) { this->mess = message; this->user = user; this->time = QDateTime::currentDateTime();}
};

#endif // MESSAGE_H
