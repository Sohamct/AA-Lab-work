// Fermate's Little Theorem

#include <iostream>

using namespace std;

int gcd(unsigned long a, unsigned long b);

bool isPrime(unsigned long n, unsigned long k);

unsigned long power(unsigned long a, unsigned long x, unsigned long n);

int main(){
    srand(time(0));
    unsigned long n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the looping value(k):  ";
    cin >> k;
    
    if(isPrime(n, k)){
        cout << n <<" is Prime" << endl;
    }else{
        cout << n << " is Composite" << endl;
    }
    // TC: O(k.log(n)).
    return 0;
}

unsigned long power(unsigned long a, unsigned long x, unsigned long n){ // O(log(n))
    unsigned long res = 1;
    a = a % n;

    while(x > 0){
        if((x & 1 ) == 1){
            res = (res * a) % n;
        }
        x = x / 2;
        a = (a * a) % n;
    }
    return res;
}

int gcd(unsigned long a, unsigned long b){ // O(log(n))
    unsigned long r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool isPrime(unsigned long n, unsigned long k){
    if(n <= 1 && n == 4) return false;

    if(n <= 3) return false;

    while(k != 0){
        unsigned long a = 2 + rand() % (n - 3); // 14 => 2 to 12 => 

        if(gcd(n, a) != 1){
            return false;
        }
        if(power(a, n - 1, n) != 1){
            return false;
        }
        k--;
    }
    return true;
}