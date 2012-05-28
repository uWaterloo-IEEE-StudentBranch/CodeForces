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

    char b[8][8];
    bool col_painted[8] = {false};

    for(unsigned int i = 0; i < 8; i += 1){
        for(unsigned int j = 0; j < 8; j += 1){
            cin >> b[i][j];
        }
    }

    int numStroke = 0;

    for(unsigned int i = 0; i < 8; i += 1){
        int numB = 0;
        bool col_temp[8] = {false};
        
        for(unsigned int j = 0; j < 8; j += 1){
            if(b[i][j] == 'B'){
                col_temp[j] = true;
                numB++;
            }
        }

        if(numB == 8){
            numStroke++;
        }
        else{
            for(unsigned int z = 0; z < 8; z += 1){
                if(!col_painted[z] && col_temp[z]){
                    col_painted[z] = true;
                    numStroke++;
                }
            }
        }
    }

    cout << numStroke << endl;
    
    return 0;
}
