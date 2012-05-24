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

unsigned long long choose(unsigned long long n, unsigned long long k){
     if (k > n)
         return 0;
     unsigned long long r = 1;
     for (unsigned long long d = 1; d <= k; ++d){
         r *= n--;
         r /= d;
     }
     return r;
}

int main (int argc, char const* argv[]){

    unsigned long long res = 0;
    int n, m ,t;
    cin >> n >> m >> t;
    
    int k = max(n-4, m-1);
    if(k == 0) k++;
    
    //cout << "k: " << k << endl;
    
    for(unsigned int i = 0; i <= k; i += 1){
    
        //cout << n << " " << 4+i << ", " << m << " " << t-(4+i) << endl;
        //cout << choose(n, 4+i) << endl;
        //cout << choose(m, t-(4+i)) << endl;
        
        if(t-(4+i) < 1) continue;
        
        res += choose(n, 4+i) * choose(m, t-(4+i));
    }    

    cout << res << endl;

    return 0;
}
