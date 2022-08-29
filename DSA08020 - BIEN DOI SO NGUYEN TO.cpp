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

const int maxn = 1e4+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int s, t;
int a[5], isPrime[maxn];

void seive() {
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i <= sqrt(maxn); i++) {
        if(!isPrime[i]) {
            for(int j = i*i; j <= maxn; j += i) isPrime[j] = 1;
        }
    }
}

void makeNum(int a[], int n) {
    for(int i = 3; i >= 0; i--) {
        a[i] = n % 10;
        n /= 10;
    }
}

void process() {
    cin >> s >> t;
    queue<int> q;
    q.push(s);
    int dp[maxn];
    memset(dp, -1 , sizeof(dp));
    dp[s] = 0;
    q.push(s);
    while(q.size()) {
        int n = q.front();
        q.pop();
        makeNum(a, n);
        for(int i = 0; i < 4; i++) {
            int k = a[i];
            for(int j = 0; j <= 9; j++) {
                a[i] = j;
                int tmp = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
                if(tmp >= 1000 && !isPrime[tmp] && dp[tmp] == -1) {
                    dp[tmp] = dp[n] + 1;
                    q.push(tmp);
                }
            }
            a[i] = k;
        }
    }
    cout << dp[t] << endl;

}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    seive();
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}