#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

string convertInt(int number){
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

int main (int argc, char const* argv[]){

    map<string,int> mymap;

    int numppl;
    cin >> numppl;

    for(unsigned int i = 0; i < numppl; i += 1){
        string n;
        cin >> n;

        map<string,int>::iterator it;
        it = mymap.find(n);

        if(it == mymap.end()){
            mymap.insert( pair<string,int>(n,0) );
            cout << "OK" << endl;
        }
        else{
            it->second++;
            cout << n.append(convertInt(it->second)) << endl;
        }
    }

    return 0;
}
