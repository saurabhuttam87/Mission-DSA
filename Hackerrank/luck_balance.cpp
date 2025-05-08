#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to calculate the maximum luck balance
int luckBalance(int k, vector<vector<int>> contests) {
    sort(contests.begin(), contests.end(), [](vector<int> l, vector<int>r){
        return l[0] > r[0];
    });
    int ans = 0, im = 0;
    for(int i = 0; i < contests.size(); i++){
        if(im < k || contests[i][1] == 0) ans += contests[i][0];
        else ans -= contests[i][0];
        if(contests[i][1] == 1) im++;
    }
    return ans;
}