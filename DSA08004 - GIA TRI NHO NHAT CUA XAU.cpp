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
    int k;
    string s;
    cin >> k >> s;
    int n = s.length();
    priority_queue<int> q;
    std::vector<int> v(26, 0);
    for(char c : s) {
        v[c - 'A']++;
    }
    for(auto x : v) {
        if (x) {
            q.push(x);
        }
    }
    while(k--) {
        int tmp = q.top();
        q.pop();
        q.push(tmp-1);
    }
    ll ans = 0;
    while(q.size()) {
        int tmp = q.top();
        ans += 1ll*tmp*tmp;
        q.pop();
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