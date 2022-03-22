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
    string s;
    std::vector<int> v;
    while(cin >> s) {
        if (s == "push") {
            int x;
            cin >> x;
            v.pb(x);
        }
        else if (s == "pop") {
            v.pop_back();
        }
        else {
            if (v.empty()) {
                cout << "empty";
            }
            else {
                for(auto x : v) cout << x << ' ';
            }
            cout << endl;
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

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}