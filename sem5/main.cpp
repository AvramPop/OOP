#include "UI.h"
//#include <Windows.h>
#include "PlayList.h"
#include "RepositoryExceptions.h"
#include "CSVPlaylist.h"

using namespace std;

int main()
{
	system("color f4");

	try
	{
		Repository repo("/home/dani/Desktop/code/faculta/an1/sem2/OOP/sem5/Songs.txt");
		FilePlaylist* p = new CSVPlaylist{};
		Controller ctrl(repo, p, SongValidator{});
		UI ui(ctrl);
		ui.run();
		delete p;
	}
	catch (FileException&)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}

	return 0;
}