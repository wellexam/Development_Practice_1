#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

class object
{
    public:
        int pointid;
        long double grid_code;
        long double Lon;
        long double Lat;
        friend bool operator > (const object &a, const object &b)
        {
            return a.grid_code < b.grid_code;
        }
        friend bool operator < (const object &a, const object &b)
        {
            return a.grid_code > b.grid_code;
        }
        friend bool operator == (const object &a, const object &b)
        {
            return a.grid_code == b.grid_code;
        }
        friend bool operator != (const object &a, const object &b)
        {
            return a.grid_code != b.grid_code;
        }
        friend object operator - (const object &a, const object &b)
        {
            object temp;
            temp.grid_code = a.grid_code - b.grid_code;
            temp.pointid = a.pointid;
            temp.Lon = a.Lon;
            temp.Lat = a.Lat;
            return temp;
        }
};



int main()
{
    static object data[120000];
    fstream in;
    char head[256];
    in.open("DEM_TXT\\2.txt", ios::in);
    in.getline(head, 256, '\n');
    int count = 0;
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
        // long double digit;
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
        // if(count >= 100)
        // {
        //     break;
        // }
    }
    count--;
    sort(data, data + count);
    for (int i = 0; i<20; i++)
    {
        cout << data[i].pointid << ' '
             << fixed << setprecision(7)
             << data[i].grid_code << ' '
             << data[i].Lon << ' '
             << data[i].Lat << endl;
    }
    cout << fixed << setprecision(7)
         << "LatMax == " << LatMax << " "
         << "LatMin == " << LatMin << " "
         << "LonMax == " << LonMax << " "
         << "LonMin == " << LonMin << endl;
    in.close();
    return 0;
}