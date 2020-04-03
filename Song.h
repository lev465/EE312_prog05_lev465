//
// Created by Luis Vazquez Delgado on 3/18/20.
//

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {

private:
    string name;
    string artist;
    int size;

    static const int MIN_SIZE=1;

public:
    Song();
    Song(string name);
    Song(string name, string artist);
    Song(string name, string artist, int size);

    string getName() const;
    void setName(string n);

    string getArtist() const;
    void setArtist(string artist);

    int getSize() const;
    void setSize(int s);

    void swap(Song &s);

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);

    ~Song();
    
};


#endif //SONG_H
