#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

ll n;
ll ans;

void Try(ll x) {
    if (x > ans) {
        return;
    }
    if (x % n == 0) {
        ans = min(x, ans);
        return;
    }
    Try(x*10);
    Try(x*10+9);
}

void process() {
    cin >> n;
    ans = 1e18;
    Try(9);
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