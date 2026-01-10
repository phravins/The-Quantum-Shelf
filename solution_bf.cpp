#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    if (N > 11) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> p(N);
    iota(p.begin(), p.end(), 1);
    long long count = 0;
    long long MOD = 1e9 + 7;
    do {
        bool ok = true;
        for (int i = 0; i < N - 1; ++i) {
            if (abs(p[i] - p[i+1]) <= K) {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    } while (next_permutation(p.begin(), p.end()));
    
    cout << count % MOD << endl;
    return 0;
}
