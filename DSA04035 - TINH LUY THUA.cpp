#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

ll n, k;

ll powMod(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll tmp = powMod(a, b/2) % mod;
    if (b & 1) return tmp % mod * tmp % mod * a % mod;
    return tmp % mod * tmp % mod;
}

void process() {
    while(1) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            return;
        }
        cout << powMod(n, k) << endl;
    }
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}