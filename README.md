# cs162assignment4

I just remember being told that these are super duper important.

anyways this is a doubly linked list assignment that is supposed to be a queue for a mock mp3 playr

when loading from a text file use "songs.txt" or "Text.txt". only the "songs" with the shorter file paths will be deleted properly. 

* issues

- delete function dosn't compare song names properly if the songPTH is too long. 


* note:
I know that this is not a proper implementation of an actual queue since things arent really deleted from the front but they are searched and picked out by filename. This is the finctionality that my professor wants this thing to have. 

# issue description

// user input:

a
songs.txt

// now the linked list is populated with objects created from the data in the txt file

e

// this will display the songs in the 

c
Skream - Exothermic Reaction.mp3

// this should delete that link in the list
// when there is an exact match it should disaply "deleting song..."
// theres some odd things i was doing in orer to try to debug the program

e

// this should show that the song is still in the list but in g++ its not taking for some reason 

