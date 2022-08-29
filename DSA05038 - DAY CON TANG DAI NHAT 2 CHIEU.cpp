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

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;
map<int, int> dp[maxn];
map<int, int>::iterator it1, it2;

void find(int id, int x, int y) {
	it1 = dp[id].lower_bound(x);
	it2 = it1;
	while (it2 != dp[id].end() && it2->sc >= y) it2++;
	dp[id].erase(it1, it2);
	dp[id].insert({x, y});
}

bool check(int id, int x, int y) {
	it1 = dp[id].lower_bound(x);
	if (it1 == dp[id].begin()) return false;
	it1--;
	return it1->sc < y;
}

void process() {
    cin >> n;
	find(0, -1e9-1, -1e9-1);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x, y; 
        cin >> x >> y;
		int l = 0, r = ans;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, x, y)) l = mid + 1;
			else r = mid - 1;
		}
		if (ans == l - 1) ans = l;
		find(l, x, y);
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

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}