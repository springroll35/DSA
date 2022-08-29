#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 100;
const ll mod = 1e9+7;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

const int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

void process() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 9; i >= 0; i--) {
        while(n >= a[i]) {
            ans++;
            n -= a[i];
        }
        if(n <= 0) break;
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