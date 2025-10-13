#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

# Problem: Next Prime (https://cses.fi/problemset/task/3396/)

# Prerequisite:
-> Prime Numbers, Divisors, Sieve

# Main Idea:
-> There is not a large gap between prime numbers. The number of prime numbers from 1 to n is given by π(n) - prime counting function.
-> And π(n) = n / log(n), since there are many prime number and their count increases as we go further. So we can start from n + 1
   and keep going until we found the prime number(p > n). 
-> For checking prime number we can check all numbers from 1 to sqrt(n) or we can use sieve of Erastosthenes to get all the prime numbers from 1 to 1e6
   and since n <= 1e12, so we can efficiently check if the number is prime or not just by checking the divisibility with these primes from 1 to 1e6. 

- is_prime_1 : This function is implemented using square root solution
- precompute : it computes all the primes from 1 to 1e6 and return the prime vector
- is_prime_2 : Uses sieve to check if the number is prime or not.

Complexties:
If we use square root method -
    1. Time Complexity: O(t * sqrt(n) * k)
    2. Space Commplexity: O(1)
If we use sieve method:
    1. Time Complexity: O(N(log(log(N))) + t * (N / log(N) * k)), where N = 1e6
    2. Space Commplexity: O(N / log(N))

And approximately k can be upto 600 for numbers <= 1e6
*/

/// Checks if the given number is prime or not. Uses sqaure root method to check.
/// TC: O(sqrt(n))
/// @return true if number is prime or false  
bool is_prime_1(ll number) {
    if (number == 2 || number == 3) {
        return true;
    }
    if (number < 2 || number % 2 == 0 || number % 6 % 4 != 1) {
        return false;
    }
 
    for (ll i = 3; 1LL * i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

/// Function to generate prime numbers.
/// @return All prime numbers from 1 to 1e6
vector<ll> precompute() {
    const int N = 1e6 + 1;
    vector<ll> primes;
    bool is_prime[N];
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back((ll) i);
            for (ll j = 1LL * i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

/// Checks if the number is prime or not. Uses generated primes to check the primality.
/// @return true if number is prime or false
bool is_prime_2(ll number, vector<ll>& primes) {
    if (number == 2 || number == 3) {
        return true;
    }
    if (number < 2 || number % 2 == 0 || number % 6 % 4 != 1) {
        return false;
    }

    for (ll prime: primes) {
        if (prime == number) {
            return true;
        }
        if (number % prime == 0) {
            return false;
        }
    }
    return true;
}

/// Function to solve one testcase
void solve() {
    ll n;
    cin >> n;

    ll next_prime = n + 1;
    while (!is_prime_1(next_prime)) {
        next_prime++;
    }
    cout << next_prime << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}
