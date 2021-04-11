#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include"obj.hpp"
using namespace std;

void readFile(string address, object * data, int &count)
{
    fstream in;
    char head[256];
    in.open(address, ios::in);
    in.getline(head, 256, '\n');
    int id;
    char comma;
    long double digit;

    in >> id;
    in >> comma;//逗号
    in >> id;
    data[count].pointid = id;
    in >> comma;//逗号
    in >> digit;
    data[count].grid_code = digit;
    in >> comma;//逗号
    in >> digit;
    data[count].Lon = digit;
    in >> comma;//逗号
    in >> digit;
    data[count].Lat = digit;

    long double LatMax=data[count].Lat, LatMin=data[count].Lat, LonMax=data[count].Lon, LonMin=data[count].Lon;
    count++;

    while(!in.eof())
    {
        in >> id;
        in >> comma;//逗号

        in >> id;
        data[count].pointid = id;

        in >> comma;//逗号

        in >> digit;
        data[count].grid_code = digit;

        in >> comma;//逗号

        in >> digit;
        data[count].Lon = digit;

        in >> comma;//逗号

        in >> digit;
        data[count].Lat = digit;

        if(LatMax<data[count].Lat)
        {
            LatMax=data[count].Lat;
        }
        if(LatMin>data[count].Lat)
        {
            LatMin=data[count].Lat;
        }
        if(LonMax<data[count].Lon)
        {
            LonMax=data[count].Lon;
        }
        if(LonMin>data[count].Lon)
        {
            LonMin=data[count].Lon;
        }

        count++;
    }
    count--;
    cout << fixed << setprecision(7)
         << "LatMax == " << LatMax << " "
         << "LatMin == " << LatMin << " "
         << "LonMax == " << LonMax << " "
         << "LonMin == " << LonMin << endl;
    in.close();
    return;
}