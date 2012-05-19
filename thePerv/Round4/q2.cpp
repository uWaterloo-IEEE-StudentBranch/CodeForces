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

int sum(int* a, int s){
}

int main (int argc, char const* argv[]){

    int d, sumt;

    cin >> d >> sumt;

    int days[d];
    int min[d];
    int max[d];

    for(unsigned int i = 0; i < d; i += 1){
        cin >> min[i] >> max[i];
    }

    for(unsigned int i = 0; i < d; i += 1){
        days[i] = min[i];
        sumt -= min[i];
    }

    int remaining = 0;
    for(unsigned int i = 0; i < d; i += 1){
        remaining += max[i] - min[i];
    }

    if(sumt < 0 || sumt > remaining){
        cout << "NO" << endl;
        exit(0);
    }

    cout << "YES" << endl;
    
    for(unsigned int i = 0; i < d; i += 1){
        int diff = max[i] - min[i];
        if(sumt > diff){
            sumt -= diff;
            days[i] += diff;
        }
        else{
            days[i] += sumt;
            sumt = 0;
            break;
        }

        //cout << "sumt: " << sumt << endl;
    }

    //int res = 0;
    for(unsigned int i = 0; i < d; i += 1){
        //res += days[i];
        cout << days[i] << " ";
    }
    cout << endl;

    return 0;
}
