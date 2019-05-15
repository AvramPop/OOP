#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "GUI.h"
#include "Scanner.h"
#include <iostream>
using namespace std;

//std::vector<VictimFile> loadBufferFromFile(){
//    std::ifstream fin("/home/dani/Desktop/code/faculta/an1/sem2/OOP/OOP-qt/data.txt");
//    std::vector<VictimFile> temp;
//    VictimFile temporary;
//    while(!fin.eof()){
//        try{
//            fin >> temporary;
//        } catch(ValidatorException& validatorException){
//            fin.close();
//            throw ValidatorException();
//        }
//        temp.push_back(temporary);
//    }
//    fin.close();
//    return temp;
//}

int main(int argc, char *argv[])
{
    //sliderExample(argc, argv);
   QApplication a(argc, argv);

   unique_ptr<FileRepository<VictimFile>> repository = make_unique<FileRepository<VictimFile>>("/home/dani/Desktop/code/faculta/an1/sem2/OOP/OOP-qt/data.txt");
   unique_ptr<VictimFileService> service = make_unique<VictimFileService>(move(repository));
   GUI gui{service->getList()};
//   std::vector<VictimFile> temp;
//   VictimFile v("dani", "ia", 888, "banii");
//   temp.push_back(v);
//   GUI gui(loadBufferFromFile());
   gui.show();
   return a.exec();
   // Scanner scanner;
  //      scanner.runConsole();
 //   return 0;
}
