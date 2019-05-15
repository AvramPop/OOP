#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "genesgui.h"
#include "Scanner.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //sliderExample(argc, argv);

   QApplication a(argc, argv);
    std::vector<Gene> genes{ Gene{ "yqgE", "E_Coli_K12", "ATGAATTTACAGCAT" }, Gene{ "ppiA", "M_tuberculosis", "TTTTCATCACCGTCGG" }, Gene{ "Col2a1", "Mouse", "TTAAAGCATGGCTCTGTG" } };
    GenesGUI gui{genes};
    gui.show();
    return a.exec();
   // Scanner scanner;
  //      scanner.runConsole();
 //   return 0;
}
