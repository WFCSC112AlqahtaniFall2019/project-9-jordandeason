//
// Created by Jordan Deason on 12/2/19.
//
#include "Data.h"
#include<iostream>
#include<string>
using namespace std;
//constructors below
Data::Data() {
    int PRECINCT = 0; //precinct
    int JURISDICTIONCODE = 0; //jurisdiction code
    int XCOORD = 0; //x coordinate
    int YCOORD = 0;// y coordinate
}
Data::Data(int pr, int ju, int xc, int yc){
    PRECINCT = pr;
    JURISDICTIONCODE = ju;
    XCOORD = xc;
    YCOORD = yc;
}
//comparison operators
bool Data::operator > (Data& d){
    return JURISDICTIONCODE > d.getJURISDICTIONCODE();
}
bool Data::operator < (Data& d){
    return JURISDICTIONCODE < d.getJURISDICTIONCODE();
}
bool Data::operator <= (Data& d){
    return JURISDICTIONCODE <= d.getJURISDICTIONCODE();
}
bool Data:: operator >= (Data& d){
    return JURISDICTIONCODE >= d.getJURISDICTIONCODE();
}

Data& Data::operator = (Data& d1){
    Data temp(d1);
    //swap function calls below
    swap(temp.PRECINCT,PRECINCT);
    swap(temp.JURISDICTIONCODE,JURISDICTIONCODE);
    swap(temp.XCOORD,XCOORD);
    swap(temp.YCOORD,YCOORD);
    return *this;
}
ostream& operator<<(ostream& os, const Data data){
    os << "PRECINCT: " << data.PRECINCT << "  JURISDICTION CODE: " << data.JURISDICTIONCODE << "  X COORDINATE: " << data.XCOORD << "  Y COORDINATE: " << data.YCOORD << endl;
    return os;
}