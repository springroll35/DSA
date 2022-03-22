#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    vector<string> d = {"02", "20", "22"};
    vector<string> m = {"02"};
    vector<string> yy = {"2000", "2002", "2020", "2022", "2200", "2202", "2220", "2222"};
    for(auto x : d) {
        for(auto y : m) {
            for(auto z : yy) {
                cout << x << "/" << y << "/" << z << endl;
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

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}