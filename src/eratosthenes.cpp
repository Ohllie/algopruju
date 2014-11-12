#include <cstdlib>
#include <cmath>

// Returns an array isPrime of length n+1 such that isPrime[x] = 1 if x is prime and 0 else
char* eratosthenes(int n){

    int m = (int) sqrt(n) + 1;
 
    char* isPrime = (char*)malloc((n+1)*sizeof(char));
    for(int i = 0; i <= n; i++) 
        isPrime[i] = (i <= 1) ? 0 : 1;

    for(int i = 2; i <= m; i++){
        if(isPrime[i]){
            for (int j = 2*i; j <= n; j += i){
                isPrime[j] = 0; 
            }
        }
    }
    return isPrime;
}
