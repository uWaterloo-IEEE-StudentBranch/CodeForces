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
#include <cctype>

using namespace std;

int main (int argc, char const* argv[]){

    string word;
    cin >> word;
    char ans[word.length()];
    
    if(islower(word[0]))
        ans[0] = toupper(word[0]);
    else
        ans[0] = tolower(word[0]);
    
    for(unsigned int i = 1; i < word.length(); i += 1){
        if( !isupper(word[i]) ){
            cout << word << endl;
            exit(0);
        }
        
        ans[i] = tolower(word[i]);
    }
    
    for(unsigned int i = 0; i < word.length(); i += 1)
        cout << ans[i];
    cout << endl;
    
    return 0;
}
