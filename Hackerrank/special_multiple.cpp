#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
// Function to find the smallest multiple of n that consists only of the digits 0 and 9
string solve(int n) {
    long long i = 2;
    long long k = 9;
    while (k % n != 0 || k < n){
        bitset<16> b(i);
        k = stol(b.to_string())*9;
        i++;
    }
    return to_string(k);
}