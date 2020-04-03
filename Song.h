/*Song.h
Luis Vazquez, Roger Priebe
EE312 04/03/20

This is the Song class.
*/

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

//Song class declaration
class Song {

private:
    string name;
    string artist;
    int size;

    static const int MIN_SIZE=1;        //songs will have minimum size of 1

public:
    //Default constructor
    //set song size to MIN_SIZE, artist and name are empty
    Song();

    //Constructor with name parameter
    //set name for song, size to MIN_SIZE
    //artist will be empty
    Song(string name);

    //Constructor with name and artist parameter
    //set name and artist for song, size to MIN_SIZE
    Song(string name, string artist);

    //Constructor with name, artist and size
    //name, artist, and size of song set to values passed
    Song(string name, string artist, int size);


    /* FUNCTION - string getName
     *  returns the name of the song

    input parms - none

    output parms - name of the song
    */
    string getName() const;


    /* FUNCTION - setName
     *  changes the name of the song

    input parms - name of song

    output parms - none
    */
    void setName(string n);


    /* FUNCTION - string getArtist
     *  returns the name of the artist for the song

    input parms - none

    output parms - artist of the song
    */
    string getArtist() const;


    /* FUNCTION - setArtist
     *  changes the name of the artist

    input parms - artist name

    output parms - none
    */
    void setArtist(string artist);


    /* FUNCTION - getSize
     *  returns the size of the song

    input parms - none

    output parms - size of the song
    */
    int getSize() const;


    /* FUNCTION - setSize
     *  changes the size of the song

    input parms - size of song

    output parms - none
    */
    void setSize(int s);


    /* FUNCTION - swap
     *  changes the contents of two songs - name, artist, and string

    input parms - song to swap current song with

    output parms - none
    */
    void swap(Song &s);


    /* OPERATOR - >
     *  Compares songs to determine order.
     * Compares the contents of the song by order of
     *      artist, name, size
     *

    input parms - song to compare current song to

    output parms - true if current song is higher in order than song passed in parameter
    */
    bool operator >(Song const &rhs);


    /* OPERATOR - <
     *  Compares songs to determine order.
     * Compares the contents of the song by order of
     *      artist, name, size
     *

    input parms - song to compare current song to

    output parms - true if current song is lower in order than song passed in parameter
    */
    bool operator <(Song const &rhs);


    /* OPERATOR - ==
     *  Compares songs to determine if they're the same.
     * Compares the contents of the song by order of
     *      artist, name, size
     *

    input parms - song to compare current song to

    output parms - true if current song is the same as the song passed in parameter
    */
    bool operator ==(Song const &rhs);


    //Copy assignment operator
    Song& operator =(Song const &rhs);

    ~Song();

};


#endif //SONG_H
