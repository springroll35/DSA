#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e6+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;
string s, t, a[maxn];

void process() {
    cin >> n >> s >> t;
    set<string> se;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    queue<string> q;
    int cnt = 0;
    q.push(s);
    while(q.size()) {
        cnt++;
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            string x = q.front();
            q.pop();
            for(int j = 0; j < s.length(); j++) {
                char c = x[j];
                for(char k = 'A'; k <= 'Z'; k++) {
                    x[j] = k;
                    if(x == t) {
                        cout << cnt + 1 << endl;
                        return;
                    }
                    if(se.count(x) == 0) continue;
                    se.erase(x);
                    q.push(x);
                }
                x[j] = c;
            }
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