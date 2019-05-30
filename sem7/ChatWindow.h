#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>

#include "Observer.h"
#include "ChatSession.h"
#include <QVector>
#include <QDebug>


class ChatWindow : public Observer, public QWidget
{
private:
    ChatSession *chatSession;
    QPushButton *button;
    QListWidget *list;
    QLineEdit *lineEdit;
    User *user;

    void update(){
        qDebug() << "updating";
        QVector<Message*> messages = this->chatSession->getMessages();
        this->list->clear();
          for(Message* message : messages)
         {
              QString string = message->time.time().toString() + " " +  message->user->getName() + ": " + message->mess;
              QListWidgetItem *item =  new QListWidgetItem(string);
              if (message->user->getName() == this->user->getName())
                    item->setTextAlignment(Qt::AlignRight);
              else
                    item->setTextAlignment(Qt::AlignLeft);
              this->list->addItem(item);
            }}
public:
    ChatWindow(User *user, ChatSession* session) {
        this->user = user;
        this->chatSession = session;
        chatSession->registerObserver(this);
        QVBoxLayout *layout = new  QVBoxLayout{this};
        QWidget *widget = new QWidget{};
        QHBoxLayout *horizontalLayout = new QHBoxLayout{widget};
        button = new QPushButton{"Send"};
        list = new QListWidget{};
        lineEdit = new QLineEdit{};
        layout->addWidget(list);
        horizontalLayout->addWidget(lineEdit);
        horizontalLayout->addWidget(button);
        layout->addWidget(widget);

        QObject::connect(this->button, &QPushButton::clicked, this, &ChatWindow::buttonHandler);
    }

    void buttonHandler()
    {

        QString text = this->lineEdit->text();
       // qDebug() << "button got  messagge: " <<  text;
        Message* message = new Message{text, user};
        this->chatSession->addMessage(message);
       // qDebug() << "printing";
        this->chatSession->notify();
    }


};

#endif // CHATWINDOW_H
