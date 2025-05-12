#include <iostream>
#include <vector>

class Solution {
    
private:
    
    std::vector<bool> primes;
    int mx;

private:
    
    void sieve() {
        primes[0] = primes[1] = false;
        
        for (int i = 2; i * i < mx; ++i) {
            if (!primes[i]) continue;
            for (int j = i * i; j < mx; j += i) primes[j] = false;
        }
    }
    
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        
        primes.resize(n, true);
        mx = n;
        
        sieve();
        
        int cnt = 0;
        
        for (int i = 2; i < n; ++i) {
            if (primes[i]) cnt++;
        }
        
        return cnt;
    }
    
    
};