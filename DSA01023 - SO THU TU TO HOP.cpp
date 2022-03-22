#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n,k;
int a[maxn];
int x[maxn];
int cnt, ans;

bool check(int a[], int b[]) {
    for(int i = 0; i < k; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void print() {
    cnt++;
    //cout << cnt << endl;
    if (check(a, x)) ans = cnt;
    
    
}

void Try(int i) {
    // x[i-1]+1 <= x[i] <= n-k+i+1 (i =  0 ... k-1)
    for(int j = x[i-1]+1; j <= n-k+i+1; j++) {
        x[i] = j;
        if (i == k-1) print();
        else Try(i+1);
    }
}

void process() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> a[i];
    cnt = 0;
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