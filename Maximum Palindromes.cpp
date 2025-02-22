#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX_N = 100005;
const int ALPHA = 26;

int fact[MAX_N], ifact[MAX_N];
int freq[MAX_N][ALPHA];

// Function to compute factorials and inverse factorials using modular arithmetic
int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2) result = 1LL * result * base % mod;
        base = 1LL * base * base % mod;
        exp /= 2;
    }
    return result;
}

void precomputeFactorials() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        ifact[i] = power(fact[i], MOD - 2, MOD);  // Using Fermat's Little Theorem
    }
}

// Function to preprocess frequency of each character in the string
void initialize(string s) {
    memset(freq, 0, sizeof(freq));
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ALPHA; j++)
            freq[i + 1][j] = freq[i][j];  // Copy previous frequencies
        freq[i + 1][s[i] - 'a']++;       // Update frequency of current character
    }
}

// Function to answer queries
int answerQuery(int l, int r) {
    l--; r--;  // Convert to zero-based index

    vector<int> count(ALPHA);
    int odd_count = 0, half_sum = 0;

    for (int i = 0; i < ALPHA; i++) {
        count[i] = freq[r + 1][i] - freq[l][i];  // Get character count in substring
        if (count[i] % 2) odd_count++;
        half_sum += count[i] / 2;
    }

    // Compute the number of distinct maximum-length palindromes
    int num_ways = fact[half_sum];
    for (int i = 0; i < ALPHA; i++) {
        if (count[i] / 2 > 0) {
            num_ways = 1LL * num_ways * ifact[count[i] / 2] % MOD;
        }
    }

    return num_ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int q;
    cin >> s >> q;

    precomputeFactorials();  // Precompute factorials and inverse factorials
    initialize(s);  // Precompute frequency table

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << answerQuery(l, r) << "\n";
    }

    return 0;
}

