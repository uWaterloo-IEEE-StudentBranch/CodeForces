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

bool exist(vector<char> *vec, char c){
    if(c == '.') return true;
    for(unsigned int i = 0; i < vec->size(); i += 1){
        if(vec->at(i) == c) return true;
    }
    return false;
}

int main (int argc, char const* argv[]){

    int n, m;
    char pres;
    cin >> n >> m >> pres;

    char room[n][m];
    vector<char> deps;

    for(unsigned int i = 0; i < n; i += 1){
        for(unsigned int j = 0; j < m; j += 1){
            cin >> room[i][j];
        }
    }

    
    for(unsigned int i = 0; i < n; i += 1){
        for(unsigned int j = 0; j < m; j += 1){
            if(room[i][j] == pres){
                if(i > 0 && room[i-1][j] != pres && !exist(&deps, room[i-1][j])) deps.push_back(room[i-1][j]);
                if(i < n-1 && room[i+1][j] != pres && !exist(&deps, room[i+1][j])) deps.push_back(room[i+1][j]);
                if(j > 0 && room[i][j-1] != pres && !exist(&deps, room[i][j-1])) deps.push_back(room[i][j-1]);
                if(j < m-1 && room[i][j+1] != pres && !exist(&deps, room[i][j+1])) deps.push_back(room[i][j+1]);
            }
        }
    }
/*
    for(unsigned int i = 0; i < deps.size(); i += 1){
        cout << deps[i] << endl;
    }
*/    
    cout << deps.size() << endl;

    return 0;
}
