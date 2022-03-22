#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 105;
const ll mod = 1e9+7;
const int row[4] = {-1, 0, 1, 0};
const int col[4] = {0, -1, 0, 1};
typedef pair<int,int> ii;

std::vector<ll> v;

void generate() {
    queue<ll> q;
    q.push(1);
    v.pb(1);
    while(q.size()) {
        ll x = q.front();
        q.pop();
        if(to_string(x).length() > 17) break;
        q.push(x * 10);
        q.push(x * 10 + 1);
        v.pb(x * 10);
        v.pb(x * 10 + 1);
    }
}

void process() {
    ll n;
    cin >> n;
    ll pos = lower_bound(all(v), n) - v.begin();
    if(v[pos] == n) pos++;
    cout << pos << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    generate();
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}