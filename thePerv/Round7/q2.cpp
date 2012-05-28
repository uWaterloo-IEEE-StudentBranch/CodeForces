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

    int t, m;
    cin >> t >> m;

    string cmd;
    int mem[m];

    for(unsigned int i = 0; i < m; i += 1){
        mem[i] = m - i;
        //cout << mem[i] << endl;
    }

    //int->free, -1->head, 0->body
    for(unsigned int i = 0; i < t; i += 1){
        cin >> cmd;
        int p;
        
        if(cmd == "alloc"){
            cin >> p;
            for(unsigned int a = 0; a < m; a += 1){
                if(mem[a] >= p){
                    mem[a] = -1;
                    for(unsigned int z = 0; z < p-1; z += 1){
                        mem[a+z+1] = 0;
                    }
                }
            }
        }
        else if(cmd == "erase"){
            cin >> p;
        }
        else{   //defrag
        }
    }

    return 0;
}
