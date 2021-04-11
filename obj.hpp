#include<string>
#include <windows.h>
using namespace std;
class object
{
    public:
        int pointid;
        long double grid_code;
        long double Lon;
        long double Lat;
        int position;
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
            temp.position = a.position;
            return temp;
        }
};

void readFile(string, object*, int&, int);