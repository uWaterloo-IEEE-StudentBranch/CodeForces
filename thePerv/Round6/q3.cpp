#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main (int argc, char const* argv[]){

    int n;
    cin >> n;

    int c[n];
    for(unsigned int i = 0; i < n; i += 1){
        cin >> c[i];
    }

    int a = 0;
    int b = n-1;

    int ac = 1;
    int bc = 1;

    int an = 0;
    int bn = 0;

    int loop = 0;
    while(a < b){
        loop++;
        
        if(ac == c[a]){
            a++;
            ac = 1;
            an++;

            //cout << "at loop: " << loop << " an++" << endl;
        }
        else{
            ac += 1;
        }

        if(bc == c[b]){
            b--;
            bc = 1;
            bn++;

            //cout << "at loop: " << loop << " bn++" << endl;
        }
        else{
            bc++;
        }
    }

    if(a == b){
        if(bc > ac){
            bn++;
        }
        else{
            an++;
        }
    }

    //cout << a << ", " << b << endl;

    cout << an << " " << bn << endl;

    return 0;
}
