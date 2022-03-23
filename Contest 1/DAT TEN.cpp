#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 35;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n,k;
int x[maxn];
string a[maxn], b[maxn];
int cnt = 0;

void print() {
    for(int i = 1; i <= k; i++) {
        cout << b[x[i]] << ' ';
    }
    cout << endl;
}

void Try(int i) {
    // x[i-1]+1 <= x[i] <= n-k+i+1 (i =  0 ... k-1)
    for(int j = x[i-1]+1; j <= cnt-k+i; j++) {
        x[i] = j;
        if (i == k) print();
        else Try(i+1);
    }
}

void process() {
    cin >> n >> k;
    map<string, int> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if (m[a[i]] == 0) {
            b[++cnt] = a[i];
        }
        m[a[i]]++;
    }
    sort(b,b+cnt+1);
    //for(int i = 0; i < cnt; i++) cout << b[i] << ' ';
    x[0] = 0;
    Try(1);
    
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