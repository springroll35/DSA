#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e3+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

ll dp[100];

void init() {
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < 93; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}

char find1(ll n, ll k) {
    if(n == 1) return '0';
    if(n == 2) return '1';
    if(k <= dp[n-2]) 
        return find1(n-2, k);
    else 
        return find1(n-1, k-dp[n-2]);
}

void process() {
    ll n, k;
    cin >> n >> k;
    cout << find1(n, k) << endl;
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}