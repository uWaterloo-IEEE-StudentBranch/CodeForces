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

    int a, b, c;
    cin >> a >> b >> c;

    if(a == 0){
        if(-c % b != 0) cout << "-1" << endl;
        else cout << "0 " << (-c/b) << endl;
        return 0;    
    }

    if(c % a == 0){
        cout << (-c/a) << " 0" << endl;
    }

    for(unsigned int i = 0; i < abs(pow((double)10, (double)9)/a); i += 1){
        if((-a*i - c) % b == 0){
            cout << i << " " << ((-a*i - c) / b)*i << endl;

            cout << a*i + ((-a*i - c) / b)*i*b + c << endl;
            return 0; 
        }
        else if((a*i - c) % b == 0){
            cout << -i << " " << ((a*i - c) / b)*-i << endl;

            cout << a*-i + ((a*i - c) / b)*-i*b + c << endl;
            return 0; 
        }
    }

    cout << "-1" << endl;

    return 0;
}
