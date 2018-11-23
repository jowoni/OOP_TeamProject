#ifndef GAMEDATA_H
#define GAMEDATA_H
#include <string>
using namespace std;

class GameData {
private:
    string name;
    int minRam;
    int minCpu;
    int minVga;
    int properRam;
    int properCpu;
    int properVga;
public:
    GameData(const string gamename, int minram, int mincpu, int minvga, int proram, int procpu, int provga);
    string getName();
};

#endif // GAMEDATA_H
