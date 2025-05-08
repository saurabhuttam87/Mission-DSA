#include <iostream>
#include <string>
using namespace std;
// Given a string s, the function substrings calculates the sum of all substrings of s.
long substrings(string s) {
    long total = 0, endRight = 0, mod = 1000000007;
    for (int i=0; i < s.size(); i++) {
        int k = s[i] - '0';
        endRight = (10*endRight + (i+1)*k) % mod;
        total = (total + endRight) % mod;
    }
    return total;
}