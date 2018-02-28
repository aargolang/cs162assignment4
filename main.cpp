#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Song.h"
#include "LinkedList.h"

using namespace std;

char Song::songListFile_[] = "";

void DisplayMenu()
{
	// Output Menu for user
	cout << "Please make a selection:" << endl;
	cout << "a) Open a song file" << endl;
	cout << "b) Add a song" << endl;
	cout << "c) Delete a song" << endl;
	cout << "d) Play a song" << endl;
	cout << "e) Print all songs" << endl;
	cout << "f) Quit" << endl;
}

void LoadTextFile(LinkedList &list, char * filePath)
{
	// Loads data from text file linked list of objects
	ifstream inFile;
	Song *tempSong;
	char songPTH[500];
	char songNM[256];

	cout << "Enter the full file path: ";// get file path
	cin.ignore();
	cin.get(filePath, '\n');
	inFile.open(filePath);

	while (!inFile) { // if file dosn't exist
		cout << "go back to cs140!" << endl;
		cin.ignore();
		cin.get(filePath, 250);
		inFile.open(filePath);
	}
		
	strcpy(Song::songListFile_, filePath); // set filepath ## maybe not functioning ##

	while (!inFile.eof()) {
		// getlines from file, parse into path and name cstrings
		inFile.getline(songPTH, 500, '\n');

		strcpy(songNM, songPTH);
		char * pars = strtok(songNM, "\\");
		while (pars != NULL) {
			strcpy(songNM, pars);
			pars = strtok(NULL, "\\");
		}

		tempSong = new Song(songNM); // Set song name 
		tempSong->SetSongPath(songPTH); // Song path
		list.AddLinkToBack((Song*)tempSong); 
	}
	cout << "Loaded file and read " << list.GetListLength() << " Songs." << endl;
	inFile.close();
	inFile.clear(std::ios_base::goodbit);
}

void AddNewSong(LinkedList &list, char * filePath)
{
	// Manually enter information about Songs into new link in list

	if (list.GetListLength() == 0){ // display error if no songs are loaded from file
		cout << "Error... no songs loaded :(" << endl;
		return;
	}

	Song *tempSong;
	char songPTH[256];
	char songNM[256];
	char reply = '0';

	cout << "Enter the full song path and name: ";
	cin.ignore();
	cin.getline(songPTH, 256, '\n');

	strcpy(songNM, songPTH);
	char * pars = strtok(songNM, "\\");
	while (pars != NULL) {
		strcpy(songNM, pars);
		pars = strtok(NULL, "\\");
	}
	tempSong = new Song(songNM); // make a new song with the name that is returned from the GetName function
	tempSong->SetSongPath(songPTH); // Song path
	list.AddLinkToBack((Song*)tempSong); // add song to back of queue
	tempSong->AppendToListFile(); // Song path	
}

void DeleteSong(LinkedList &list) {
	// deletes a song from the list by the filename
	char songNM[256];
	char songCMP[256];
	bool deletedSong = false;
	Node *current;
	int i = 0;

	// get user input
	cout << "Please enter the song you wish to delete including file extension: ";
	cin.ignore();		
	cin.get(songNM, 256, '\n');
	
	// search list by the string: Song->data_->GetSongName
	current = ((Node*)list.GetFirstNode());
	while ((i < list.GetListLength()) && (deletedSong == false)) {
		strcpy(songCMP, ((Song*)current->data_)->GetSongName());
		if (strcmp(songCMP, songNM) == 0) { 
			// if current node.name is equal to songNM
			delete (Node*)list.RemoveThisLink(current);
			deletedSong = true;
		}
		else
			;
		current = current->next_;
		i++;
	}
}

void PlaySong(LinkedList &list) {
	// this function disaplays the song name and deletes the song from the list
	char songNM[256];
	char songCMP[256];
	bool playedSong = false;
	Node *current;
	int i = 0;

	cout << "Please enter the song you wish to play including file extension: ";
	cin.ignore();
	cin.get(songNM, 256, '\n');
	current = ((Node*)list.GetFirstNode());
	while ((i < list.GetListLength()) && (playedSong == false)) {
		strcpy(songCMP, ((Song*)current->data_)->GetSongName());
		if (strcmp(songCMP, songNM) == 0) {
			// if current node.name is equal to songNM
			cout << "playing " << songNM << endl;
			cout << "(this song will be removed from queue after it is finished)" << endl;
			delete (Node*)list.RemoveThisLink(current);
			playedSong = true;
		}
		else
			;
		current = current->next_;
		i++;
	}
}

void PrintAllSongData(LinkedList &list)
{
	// Print all Song data to console
	int i = 0;
	Node *current;
	current = ((Node*)list.GetFirstNode());
	while (i < list.GetListLength()) {
		cout << ((Song*)current->data_)->GetSongName() << endl;
		current = current->next_;
		i++;
	}
	cout << endl;
}

void ClearList(LinkedList &list)
{
	// clear list
	int i = 0;
	Node *current;

	current = ((Node*)list.GetFirstNode());
	while (current != 0) {
		delete (Node*)list.RemoveLinkFromFront();
		current = current->next_;
		i++;
	}
}

int main()
{
	// Main function (menu, list, filePath, etc)
	bool terminate = false;
	char selection;
	LinkedList list;
	char filePath[250] = "null";

	while (!terminate)
	{
		DisplayMenu();
		cout << "list length: " << list.GetListLength() << endl;
		cout << "intput selection: ";
		cin >> selection;
		cout << endl;

		if (tolower(selection) == 'a') { // Open song file
			ClearList(list);
			LoadTextFile(list, filePath);
		}
		else if (tolower(selection) == 'b') { // Add a song
			AddNewSong(list, filePath);
		}
		else if (tolower(selection) == 'c') { // Delete a song
			DeleteSong(list);
		}
		else if (tolower(selection) == 'd') { // Play a song
			PlaySong(list);
		}
		else if (tolower(selection) == 'e') { // Print song list
			PrintAllSongData(list);
		}
		else if (tolower(selection) == 'f') { // Quit 
			ClearList(list);
			terminate = true;
		}
		else {
			cout << "did not compute. better luck next time." << endl;
		}
	}
	return 0;
}
