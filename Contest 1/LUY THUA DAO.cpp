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

ll n;
ll mu[20];

ll toNum(ll n) {
    string s = to_string(n);
    //cout << s << endl;
    ll m = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        m += mu[i] * (ll) (s[i] - '0');
    }
    return m;
}

ll powMod(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll tmp = powMod(a, b/2) % mod;
    if (b & 1) return tmp % mod * tmp % mod * a % mod;
    return tmp % mod * tmp % mod;
}

void process() {
    cin >> n;
    //cout << toNum(n) << endl;
    cout << powMod(n, toNum(n)) << endl;
    
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    mu[0] = 1;
    for(int i = 1; i < 20; i++) mu[i] = mu[i-1]*10;

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}