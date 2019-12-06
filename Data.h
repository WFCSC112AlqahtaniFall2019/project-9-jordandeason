#ifndef PROJECT9_DATA_H
#define PROJECT9_DATA_H
#include "Data.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Data {
    //public function declarations
    //public variable declarations
public:
    //constructors
    Data();
    Data(int PRECINCT, int JURISDICTIONCODE,int XCOORD, int YCOORD);
    //variables
    int PRECINCT;
    int JURISDICTIONCODE;
    int XCOORD;
    int YCOORD;

    friend ostream& operator << (ostream& os, const Data& data);//friend

    //comparison operators
    bool operator > (Data& d);
    bool operator < (Data& d);
    bool operator <= (Data& d);
    bool operator >= (Data& d);
    Data& operator = (Data& d1);

    void setPRECINCT(int pr){PRECINCT=pr;};//not used
    void setJURISDICTIONCODE(int ju){JURISDICTIONCODE=ju;};//not used
    void setXCOORD(int xc){XCOORD=xc;};//not used
    void setYCOORD(int yc){YCOORD=yc;};//not used
    int getPRECINCT(){return PRECINCT;};//not used
    int getJURISDICTIONCODE(){return JURISDICTIONCODE;};// used
    int getXCOORD(){return XCOORD;};//not used
    int getYCOORD(){return YCOORD;};//not used

    //no private function or variable declarations
private:
};
#endif //PROJECT9_DATA_H