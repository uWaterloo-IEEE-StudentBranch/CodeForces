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
    int max = 0;
    vector<string> text;
    vector<string> res;
    bool right = false;
    
    while(getline(cin,str)){
        text.push_back(str);
        if(str.length() > max) max = str.length();
        
    }
    
    string margin = string(max+2, '*');
    res.push_back(margin);
    
    for(unsigned int i = 0; i < text.size(); i += 1){
        string temp = string("*");
        int l = max;
        int modifier = 0;
        
        if( (l - text[i].length()) % 2 != 0){
            if(right){
                l++;
                modifier = -1;
                right = false;
            }
            else{
                right = true;
                modifier = 1;
            }
        }
        
        int sides = (l - text[i].length()) / 2;
        temp.append( string(sides, ' ') );
        temp.append( text[i] );
        temp.append( string(sides + modifier, ' ') );
        temp.append( string("*") );
        
        res.push_back(temp);
    }

    res.push_back(margin);

    for(unsigned int i = 0; i < res.size(); i += 1){
        cout << res[i] << endl;
    }

    return 0;
}
