#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include"obj.hpp"
using namespace std;

int main()
{
    static int count = 0;
    static object data[1200000];
    readFile("DEM_TXT\\1.txt", data, count);
    sort(data, data + count);
    for (int i = 0; i<20; i++)
    {
        cout << data[i].pointid << ' '
             << fixed << setprecision(7)
             << data[i].grid_code << ' '
             << data[i].Lon << ' '
             << data[i].Lat << endl;
    }
    return 0;
}