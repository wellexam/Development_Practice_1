#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include"obj.hpp"
using namespace std;

void readFile(string address, object * data, int &count, int pos)
{
    int id, begin = count;
    char comma, head[256];
    long double digit;
    fstream in;
    in.open(address, ios::in);
    in.getline(head, 256, '\n');

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
    data[count].position = pos;

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

        data[count].position = pos;//来自的文件位置

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
         << "File" << pos << " : "
         << "LatMax == " << LatMax << " "
         << "LatMin == " << LatMin << " "
         << "LonMax == " << LonMax << " "
         << "LonMin == " << LonMin << endl;
    sort(data + begin, data + count);
    for (int i = begin; i<begin+20; i++)
    {
        cout << data[i].pointid << ' '
             << fixed << setprecision(7)
             << data[i].grid_code << ' '
             << data[i].Lon << ' '
             << data[i].Lat << ' '
             << endl;
    }
    in.close();
    return;
}