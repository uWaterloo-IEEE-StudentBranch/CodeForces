#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main (int argc, char const* argv[]){

    string str;
    int x1, y1, x2, y2;     //A# , col row
    
    cin >> str;
    x1 = str[0] - 'a' + 1;
    y1 = str[1] - '0';
    cin >> str;
    x2 = str[0] - 'a' + 1;
    y2 = str[1] - '0';

    bool farx;
    int hi, lo;
    if(abs(x2-x1) > abs(y2-y1)){
        hi = abs(x2-x1);
        lo = abs(y2-y1);
        farx = true;
    }
    else{
        hi = abs(y2-y1);
        lo = abs(x2-x1);
        farx = false;
    }

    char dirx, diry;
    if(x2-x1 > 0) dirx = 'R';
        else dirx = 'L';
    if(y2-y1 < 0) diry = 'D';
        else diry = 'U';

    cout << hi << endl;

    for(unsigned int i = 0; i < lo; i += 1){
        cout << dirx << diry << endl;
    }

    for(unsigned int i = lo; i < hi; i += 1){
        if(farx) cout << dirx << endl;
            else cout << diry << endl;
    }

    return 0;
}
