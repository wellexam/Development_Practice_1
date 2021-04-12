#include<algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include"obj.hpp"
using namespace std;

int main()
{
    
    int rows;
    double time;
    static int count = 0;
    static object data[1200000];
    string address1, address2, address;
    address1="DEM_TXT\\";
    address2 = ".txt";
    for (int i = 1; i <= 9;i++)
    {
        address = address1 + to_string(i) + address2;
        LARGE_INTEGER t1,t2,tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);

        readFile(address, data, count, i);
        
        QueryPerformanceCounter(&t2);
        time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
        cout<<"time = "<<time<<endl;  //输出时间（单位：ｓ）
    }
    sort(data, data + count);
    cout << "Input the number of the rows you want to display. " << endl;
    cin >> rows;
    for (int i = 0; i<rows; i++)
    {
        cout << data[i].pointid << ' '
             << fixed << setprecision(7)
             << data[i].grid_code << ' '
             << data[i].Lon << ' '
             << data[i].Lat << ' '
             << "From file " << data[i].position
             << endl;
    }
    return 0;
}