/*UtPod.cpp
Luis Vazquez, Roger Priebe
EE312 04/03/20

This is the UtPod class.
*/

#include "UtPod.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

UtPod::UtPod()
{
    memSize=MAX_MEMORY;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);

    songs = NULL;
}


UtPod::UtPod(int size)
{
    if(size>MAX_MEMORY || size<=0){
        memSize=MAX_MEMORY;
    }
    else {
        memSize = size;
    }
    songs = NULL;

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}


int UtPod::addSong(const Song &s)
{
    if(s.getSize() <= getRemainingMemory()){
        SongNode *temp=new SongNode;
        temp->s=s;
        temp->next=songs;
        songs=temp;            //change head of list to newest song
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}


int UtPod::removeSong(const Song &s)
{
    SongNode *temp=songs;
    SongNode *previous=NULL;
    while(temp!=NULL){
        if(temp->s==s){     //song found, remove
           if(previous==NULL){      //first song in list
               songs=songs->next;   //change head to new
               delete temp;
               return SUCCESS;
           }
           else{                    //song is in between two songs
               previous->next=temp->next;
               delete temp;
               return SUCCESS;
           }
        }
        previous=temp;
        temp=temp->next;
    }
    return NOT_FOUND;
}


void UtPod::shuffle()
{
    int listLength = numSongs();
    if(songs!=NULL &&
       (listLength>2)) {
        SongNode *pt1;
        SongNode *pt2;
        int numSwaps = 5 * listLength;
        for (int i=0; i<numSwaps; i++){
            pt1=songs;
            pt2=songs;
            long offset1 = (rand()%listLength);
            long offset2 = (rand()%listLength);

            while(offset1!=0) {
                pt1 = pt1 ->next;
                offset1--;
            }

            while(offset2!=0){
                pt2=pt2->next;
                offset2--;
            }

            pt1->s.swap(pt2->s);
        }
    }
}


void UtPod::showSongList()
{
    SongNode *temp=songs;
    while(temp!=NULL){
        cout << temp->s.getName() << ", "<< temp->s.getArtist() << ", " << temp->s.getSize() << "MB" << endl;
        temp=temp->next;
    }
}


void UtPod::sortSongList()
{
    int listLength=numSongs();

    if(listLength>2) {
        SongNode *ptr1 = songs;

        while(ptr1!= NULL) {
            SongNode *ptr2 = ptr1->next;
            while (ptr2 != NULL) {
                if (ptr1->s > ptr2->s) {
                    (ptr1->s).swap(ptr2->s);
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }

}


void UtPod::clearMemory()
{
    while(songs!=NULL){
        removeSong(songs->s);
    }
}


int UtPod::getTotalMemory() {
    return memSize;
}


int UtPod::getRemainingMemory()
{
    int count = 0;
    SongNode *temp=songs;
    while(temp!=NULL){
        count= count + temp->s.getSize();
        temp=temp->next;
    }
    return getTotalMemory()-count;
}


int UtPod::numSongs(){
    int count=0;
    SongNode *temp=songs;
    while(temp!=NULL){
        count= count+1;
        temp=temp->next;
    }
    return count;
}

void UtPod::showNumSongs()
{
    cout<<"Number of songs in UtPod - "<< numSongs()<<"\n"<<endl;
}

//copy constructor
UtPod::UtPod(const UtPod& t)
{
    SongNode *temp=t.songs;
    songs= NULL;
    while(temp!=NULL){
        memSize=t.memSize;
        this->addSong(temp->s);
        temp=temp->next;
    }
}

//copy assignment operator
UtPod& UtPod::operator=(const UtPod &t){
    if(this!= &t){
        SongNode *temp=t.songs;
        delete this->songs;
        memSize=t.memSize;
        songs=NULL;
        while(temp!=NULL) {
            this->addSong(temp->s);
            temp = temp->next;
        }
    }
    return *this;
}

UtPod::~UtPod()
{
    clearMemory();
}