/* utPod_driver.cpp
Driver for the UtPod.
Luis Vazquez
EE 312 04/03/20

This is a driver for the UtPod.

*/

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    int result;
    //SongList
    Song s1("Back in Black", "AC/DC", 4);
    Song s2("Enter Sandman", "Metallica", 25);
    Song s3("Hey Jude", "Beatles", 5);
    //try default constructor
    Song s4;
    s4.setName("The Twist");
    s4.setArtist("Chubby Checker");
    s4.setSize(8);

    Song s5("Smooth");
    s5.setArtist("Santana");
    s5.setSize(12);

    Song s6("Uptown Funk","Bruno Mars");
    s6.setSize(20);

    Song s7("Party Rock Anthem", "LMFAO", 20);
    Song s8("Imagine", "John Lennon", 30);
    Song s9("Sweet Child O'Mine", "Guns N' Roses", 35);
    Song s10("Hotel California","The Eagles", 30);


    //Attempt to add more songs than memory could hold - attempted to add 9, could only hold 8
    UtPod pod1(32);
    for(int i=0; i<9;i++) {
        result = pod1.addSong(s1);
    }
    cout << "\nLast add attempt result = " << result << endl;
    pod1.showSongList();
    pod1.showNumSongs();


    UtPod t;

    cout<<"UtPod t"<<endl;
    result = t.addSong(s1);
    result = t.addSong(s2);
    result = t.addSong(s3);
    result = t.addSong(s4);
    result = t.addSong(s5);
    result = t.addSong(s6);
    result = t.addSong(s7);
    result = t.addSong(s8);
    result = t.addSong(s9);
    result = t.addSong(s10);
    cout << "\nLast add attempt result = " << result << endl;

    UtPod t2(t);    //copy constructor

    t.showSongList();
    t.showNumSongs();

    cout <<"\n\nShuffle"<<endl;
    t.shuffle();
    t.showSongList();
    t.showNumSongs();

    cout<< "\n\nSort List"<<endl;
    t.sortSongList();
    t.showSongList();

    t.addSong(s5);
    cout<< "\n\nSort List - multiple instances of same song\n"<<endl;
    t.sortSongList();
    t.showSongList();
    cout<<"\nTotal Memory in UtPod - "<<t.getTotalMemory()<<endl;
    cout<<"Remaining Memory in UtPod - "<<t.getRemainingMemory()<<endl;


    cout<<"\n\nDelete First Song in List\n"<<endl;
    t.removeSong(s1);
    t.showSongList();
    t.showNumSongs();

    cout<<"\n\nDelete Last Song in List\n"<<endl;
    t.removeSong(s10);
    t.showSongList();
    t.showNumSongs();

    cout<<"\n\nClear Memory"<<endl;
    t.clearMemory();
    t.showSongList();
    t.showNumSongs();
    cout<<"Total Memory in UtPod - "<<t.getTotalMemory()<<endl;
    cout<<"Remaining Memory in UtPod - "<<t.getRemainingMemory()<<endl;

    result = t.addSong(s5);
    cout << "\nadd result = " << result << endl;
    cout<<"Utpod t1 - "<<endl;
    t.showSongList();
    t.showNumSongs();

    cout<<"Utpod t2 - Copy Constructor"<<endl;
    t2.showSongList();
    t2.showNumSongs();

    UtPod t3;
    t3=t;
    cout<<"Utpod t3 - Copy Assignment Operator"<<endl;
    t3.showSongList();
    t3.showNumSongs();
}