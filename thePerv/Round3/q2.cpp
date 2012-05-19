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

class vech{
public:
    int id;
    int type;
    int cap;
};

    vector<vech> lorry;
    vector<vech> final;
    
int biggest(int type){
    int max = 0;
    int id = -1;
    for(unsigned int i = 0; i < lorry.size(); i += 1){
        if(lorry[i].type == type && lorry[i].cap > max){
            max = lorry[i].cap;
            id = i;
        }
    }
    return id;
}

int main (int argc, char const* argv[]){

    int numt, cap;
    cin >> numt >> cap;

    for(unsigned int i = 0; i < numt; i += 1){
        vech temp;
        cin >> temp.type >> temp.cap;
        temp.id = i + 1;
        lorry.push_back(temp);
    }

    int total = 0;

    if(cap % 2){    //fill biggest kayak first
        int id = biggest(1);
        final.push_back(lorry[id]);
        total += lorry[id].cap;
        lorry.erase(lorry.begin() + id);
    }

    for(unsigned int i = 0; i < (cap/2); i += 1){
        int sum1, sum2;
        int id11, id12, id21;
        
        id11 = biggest(1);
        vech temp = lorry[id11];
        lorry.erase(lorry.begin() + id11);
        id12 = biggest(1);
        id21 = biggest(2);

        if(id21 != -1){
            sum1 = temp.cap;
            if(id12 != -1) sum1 += lorry[id12].cap;
            
            sum2 = lorry[id21].cap;
            if(sum1 > sum2){
                final.push_back(temp);
                if(id12 != -1) final.push_back(lorry[id12]);

                total += temp.cap;
                if(id12 != -1) total += lorry[id12].cap;
                
                lorry.erase(lorry.begin() + id12);
            }
            else{
                lorry.push_back(temp);
                final.push_back(lorry[id21]);

                total += lorry[id21].cap;
                
                lorry.erase(lorry.begin() + id21);
            }
        }
        else{
            final.push_back(temp);
            if(id12 != -1) final.push_back(lorry[id12]);
            
            total += temp.cap;
            if(id12 != -1) total += lorry[id12].cap;    
                    
            if(id12 != -1) lorry.erase(lorry.begin() + id12);
        }
        
    }

    cout << total << endl;

    for(unsigned int i = 0; i < final.size(); i += 1){
        cout << final[i].id << endl;
    }

    return 0;
}
