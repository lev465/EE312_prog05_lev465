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
    UtPod t;
    Song s2("Beatles", "Hey Jude2", 5);
    int result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s1("Beatles", "Hey Jude1", 4);
    result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    cout<< "\n\nthis is BEFORE the shuffle"<<endl;

    t.showSongList();

    t.shuffle();

    cout <<"\n\nthis is after"<<endl;
    t.showSongList();

    t.sortSongList();
    cout<< "\n\nTHIS IS AFTER SORTING"<<endl;
    t.showSongList();

    t.clearMemory();
    t.showSongList();
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;


}