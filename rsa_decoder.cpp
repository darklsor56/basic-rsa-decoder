#include<iostream>
#include<array>
#include<cmath>

using std::cout;
using std::endl;

int main() {
    const int e = 7;              // Relatively prime with $\phi (n)$
    const int n = 4453;           // n = p * q
    const int m = 115;            // The number of characters in the message
    int p;                        // The prime number that makes up n
    int q;                        // The prime number that makes up n
    int phi;                      // $\phi (n) = (p-1)(q-1)$
    int M;                        // A decrypted node
    std::array<int, 16> primes = {7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};


    cout << "Hello! Alice has given us Bob's e and n values and she expects us to edcrypt Bob's message" << endl;
    cout << "in a reasonable amount of time with this program." << endl;
    cout << endl;
    cout << "First, let's get the prime numbers that make up n, the prime integers p and q..." << endl;
    cout << endl;

    // Iterate through the list of possible factors of prime numbers as shown earlier in LaTeX
    for(unsigned int i = 0; i < primes.size(); ++i) {
        if (n % primes[i] == 0) {
            p = primes[i];
            q = n / primes[i];
        }
    }
    return 0;
}
