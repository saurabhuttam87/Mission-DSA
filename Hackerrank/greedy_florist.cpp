#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to calculate the minimum cost of flowers
int getMinimumCost(int k, vector<int> c) {
    int minCost = 0;

    if(k >= c.size()){
    for(auto cost: c){
       minCost += cost;
    }

   return minCost;
}

int prevPurchases = 0;
int tempFriendsCnt = k;
sort(c.begin(), c.end());

for(int i = c.size()-1; i >= 0; i--) {
   if(tempFriendsCnt == 0){
       tempFriendsCnt = k;
       prevPurchases++;
   }

   minCost += (prevPurchases + 1) * c[i];
   tempFriendsCnt--;
}

return minCost;
}