#include <iostream>
#include <vector>
#include <set>
using namespace std;
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    vector<pair<int, int>> directions = {
        {-1,  0}, {1,  0}, {0, -1}, {0,  1}, 
        {-1, -1}, {-1,  1}, {1, -1}, {1,  1}
    };

    set<pair<int, int>> obs;
    for (auto& o : obstacles) {
        obs.insert({o[0], o[1]});
    }

    int attackableSquares = 0;

    for (auto& dir : directions) {
        int r = r_q + dir.first;
        int c = c_q + dir.second;
        
        while (r >= 1 && r <= n && c >= 1 && c <= n && obs.find({r, c}) == obs.end()) {
            attackableSquares++;
            r += dir.first;
            c += dir.second;
        }
    }

    return attackableSquares;
}