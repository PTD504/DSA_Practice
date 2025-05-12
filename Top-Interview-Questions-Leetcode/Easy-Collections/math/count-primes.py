class Solution:
    def __init__(self):
        self.mx = None
        self.primes = []
    
    def __sieve(self):
        self.primes = [True for i in range(self.mx)]
        
        self.primes[0] = self.primes[1] = False
        
        i = 2
        
        while i * i < self.mx:
            if self.primes[i] == False:
                i += 1
                continue
            
            for j in range(i * i, self.mx, i):
                self.primes[j] = False
            
            i += 1
        
    def countPrimes(self, n: int) -> int:
        self.mx = n
        
        if n < 2:
            return 0
        
        self.__sieve()
        
        cnt = 0
        
        for i in range(2, n):
            if self.primes[i]:
                cnt += 1
        
        return cnt
        