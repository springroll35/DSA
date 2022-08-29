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
    int s, t;
    cin >> s >> t;
    map<int, int> mp;
    queue<ii> q;
    q.push({s, 0});
    mp[s] = 1;
    while(q.size()) {
        ii x = q.front();
        q.pop();
        if(x.fi == t) {
            cout << x.sc << endl;
            return; 
        }
        if(x.fi - 1 == t || x.fi * 2 == t) {
            cout << x.sc+1 << endl;
            return;
        }
        if(x.fi - 1 >= 0 && mp[x.fi-1] == 0) {
            mp[x.fi-1] = 1;
            q.push({x.fi-1, x.sc+1});
        }
        if(x.fi * 2 <= t * 2 && mp[x.fi*2] == 0) {
            mp[x.fi*2] = 1;
            q.push({x.fi*2, x.sc+1});
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