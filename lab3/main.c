#include <stdio.h>
#include <string.h>
#include "File.h"
#include "FileRepository.h"
#include "Console.h"

int main(){
    FileRepository fileRepository = newFileRepository();
    runConsole(fileRepository);
    return 0;
}