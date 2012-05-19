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
    cin >> str;
    
    vector<int> lefts;
    int left = 0;
    int max = 0;
    int count = 0;
    int cur = 0;
    
    for(unsigned int i = 0; i < str.length(); i += 1){
        
        //cout << "[" << i << ", " << cur << "]" << endl;
    
        if(str[i] == '('){
            //left
            left++;
            lefts.push_back(i);
        }
        else{
            //right
            left--;
            if(left >= 0) lefts.pop_back();
            
            if(left < 0){
                //end seq
                if(cur > max){
                    max = cur;
                    count = 0;
                }
                if(cur == max){
                    count++;
                }
                
                //cout << "cur " << cur << " at " << i << endl;
                
                left = 0;
                cur = 0;
            }
            else{
                //good
                cur += 2;
            }
        }
    }
    
    //cout << max << " " << count << endl;
    //cout << "left over " << cur << endl;
    //cout << lefts.size() << endl;
    
    //wrap up
    if(lefts.size() == 0){
        if(cur > max){
            max = cur;
            count = 0;
        }
        if(cur == max){
            count++;
        }
    }
    else{
        lefts.push_back(str.length());
        
        for(unsigned int i = 1; i < lefts.size(); i += 1){
            cur = lefts[i] - lefts[i-1] - 1;
            
            //cout << lefts[i] << " " << lefts[i-1] << " " << cur << endl;
            
            if(cur > max){
                max = cur;
                count = 0;
            }
            if(cur == max){
                count++;
            }
        }
    }
    //decision
    if(max == 0){
        cout << "0 1" << endl;
    }
    else{
        cout << max << " " << count << endl;
    }
        
    return 0;
}
