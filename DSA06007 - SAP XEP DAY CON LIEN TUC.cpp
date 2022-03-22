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
typedef pair<ii, int> iii;

void process() {
    int n;
    cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    std::vector<int> b = a;
    sort(all(b));
    int l = 0, r = n-1;
    while(a[l] == b[l] && l < n) l++;
    while(a[r] == b[r] && r >= 0) r--;
    cout << l+1 << ' ' << r+1 << endl;

    

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