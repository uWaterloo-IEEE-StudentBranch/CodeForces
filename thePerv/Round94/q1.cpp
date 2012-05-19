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
    
    int numbags;
    cin >> numbags;
    
    int bags[numbags];
    
    int sum = 0;
    for(unsigned int i = 0; i < numbags; i += 1){
        cin >> bags[i];
        sum += bags[i];
    }
    
    int ways = 0;
    for(unsigned int i = 0; i < numbags; i += 1){
        if(sum % 2 == 0){
            //even
            if(bags[i] % 2 == 0) ways++;
        }
        else{
            //odd
            if(bags[i] % 2 != 0) ways++;
        }
    }

    cout << ways << endl; 
    
    return 0;
}
