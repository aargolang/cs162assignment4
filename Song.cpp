#include "Song.h"
#include <iostream>
#include <fstream>
using namespace std;

//char Song::songListFile_[] = "";

// Constructors
Song::Song() {
	strcpy(songName_, "0");
}	
Song::Song(char * nm) {
	strcpy(songName_, nm);
}
Song::~Song() {
}

// Getters and setter functions
const char* Song::GetSongName(){
	return songName_;
}

// Utility functions
void Song::SetSongPath(char* path) {
	strcpy(songPath_, path);
}
void Song::AppendToListFile() {
	ofstream file;
	file.open(songListFile_, ios::ate | ios::app);
	file << "\n" << songPath_;
	file.close();
	file.clear(std::ios_base::goodbit);
}
void Song::PlaySong() {
	
}
void Song::StopSong() {

}