#ifndef CHATSESSION_H
#define CHATSESSION_H

#include "Subject.h"
#include "Message.h"



class ChatSession : public Subject
{
private:
    QVector<Message*> messages;
public:
    ChatSession(){}
    QVector<Message*> getMessages() { return this->messages;}
    void addMessage(Message* message) { this->messages.push_back(message);}
};

#endif // CHATSESSION_H
