cmake_minimum_required(VERSION 3.14)
project(sem5)

set(CMAKE_CXX_STANDARD 14)

add_executable(sem5 main.cpp Controller.cpp Controller.h CSVPlaylist.cpp FilePlaylist.cpp FilePlaylist.h PlayList.cpp PlayList.h Repository.cpp Repository.h RepositoryExceptions.cpp RepositoryExceptions.h Song.cpp Song.h SongValidator.cpp SongValidator.h UI.h UI.cpp Utils.cpp Utils.h CSVPlaylist.h UndoAction.cpp UndoAction.h UndoAdd.cpp UndoAdd.h UndoRemove.cpp UndoRemove.h)