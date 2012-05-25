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

    int s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];

    int res = 0;

    for(unsigned int i = 0; i < 4; i += 1){
        int s1 = s[i % 4];
        int s2 = s[(i+1) % 4];
        int s3 = s[(i+2) % 4];

        //make s3 longest
        if(s1 > s2){
            int temp = s2;
            s2 = s1;
            s1 = temp;
        }
        if(s2 > s3){
            int temp = s3;
            s3 = s2;
            s2 = temp;
        }
    
        if(s3 < s1 + s2){
            res = 2;
        }
        else if(s3 == s1 + s2 && res != 2){
            res = 1;
        }

        //cout << res << endl;
        //cout << s1 << " " << s2 << " " << s3 << endl;
    }

    if(res == 2)
        cout << "TRIANGLE" << endl;
    else if(res == 1)
        cout << "SEGMENT" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
