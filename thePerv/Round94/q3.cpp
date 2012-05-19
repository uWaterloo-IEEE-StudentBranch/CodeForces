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

    string str;
    int k;
    cin >> str >> k;
    
    vector<string> subsets;
    
    for(unsigned int i = 0; i < str.length(); i += 1){
        string subject = str.substr(i);
        
        for(unsigned int j = 0; j < subject.length(); j += 1){
            subsets.push_back(subject.substr(0,j+1));
        }
    }

    sort(subsets.begin(), subsets.begin() + subsets.size());

    /*
    for(unsigned int i = 0; i < subsets.size(); i += 1){
        cout << subsets[i] << endl;
    }
    */
    
    cout << subsets[k-1] << endl;


    return 0;
}
