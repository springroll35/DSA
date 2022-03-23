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

void process() {
    ll n, k;
    cin >> n >> k;
    ll a[n+1];
    for (ll i = 1; i <= n; i++) {
        a[i] = pow(2, i-1);
    }
    for(ll i = n; i > 0; i--) {
        if (k == a[i]) {
            cout << i << endl;
            break;
        }
        else if (k > a[i]) {
            k -= a[i];
        }
    }
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