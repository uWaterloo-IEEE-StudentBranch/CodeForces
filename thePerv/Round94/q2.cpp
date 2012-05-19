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

    int n, m;
    cin >> n >> m;
    
    int lace[m][2];
    int stu[n];
    int stu_new[n];
    
    for(unsigned int i = 0; i < n; i += 1){
        stu[i] = 0;
        stu_new[i] = 0;
    }
    
    for(unsigned int i = 0; i < m; i += 1){
        cin >> lace[i][0] >> lace[i][1];
        stu[lace[i][0]-1]++;
        stu[lace[i][1]-1]++;
        stu_new[lace[i][0]-1]++;
        stu_new[lace[i][1]-1]++;
    }
    
    bool kicked = true;
    int kicknum = 0;
    
    for(unsigned int z = 0; z < n; z += 1){
        kicked = false;
    
        //cout << "######round#: " << z << endl;
        
        bool counted = false;
        
        for(unsigned int i = 0; i < m; i += 1){
            bool kick1 = false;
            bool kick2 = false;
            
            //cout << "lace#: " << i << endl;
            
            if(lace[i][0] != -1){
                if(stu[lace[i][0]-1] == 1){
                    kick1 = true;
                    
                    //cout << lace[i][0] << " kicked" << endl;
                    
                }
                if(stu[lace[i][1]-1] == 1){
                    kick2 = true;
                    
                    //cout << lace[i][1] << " kicked" << endl;
                    
                }
            }
            
            if(kick1){
                stu[lace[i][0]-1] = -1;
                stu_new[lace[i][1]-1]--;
            }
            if(kick2){
                stu[lace[i][1]-1] = -1;
                stu_new[lace[i][0]-1]--;
            }
            
            kicked = kick1 | kick2;
            if(kicked){
                lace[i][0] = -1;
                lace[i][1] = -1;
                if(!counted){
                    //cout << "kicked a round" << endl;
                    counted = true;
                    kicknum++;
                }
            }
        }

        for(unsigned int i = 0; i < n; i += 1){
            stu[i] = stu_new[i];
        }
    }
    
    cout << kicknum << endl;
    
    //cout << kicknum << endl;
    
    /*
    for(unsigned int i = 0; i < n; i += 1){
        cout << stu[i] << endl;
    }
    
    /*
    for(unsigned int i = 0; i < m; i += 1){
        cout << lace[i][0] << " " << lace[i][1] << endl;;
    }
    */

    return 0;
}
