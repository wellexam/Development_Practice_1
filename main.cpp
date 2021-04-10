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
        static long double LatMax, LatMin, LonMax, LonMin;
        // static bool ValueCmp(object const &a, object const &b)
        // {
        //     return a.grid_code > b.grid_code;
        // }
        // friend bool operator > (const object &a, const object &b)
        // {
        //     return a.grid_code > b.grid_code;
        // }
        // friend bool operator == (const object &a, const object &b)
        // {
        //     return a.grid_code == b.grid_code;
        // }
        // friend bool operator != (const object &a, const object &b)
        // {
        //     return a.grid_code != b.grid_code;
        // }
        // friend object operator - (const object &a, const object &b)
        // {
        //     object temp;
        //     temp.grid_code = a.grid_code - b.grid_code;
        //     temp.pointid = a.pointid;
        //     temp.Lon = a.Lon;
        //     temp.Lat = a.Lat;
        //     return temp;
        // }
};



int main()
{
    static object data[120000];
    fstream in;
    char head[256];
    in.open("DEM_TXT\\1.txt", ios::in);
    in.getline(head, 256, '\n');
    int count = 0;
    int id;
    char trash;
    while(!in.eof())
    {
        long double digit;
        in >> id;
        in >> trash;

        in >> id;
        data[count].pointid = id;
        // cout << data[count].pointid<< ' ';

        in >> trash;
        in >> digit;
        data[count].grid_code = digit;
        // cout << digit << " ";
        std::cout << std::fixed << std::setprecision(7) << data[count].grid_code<< ' ';

        in >> trash;
        in >> digit;
        data[count].Lon = digit;
        // cout << data[count].Lon<< ' ';

        in >> trash;
        in >> digit;
        data[count].Lat = digit;
        // cout << data[count].Lat<< endl;

        count++;
        if(count >= 100)
        {
            break;
        }
    }
    count--;
    cout << endl;
    sort(data[0], data[count],
          [](object const & a, object const & b) -> bool
          { return a.grid_code < b.grid_code; } );
    for (int i = 0; i<count; i++)
    {
        cout << data[i].pointid<< ' ';
        cout << fixed << setprecision(7) << data[i].grid_code<< ' ';
        cout << data[i].Lon<< ' ';
        cout << data[i].Lat<< endl;
    }
    in.close();
    return 0;
}