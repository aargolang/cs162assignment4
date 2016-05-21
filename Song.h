#define _CRT_SECURE_NO_WARNINGS
#ifndef Song_H
#define Song_H
#include "LinkedList.h"
#include <cstring>
	
// make static character array size
const int ENTRY_SZ = 512;
	
class Song
{
private:
	char songPath_[ENTRY_SZ];   // Contains the full path name
	char songName_[ENTRY_SZ];   // Song name extracted from the path

public:
	// Store the path name of the song list file
	static char songListFile_[ENTRY_SZ];
	static char currentMP3_[ENTRY_SZ];

	// Member functions
	Song();
	Song(char * nm);
	~Song();
	void SetSongPath(char * path);
	const char * GetSongName();
	void AppendToListFile();
	void PlaySong();
	void StopSong();
};	
#endif