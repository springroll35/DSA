#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(dp) dp.begin(), dp.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

vector<ll> dp;

ll cal(ll x, ll n, ll pos) {
    if (x & 1) return 1;
    if (x < dp[pos]) return cal(x, n >> 1, pos - 1);
    else if (x == dp[pos]) return n & 1;
    return cal(2 * dp[pos] - x, n >> 1, pos - 1);
}

void process() {
    ll n, l, r; 
    cin >> n >> l >> r;
    dp.clear();
    ll mul = 1;
    ll tmp = n;
        while (tmp > 1) {
            mul <<= 1;
            dp.pb(mul);
            tmp >>= 1;
        }
        ll ans = 0;
        for (ll i = l; i <= r; i++) {
            ans += cal(i, n, dp.size() - 1);
        }
        cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}