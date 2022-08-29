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
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> l(n, 1), r(n, 1);
	for(int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) l[i] += l[i-1];
    }
	for(int i = n-2; ~i; i--) {
        if (a[i] > a[i + 1]) r[i] += r[i+1];
    }
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, l[i] + r[i] - 1);
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