#include "part.h"

Part::Part(const string myName, const int myPrice, const int myPowerConsumption, const string myDescription)
: name(myName), price(myPrice), powerConsumption(myPowerConsumption), description(myDescription) {}

string Part::getName() {
    return name;
}

CPU::CPU(const string myName, const int myPrice, const int myPowerConsumption, const string myDescription, const string mySocket, const int mySingleBenchmark, const int myMultiBenchmark, const int myVgaBenchmark)
    : Part(myName, myPrice, myPowerConsumption, myDescription) {
    socket = mySocket;
    cpuSingleBenchmark = mySingleBenchmark;
    cpuMultiBenchmark = myMultiBenchmark;
    vgaBenchmark = myVgaBenchmark;
}
string CPU::getSocket(){
    return socket;
}
void CPU::showName(){
    cout << getName() << endl;
}

VGA::VGA(const string myName, const int myPrice, const int myPowerConsumption, string myDescription, const string mySocket, const int myVgaBenchmark)
    : Part(myName, myPrice, myPowerConsumption, myDescription) {
    socket = mySocket;
    vgaBenchmark = myVgaBenchmark;
}
void VGA::showName(){
    cout << getName() << endl;
}

PowerSupply::PowerSupply(const string myName, const int myPrice, const string myDescription, const int mycapacity)
    : Part(myName, myPrice, 1, myDescription) {  // 전력 소모량( 기본 대기 전력 = 1 )
    capacity = mycapacity;
}
void PowerSupply::showName(){
    cout << getName() << endl;
}

RAM::RAM(const string myName, const int myPrice, const string myDescription, const int myCapacity)
    : Part(myName, myPrice, 2, myDescription) {   // 전력 소모량( 기본 대기 전력 = 2 )
    capacity = myCapacity;
}
void RAM::showName(){
    cout << getName() << endl;
}

SSD::SSD(const string myName, const int myPrice, const string myDescription, const int myCapacity)
    : Part(myName, myPrice, 3, myDescription) {   // 전력 소모량( 기본 대기 전력 = 3 )
    capacity = myCapacity;
}
void SSD::showName(){
    cout << getName() << endl;
}

HDD::HDD(const string myName, const int myPrice, const string myDescription, const int myCapacity)
    : Part(myName, myPrice, 15, myDescription) {  // 전력 소모량( 기본 대기 전력 = 15 )
    capacity = myCapacity;
}
void HDD::showName(){
    cout << getName() << endl;
}

Mainboard::Mainboard(const string myName, const int myPrice, const string myDescription, const string mySocket)
    : Part(myName, myPrice, 30, myDescription) {  // 전력 소모량( 기본 대기 전력 = 30 )
    socket = mySocket;
}
string Mainboard::getSocket(){
    return socket;
}
void Mainboard::showName(){
    cout << getName() << endl;
}
