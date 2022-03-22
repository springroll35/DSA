#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;
ull a[maxn], mu[25];
int x[maxn];
ull ans;

void print() {
    ull num1 = 0, num2 = 0;
    int cnt = 0, cnt2 = 0;
    for(int i = n-1; i >= 0; i--) {
        if (x[i]) {
            num2 += mu[cnt2]*a[i];
            cnt2++;
        }
        else {
            num1 += mu[cnt]*a[i];
            cnt++;
        }
    }
    //cout << num1 << ' ' << num2 << endl;
    ans = min(ans, num1+num2);
}

void Try(int i) {
    for(int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n-1) print();
        else Try(i+1);
    }
}

void process() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    ans = 1e20;
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

    mu[0] = 1;
    for(int i = 1; i < 20; i++) mu[i] = mu[i-1]*10;

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}