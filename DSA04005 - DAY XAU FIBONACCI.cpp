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

ll dp[100];

char Try(ll n, ll k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= dp[n-2]) {
        return Try(n-2, k);
    }
    else {
        return Try(n-1, k-dp[n-2]);
    }
}

void process() {
    ll n, k;
    cin >> n >> k;
    cout << Try(n, k) << endl;
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < 93; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}