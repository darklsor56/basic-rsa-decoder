#include<iostream>
#include<array>
#include<cmath>
#include<string>

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

bool findFactors(int n, int& p, int& q) {
    // Check 2 first
    if(n % 2 == 0) {
        p = 2;
        q = n / 2;
        return true;
    }
    int limit = sqrt(n) + 1;

    // Now only check odd numbers
    for(unsigned int i = 3; i <= limit; i = i + 2) {
        if(n % i == 0) {
            p = i;
            q = n / i;
            return true;
        }
    }
    return false;
}

int main() {
    int e = 7;              // Relatively prime with $\phi (n)$
    int n = 4453;           // n = p * q
    int m = 115;            // The number of characters in the message
    int p = 0;                        // The prime number that makes up n
    int q = 0;                        // The prime number that makes up n
    int phi = 0;                      // $\phi (n) = (p-1)(q-1)$
    int M;                        // A decrypted node
    std::array<int, 115> tempM = {1400, 2218, 99, 2970, 2218, 2962, 3015, 99, 871, 843,
        3780, 843, 84, 2218, 2269, 2218, 1443, 2962, 99, 84,
        843, 1655, 2979, 99, 843, 3015, 2382, 447, 4191, 871,
        2218, 2962, 1294, 2916, 99, 843, 84, 843, 1655, 2979,
        99, 871, 2218, 3237, 843, 99, 2269, 1443, 3237, 843,
        4242, 1443, 3015, 2979, 99, 871, 2382, 1655, 2962, 2269,
        99, 1443, 2962, 99, 871, 2088, 843, 99, 2269, 843,
        871, 1691, 99, 2218, 99, 1294, 1443, 99, 2218, 2962,
        871, 1443, 99, 871, 2088, 843, 99, 1443, 871, 2088,
        843, 1655, 99, 1655, 1443, 1443, 3237, 99, 4191, 2962,
        3015, 99, 1655, 843, 4191, 3015, 99, 4191, 99, 4242,
        1443, 1443, 3629, 2916, 1400};
    // n is probably randomized... AAAAAAHHHHH
    //std::array<int, 18> primes = {2, 3, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};


    //cout << "Hello! Alice has given us Bob's e and n values and she expects us to edcrypt Bob's message" << endl;
    //cout << "in a reasonable amount of time with this program." << endl;
    //cout << endl;
    //cout << "First, let's get the prime numbers that make up n, the prime integers p and q..." << endl;
    //cout << endl;

    // Iterate through the list of possible factors of prime numbers as shown earlier in LaTeX
    

    if(!findFactors(n, p, q)) {
        throw std::runtime_error("ERROR: Failed to find p or q");
        return 1;
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
        throw std::runtime_error("ERROR: given e is not invertable suggesting public key is not valid!");
        return 1;
    }

    cout << "d = " << d << endl;

    std::string message = "";

    

    return 0;
}
