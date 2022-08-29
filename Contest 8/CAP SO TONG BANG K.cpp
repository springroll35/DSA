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

void process() {
    ll n, k;
    cin >> n >> k;
    std::vector<ll> a(n);
    map<ll, ll> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    int ans = 0;
    if(d[a[0]] == n && a[0] + a[0] == k) {
        cout << n*(n-1)/2 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(d[a[i]]) {
            if (a[i] == k-a[i]) {
                ans += d[a[i]] * (d[a[i]]-1) / 2;
            }
            else {
                ans += d[a[i]] * d[k-a[i]];
            }
            d[a[i]] = d[k-a[i]] = 0;
        }
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