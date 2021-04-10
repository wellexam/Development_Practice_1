#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<vector>
// #include<string>
using namespace std;

class object
{
    public:
        int pointid;
        long double grid_code;
        long double Lon;
        long double Lat;
    static bool ValueCmp(object const & a, object const & b)
    {
        return a.grid_code < b.grid_code;
    }
        // bool operator < (const object &m)const
        // {
        //     return grid_code < m.grid_code;
        // }
        // bool operator > (const object &m)const
        // {
        //     return grid_code > m.grid_code;
        // }
        // bool operator == (const object &m)const
        // {
        //     return grid_code == m.grid_code;
        // }
        // bool operator != (const object &m)const
        // {
        //     return grid_code != m.grid_code;
        // }
        // long double operator - (const object &m)const
        // {
        //     return grid_code - m.grid_code;
        // }
};

bool cmp_grid_code(object a, object b)
{
    return a.grid_code > b.grid_code;
}

bool cmp_Lon(object a, object b)
{
    return a.Lon > b.Lon;
}

bool cmp_Lat(object &a, object &b)
{
    return a.Lat > b.Lat;
}

int main()
{
    static object data[120000];
    fstream in;
    char head[256];
    in.open("DEM_TXT\\1.txt", ios::in);
    in.getline(head, 256, '\n');
    int count = 0;
    int id;
    // long double digit;
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
    sort(data[0], data[count], object::ValueCmp);
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