//UtPod.cpp
//

#include "UtPod.h"
#include <ctime>
using namespace std;

UtPod::UtPod()
{
    memSize=MAX_MEMORY;
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
}

UtPod::UtPod(int size)
{
    if(size>MAX_MEMORY || size<=0){
        memSize=MAX_MEMORY;
    }
    else {
        memSize = size;
    }

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
    if(songs!=NULL &&
       (numSongs()>2)) {
        SongNode *pt1=songs;
        SongNode *pt2=songs;
        for (int i=0; i<20; i++){
            long offset1 = (rand()%numSongs());
            long offset2 = (rand()%numSongs());
            (pt1-offset1)->s.swap((pt2-offset2)->s);
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

}

void UtPod::clearMemory()
{
    while(songs!=NULL){
        removeSong(songs->s);
        songs=songs->next;
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

UtPod::~UtPod()
{
    cout<<"debug in UtPod destructor - "<<this<<endl;
}