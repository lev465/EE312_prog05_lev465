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

    songs = nullptr;
}

UtPod::UtPod(int size)
{
    if(size>MAX_MEMORY || size<=0){
        memSize=MAX_MEMORY;
    }
    else {
        memSize = size;
    }
    songs = nullptr;

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
    SongNode *previous=nullptr;
    while(temp!=nullptr){
        if(temp->s==s){     //song found, remove
           if(previous==nullptr){      //first song in list
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
    if(songs!=nullptr &&
       (listLength>2)) {
        SongNode *pt1=songs;
        SongNode *pt2=songs;
        int numSwaps = 5 * listLength;
        for (int i=0; i<numSwaps; i++){
            long offset1 = (rand()%listLength);
            long offset2 = (rand()%listLength);
            (pt1-offset1)->s.swap((pt2-offset2)->s);
        }
    }
}

void UtPod::showSongList()
{
    SongNode *temp=songs;
    while(temp!=nullptr){
        cout << temp->s.getName() << ", "<< temp->s.getArtist() << ", " << temp->s.getSize() << "MB" << endl;
        temp=temp->next;
    }
}

void UtPod::sortSongList()
{
    int listLength=numSongs();

    if(listLength>2) {
        SongNode *ptr1 = songs;

        while(ptr1!= nullptr) {
            SongNode *ptr2 = ptr1->next;
            while (ptr2 != nullptr) {
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
    while(songs!=nullptr){
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
    while(temp!=nullptr){
        count= count + temp->s.getSize();
        temp=temp->next;
    }
    return getTotalMemory()-count;
}

int UtPod::numSongs(){
    int count=0;
    SongNode *temp=songs;
    while(temp!=nullptr){
        count= count+1;
        temp=temp->next;
    }
    return count;
}

UtPod::~UtPod()
{
    cout<<"debug in UtPod destructor - "<<this<<endl;
}