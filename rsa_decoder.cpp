#include<iostream>
#include<array>
#include<cmath>

using std::cout;
using std::endl;

// Inverse Check
int modularInverse(int e, int phi) {
    int t = 0, new_t = 1;       // coefficients for e for backtracking
    int r = phi, new_r = e;     // Renainders
    
    while (new_r != 0) {
        int quotient = r / new_r;

        int temp = new_t;
        new_t = t - quotient * new_t;
        t = temp;

        temp = new_r;
        new_r = r - quotient * new_r;
        r = temp;
    }

    if (r > 1) {
        return -1; // e is not invertible
    }
    if (t < 0) {
        t += phi;
    }
    return t;
}

int main() {
    const int e = 7;              // Relatively prime with $\phi (n)$
    const int n = 4453;           // n = p * q
    const int m = 115;            // The number of characters in the message
    int p = 0;                        // The prime number that makes up n
    int q = 0;                        // The prime number that makes up n
    int phi = 0;                      // $\phi (n) = (p-1)(q-1)$
    int M;                        // A decrypted node
    std::array<int, 18> primes = {2, 3, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};


    //cout << "Hello! Alice has given us Bob's e and n values and she expects us to edcrypt Bob's message" << endl;
    //cout << "in a reasonable amount of time with this program." << endl;
    //cout << endl;
    //cout << "First, let's get the prime numbers that make up n, the prime integers p and q..." << endl;
    //cout << endl;

    // Iterate through the list of possible factors of prime numbers as shown earlier in LaTeX
    for(unsigned int i = 0; i < primes.size(); ++i) {
        if (n % primes[i] == 0) {
            p = primes[i];
            q = n / primes[i];
            break; // Once we find p and q, stop the loop
        }
    }

    if(p == 0 || q == 0) {
        std::runtime_error("ERROR: Failed to find p or q");
    }

    cout << "p = " << p << ", q = " << q << endl;
    //cout << "Now let's compute phi(n)" << endl;
    //cout << endl;

    phi = (p-1)*(q-1);

    cout << "phi(n) = " << phi << endl;
    //cout << "Now let's compute d such that d*e congruent to 1 mod 4320"

    // Use the Extended Euclidean Algorithm or Brute Force!
    int d = modularInverse(e, phi);
    if(d == -1) {
        std::runtime_error("ERROR: given e is not invertable suggesting public key is not valid!");
    }

    cout << "d = " << d << endl;

    return 0;
}
