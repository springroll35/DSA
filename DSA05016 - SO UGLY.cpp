#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(k) k.begin(), k.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e4+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

vector<ll> v;
set<ll> s;

void init() {
    ll k = 1;
    s.insert(k);
    while(s.size() < 10000) {
        for(auto x : s) {
            if(x > 1e18) break;
            v.pb(x * 2);
            v.pb(x * 3);
            v.pb(x * 5);
        }
        for(auto x : v) s.insert(x);
        v.clear();
    }
    v.clear();
    for(auto x : s) {
        v.pb(x);
    }
}

void process() {
    int n;
    cin >> n;
    cout << v[n-1] << endl;
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