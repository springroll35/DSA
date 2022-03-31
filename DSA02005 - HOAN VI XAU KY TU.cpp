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

int n;

void process() {
    string a;
    cin >> a;
    cout << a << ' ';
    while (next_permutation(a.begin(),a.end())) {
        cout << a << ' ';
    }
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