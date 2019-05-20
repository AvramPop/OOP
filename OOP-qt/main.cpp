#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "GUI.h"
#include "Scanner.h"
#include "InMemoryRepository.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ifstream fin("/home/dani/Desktop/code/faculta/an1/sem2/OOP/OOP-qt/conf.in");
    std::string repoType;
    unique_ptr<Repository<VictimFile>> repository;
    fin >> repoType;
    if(repoType == "file"){
        std::string path;
        fin >> path;
        repository = make_unique<FileRepository<VictimFile>>(path);
    } else {
        repository = make_unique<InMemoryRepository<VictimFile>>();
    }
   unique_ptr<VictimFileService> service = make_unique<VictimFileService>(move(repository));
   GUI gui{move(service)};
   gui.show();
   fin.close();
   return a.exec();
}
