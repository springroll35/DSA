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
const ll mod = 1e15+7;
typedef pair<int,int> ii;

void process() {
    queue<ll> q;
    vector<ll> v;
    q.push(4);
    q.push(7);
    v.pb(4);
    v.pb(7);
    ll k, x, y;
    while(q.front() <= 1e9) {
        k = q.front();
        q.pop();
        x = k * 10 + 4;
        y = k * 10 + 7;
        q.push(x);
        q.push(y);
        v.pb(x);
        v.pb(y);
    }
    int a, b;
    cin >> a >> b;
    ll ans = 0, cnt = 0;
    int id = lower_bound(all(v), a) - v.begin();
    while(a <= b) {
        cnt = min(v[id], 1ll * b) - a + 1;
        ans += cnt * v[id];
        a = v[id] + 1;
        id++;
    }
    cout << ans;
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