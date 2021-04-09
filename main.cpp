#include<algorithm>
#include<iostream>
#include<fstream>
// #include<string>
using namespace std;

class object
{
    public:
        int pointid;
        double grid_code;
        double Lon;
        double Lat;
};

int main()
{
    object data[120000];
    fstream in;
    char head[256];
    in.open("DEM_TXT\\1.txt", ios::in);
    in.getline(head, 256, '\n');
    int count = 0;
    int id;
    double digit;
    char trash;
    while(!in.eof())
    {
        in >> id;
        in >> trash;
        in >> id;
        data[count].pointid = id;
        cout << data[count].pointid<< ' ';
        in >> trash;
        in >> digit;
        data[count].grid_code = digit;
        cout << digit << " ";
        cout << data[count].grid_code<< ' ';
        in >> trash;
        in >> digit;
        data[count].Lon = digit;
        cout << data[count].Lon<< ' ';
        in >> trash;
        in >> digit;
        data[count].Lat = digit;
        cout << data[count].Lat<< endl;
        count++;
        if(count >= 100)
        {
            break;
        }
    }
    in.close();
    return 0;
}