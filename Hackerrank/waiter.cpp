#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;
vector<int> waiter(vector<int> number, int q) {
    
    vector<int> v{};
    stack<int> snumber;
    vector<int> output;
    
    for(auto a : number)
    {
        cout<<a<<" ";
        snumber.push(a);
    }
    auto getprimes =[](int q){
            deque<int> primes{};
            int num = 2;
            while (static_cast<int>(primes.size()) < q) {
                bool is_prime = true;
                for (int i = 2; i <= std::sqrt(num); ++i) {
                    if (num % i == 0) {
                        is_prime = false;
                        break;
                    }
                }
                if (is_prime) {
                    primes.push_back(num);
                }
                num++;
            }
            return primes;
    };
    deque<int> nprimes = getprimes(q);
    while (!nprimes.empty()) {
        int prime = nprimes.front();
        nprimes.pop_front();
            stack<int> a;
            stack<int> b;
            while(!snumber.empty())
            {
               int top = snumber.top();
               snumber.pop();
               if(top%prime==0)
                    b.push(top);
               else
                    a.push(top);
            }
            while(!b.empty())
            {
                int top = b.top();
                b.pop();
                output.push_back(top);
            }
            snumber=a;
    }
    
    while(!snumber.empty())
    {
        int top = snumber.top();
        snumber.pop();
        output.push_back(top);
    
    }
    return output;
}