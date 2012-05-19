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

    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    
    double max_v_before;
    double t1, t2;
    double e = l - d;
    
    double v2 = sqrt(2*a*d + pow(w,2));
    
    //get t1
    if(v2 < v){
        //peak at v2
        max_v_before = v2;
        
        t1 = (v2/a) + (v2-w)/a;
    }
    else{
        //go to v for as long as possible
        max_v_before = v;
        double d11 = pow(v,2)/(2*a);
        
        t1 = (v/a) + (d-d11)/v;
    }
    
    cout << t1 << endl;
    
    //get t2
    double vf = sqrt(pow(w,2) + 2*a*e);
    if(vf > v){
        //v then stay at v
        double e11 = pow(v,2)/(2*a);
        
        t2 = (v/a) + (e-e11)/v;
    }
    else{
        //accel all the way
        t2 = vf/a;
    }

    cout << t2 << endl;
    
    double t = t1 + t2;
    
    cout << t << endl;
    
    return 0;
}
