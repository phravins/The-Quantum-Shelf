#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    // Special case: K = 0 means all permutations are valid
    if (K == 0) {
        cout << factorial(N) << '\n';
        return 0;
    }
    
    // If N <= 2K+1, it's impossible to have a valid arrangement
    if (N <= 2 * K + 1) {
        cout << 0 << '\n';
        return 0;
    }
    
    // For larger N, we use DP with bitmask
    // dp[mask][last] = number of ways to arrange artifacts in 'mask' ending with 'last'
    // CRITICAL FAILURE POINT FOR N=60: (1 << 60) is too large.
    vector<vector<int>> dp(1 << N, vector<int>(N, 0));
    
    // Initialize: single artifact arrangements
    for (int i = 0; i < N; i++) {
        dp[1 << i][i] = 1;
    }
    
    // Fill DP table
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int last = 0; last < N; last++) {
            if ((mask & (1 << last)) == 0) continue;
            if (dp[mask][last] == 0) continue;
            
            for (int next = 0; next < N; next++) {
                if (mask & (1 << next)) continue;
                
                // Check if |(last+1) - (next+1)| > K
                if (abs((last + 1) - (next + 1)) > K) {
                    int new_mask = mask | (1 << next);
                    dp[new_mask][next] = (dp[new_mask][next] + dp[mask][last]) % MOD;
                }
            }
        }
    }
    
    // Sum all valid permutations using all artifacts
    int full_mask = (1 << N) - 1;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + dp[full_mask][i]) % MOD;
    }
    
    cout << ans << '\n';
    return 0;
}
