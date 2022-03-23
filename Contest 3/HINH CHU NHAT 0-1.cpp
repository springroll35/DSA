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
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    for(int j = 0; j < n; j++) {
        for(int i = 1; i < m; i++) {
            if(a[i][j]) {
                a[i][j] = a[i-1][j] + 1;
            }
        }
    }
    stack<int> st1, st2;
    int ans = 0;
    int l[maxn], r[maxn];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            while(st1.size() && a[i][j] <= a[i][st1.top()]) st1.pop();
            if(st1.empty()) l[j] = 0;
            else l[j] = st1.top() + 1;
            st1.push(j);
        }
        for(int j = n-1; j >= 0; j--) {
            while(st2.size() && a[i][j] <= a[i][st2.top()]) st2.pop();
            if(st2.empty()) r[j] = n-1;
            else r[j] = st2.top() - 1;
            st2.push(j);
        }
        for(int j = 0; j < n; j++) {
            ans = max(ans, a[i][j] * (r[j] - l[j] + 1));
        }
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