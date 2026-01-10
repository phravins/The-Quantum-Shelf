#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MAXN = 65;
const int MAXK = 9;
const ll MOD = 1e9 + 7;
struct State {
    int deg[8];
    int comp[8];

    ll encode(int K) const {
        ll res = 0;
        ll d_part = 0;
        for(int i=0; i<K; ++i) d_part |= ((ll)deg[i] << (2*i));
        ll c_part = 0;
        int map_c[16];
        memset(map_c, -1, sizeof(map_c));
        int next_id = 0;
        for(int i=0; i<K; ++i) {
            int c = 0;
            if (deg[i] > 0) {
                if (map_c[comp[i]] == -1) map_c[comp[i]] = next_id++;
                c = map_c[comp[i]] + 1;
            }
            c_part |= ((ll)c << (4*i));
        }
        return (c_part << 16) | d_part;
    }

    void decode(ll val, int K) {
        ll d_part = val & 0xFFFF;
        ll c_part = val >> 16;
        for(int i=0; i<K; ++i) {
            deg[i] = (d_part >> (2*i)) & 3;
            comp[i] = (c_part >> (4*i)) & 0xF;
        }
    }
};

map<ll, vll> dp[MAXN]; 
ll fact[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, K;
    if (!(cin >> N >> K)) return 0;
    State start;
    memset(start.deg, 0, sizeof(start.deg));
    memset(start.comp, 0, sizeof(start.comp));
    map<ll, vll> cur_dp;
    cur_dp[start.encode(K)] = vll(1, 1);

    for (int i = 0; i < N; ++i) {
        map<ll, vll> next_dp;
        
        for (auto& [enc, counts] : cur_dp) {
            State s; s.decode(enc, K);
            vi neighbors;
            for(int j=0; j<K; ++j) if(s.deg[j] < 2) neighbors.push_back(j);

            {
                State ns;
                for(int x=K-1; x>0; --x) { ns.deg[x] = s.deg[x-1]; ns.comp[x] = s.comp[x-1]; }
                ns.deg[0] = 0; 
                ns.comp[0] = 15; 
                
                ll nenc = ns.encode(K);
                vll &target = next_dp[nenc];
                if(target.empty()) target.resize(N+1, 0);
                for(size_t k=0; k<counts.size(); ++k) target[k] = (target[k] + counts[k]) % MOD;
            }

            for(int neigh : neighbors) {
                State ns;
                for(int x=K-1; x>0; --x) { ns.deg[x] = s.deg[x-1]; ns.comp[x] = s.comp[x-1]; }
                
                ns.deg[neigh+1]++;
                ns.deg[0] = 1;
                
                ns.comp[0] = ns.comp[neigh+1];
                
                ll nenc = ns.encode(K);
                vll &target = next_dp[nenc];
                if(target.empty()) target.resize(N+1, 0);
                for(size_t k=0; k<counts.size(); ++k) 
                    if(k+1 <= N) target[k+1] = (target[k+1] + counts[k]) % MOD;
            }
            
            for(size_t a=0; a<neighbors.size(); ++a) {
                for(size_t b=a+1; b<neighbors.size(); ++b) {
                    int n1 = neighbors[a], n2 = neighbors[b];
                    
                    if (s.comp[n1] == s.comp[n2] && s.comp[n1] != 0) continue; // Cycle check

                    State ns;
                    for(int x=K-1; x>0; --x) { ns.deg[x] = s.deg[x-1]; ns.comp[x] = s.comp[x-1]; }
                    
                    ns.deg[n1+1]++; 
                    ns.deg[n2+1]++;
                    ns.deg[0] = 2; 

                    int c1 = ns.comp[n1+1];
                    int c2 = ns.comp[n2+1];
                    if (c1 == 0) c1 = 14; 
                    if (c2 == 0) c2 = 13;

                    ns.comp[0] = c1;
                    
                    for(int x=1; x<K; ++x) {
                        if(ns.comp[x] == c2 || ns.comp[x] == 13) ns.comp[x] = c1;
                    }
                    if(c1 == 14) { 
                        for(int x=0; x<K; ++x) if(ns.comp[x]==14) ns.comp[x]=15; 
                    }

                    ll nenc = ns.encode(K);
                    vll &target = next_dp[nenc];
                    if(target.empty()) target.resize(N+1, 0);
                    for(size_t k=0; k<counts.size(); ++k)
                        if(k+2 <= N) target[k+2] = (target[k+2] + counts[k]) % MOD;
                }
            }
        }
        cur_dp = move(next_dp);
    }
    vector<ll> C(N+1, 0);
    for(auto& [enc, counts] : cur_dp) {
        for(size_t k=0; k<counts.size(); ++k) C[k] = (C[k] + counts[k]) % MOD;
    }
    
    fact[0] = 1;
    for(int i=1; i<=N; ++i) fact[i] = (fact[i-1]*i) % MOD;
    
    ll ans = 0;
    for(int k=0; k<N; ++k) {
        if(C[k] == 0) continue;
        ll term = (C[k] * fact[N-k]) % MOD;
        if(k & 1) ans = (ans - term + MOD) % MOD;
        else ans = (ans + term) % MOD;
    }
    cout << ans << endl;
    return 0;
}
