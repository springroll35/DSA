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

void process() {
    int n;
    cin >> n;
    queue<ll> q;
    std::vector<ll> ans;
    q.push(6);
    q.push(8);
    ans.pb(6);
    ans.pb(8);
    while(q.size()) {
        ll x = q.front();
        if(to_string(x).length() >= n) break;
        q.pop();
        q.push(x*10+6);
        q.push(x*10+8);
        ans.pb(x*10+6);
        ans.pb(x*10+8);
    }
    reverse(all(ans));
    for(auto x : ans) cout << x << ' ';
    cout << endl;

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