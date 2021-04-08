#include<algorithm>
#include<iostream>
#include<fstream>
// #include<string>
using namespace std;

class object
{
    int OBJECTID;
    int pointid;
    float grid_code;
    float Lon;
    float Lat;
};

int main()
{
    fstream in;
    char temp[256];
    in.open("\\DEM_TXT\\1.txt", ios::in);
    while(!in.eof())
    {
        in.getline(temp, 256, '\n');
        cout << temp << endl;
    }
    in.close();
    return 0;
}