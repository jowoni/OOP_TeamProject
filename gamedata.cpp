#include "gamedata.h"

GameData::GameData(const string gamename, int minram, int mincpu, int minvga, int proram, int procpu, int provga) {
    name = gamename;
    minRam = minram;
    minCpu = mincpu;
    minVga = minvga;
    properRam = proram;
    properCpu = procpu;
    properVga = provga;
}

string GameData::getName(){
    return name;
}
