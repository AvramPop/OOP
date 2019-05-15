#include "Controller.h"
#include <algorithm>
#include "FilePlaylist.h"
#include "RepositoryExceptions.h"
#include "UndoAdd.h"
#include "UndoRemove.h"

using namespace std;

void Controller::addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source)
{
	Song s{ artist, title, Duration{minutes, seconds}, source };
	this->validator.validate(s);
	this->repo.addSong(s);
	unique_ptr<UndoAction> undoAdd = make_unique<UndoAdd>(repo, s);
	undoHistory.push_back(move(undoAdd));
}

void Controller::removeSongFromRepository(const std::string & artist, const std::string & title)
{
	Song s = this->repo.findByArtistAndTitle(artist, title);
	this->repo.removeSong(s);
    unique_ptr<UndoAction> undoRemove = make_unique<UndoRemove>(repo, s);
    undoHistory.push_back(std::move(undoRemove));
}

void Controller::addSongToPlaylist(const Song& song)
{
	if (this->playList == nullptr)
		return;
	this->playList->add(song);
}

void Controller::addAllSongsByArtistToPlaylist(const std::string& artist)
{
	vector<Song> songs = this->repo.getSongs();
	int nSongs = count_if(songs.begin(), songs.end(),
		[artist](const Song& s)
		{
			return s.getArtist() == artist;
		});

	vector<Song> songsByArtist(nSongs);
	copy_if(songs.begin(), songs.end(), songsByArtist.begin(),
		[artist](const Song& s)
		{
			return s.getArtist() == artist;
		});

	for (auto s : songsByArtist)
		this->playList->add(s);
}

void Controller::startPlaylist()
{
	if (this->playList == nullptr)
		return;
	this->playList->play();
}

void Controller::nextSongPlaylist()
{
	if (this->playList == nullptr)
		return;
	this->playList->next();
}

void Controller::savePlaylist(const std::string& filename)
{
	if (this->playList == nullptr)
		return;

	this->playList->setFilename(filename);
	this->playList->writeToFile();
}

void Controller::openPlaylist() const
{
	if (this->playList == nullptr)
		return;

	this->playList->displayPlaylist();
}

void Controller::undo(){
    if(!undoHistory.empty()){
        undoHistory.back()->executeUndo();
        undoHistory.pop_back();
    } else {
        throw std::exception();
    }
}
