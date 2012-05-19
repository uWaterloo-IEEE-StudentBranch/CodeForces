#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main (int argc, char const* argv[]){

    int w;
    cin >> w;

    if(w > 2 && w % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
