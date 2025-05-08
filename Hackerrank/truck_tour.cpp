#include <iostream>
#include <vector>
using namespace std;
// The function truckTour takes a vector of petrol pumps, each represented by a vector of two integers.
int truckTour(vector<vector<int>> petrolpumps) {
    int balance,deficit,start=1;
    
    for(int i =0;i<petrolpumps.size();i++){
        balance += petrolpumps[i][0] - petrolpumps[i][1];
    
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    if(balance + deficit >= 0){
        return start;
    }
    return -1;
}