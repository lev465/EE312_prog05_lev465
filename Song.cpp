/*Song.cpp
Luis Vazquez, Roger Priebe
EE312 04/03/20

This is the Song class.
*/

#include "Song.h"

#include <utility>
#include <string>
#include<iostream>

using namespace std;

Song::Song()
{
    name="";
    artist="";
    size=MIN_SIZE;
}

Song::Song(string name)
{
    this->name=name;
    artist="";
    size=MIN_SIZE;
}

Song::Song(string name, string artist)
{
    this->name=name;
    this->artist=artist;
    size=MIN_SIZE;
}

Song::Song(string name, string artist, int size)
{
    this->name=name;
    this->artist=artist;
    this->size=size;
}

string Song::getName() const
{
    return name;
}

string Song::getArtist() const
{
    return artist;
}

int Song::getSize() const
{
    return size;
}

void Song::setName(string n)
{
    name = n;
}

void Song::setArtist(string artist)
{
    this->artist=artist;
}

void Song::setSize(int s)
{
    size=s;
}

void Song::swap(Song &s2)
{
    Song temp = s2;
    s2=*this;
    *this=temp;
}

bool Song::operator ==(Song const &rhs)
{
    return (name==rhs.name &&
            artist==rhs.artist &&
            size==rhs.size);
}

bool Song::operator <(Song const &rhs)
{
    if(artist<rhs.artist) {
        return true;
    }
    else if(name<rhs.name&&
            artist==rhs.artist) {
        return true;
    }
    else if(size<rhs.size &&
            artist==rhs.artist &&
            name==rhs.name) {
        return true;
    }
    else {
        return false;
    }
}

bool Song::operator >(Song const &rhs)
{
    if(artist>rhs.artist) {
        return true;
    }
    else if(name>rhs.name &&
            artist==rhs.artist) {
        return true;
    }
    else if(size>rhs.size &&
            artist==rhs.artist &&
            name==rhs.name) {
        return true;
    }
    else {
        return false;
    }
}

Song& Song::operator=(const Song &rhs){
    artist=rhs.artist;
    name=rhs.name;
    return *this;
}

Song::~Song(){
}