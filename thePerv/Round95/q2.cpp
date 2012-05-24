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

    int numppl;
    map<int,long long> rank;
    long long res = 0;
    
    cin >> numppl;
    
    for(int i = -10; i <= 10; i += 1)
        rank[i] = 0;
    
    for(int i = 0; i < numppl; i += 1){
        int temp;
        cin >> temp;
        rank[temp]++;
    }
    
    for(int i = -10; i < 0; i += 1){
        int id = -i;
        res += rank[i] * rank[id];    
        //cout << "at: " << i << " res :" << res << endl;
    }
    
    res += (rank[0] - 1) * rank[0] / 2;
    
    //cout << "res :" << res << endl;
    
    //for(int i = -10; i <= 10; i += 1)
        //cout << rank[i] << endl;
        
    cout << res << endl;

    return 0;
}
