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

    int n, m, a;
    
    cin >> n >> m >> a;
    
    if(m > n){
        int temp = n;
        n = m;
        m = temp;
    }
    
    int lt = ceil((double)(n)/(double)(a));
    int st = ceil((double)(m)/(double)(a));
    
    cout << lt*st << endl;

    return 0;
}