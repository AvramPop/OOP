#include "ChatSession.h"
#include "ChatWindow.h"
#include "Widget.h"
#include "User.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatSession* session = new ChatSession();
    User *user1 = new User{"user1"};
    User *user2 = new User{"user2"};
    User *user3 = new User{"user3"};
    User *user4 = new User{"user4"};


    ChatWindow* window1 = new ChatWindow{user1, session};
    ChatWindow* window2 = new ChatWindow{user2, session};
    ChatWindow* window3 = new ChatWindow{user3, session};
    ChatWindow* window4 = new ChatWindow{user4, session};
    window1->show();
    window2->show();
    window3->show();
    window4->show();

    return a.exec();
}
