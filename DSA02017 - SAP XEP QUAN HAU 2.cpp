#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 105;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n = 8;
int a[maxn][maxn];
vector<int> p(maxn,0), q(maxn,0), r(maxn,0);
int x[maxn];
int ans;

void print() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][x[i]];
    }
    ans = max(ans, sum);
}

void Try(int i) {
    for (int j = 0; j < n; j++) {
        if (p[j] == 0 && q[i+j] == 0 && r[i-j+n-1] == 0) {
            x[i] = j;
            if (i == n-1) print();
            else {
                p[j] = q[i+j] = r[i-j+n-1] = 1;
                Try(i+1);
                p[j] = q[i+j] = r[i-j+n-1] = 0;
            }
        }
    }
}



void process() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    ans = 0;
    Try(0);
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