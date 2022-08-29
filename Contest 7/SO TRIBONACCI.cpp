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
const ll mod = 1e15+7;
ll tr[5] = {1,3,6,12,23};
typedef pair<int,int> ii;

struct Matrix {
	ll dp[4][4] = {
		{1,0,0,0},
		{0,1,1,0},
		{1,1,0,1},
		{0,1,0,0}
    };
};

ll Mul(ll a, ll b) {
	if (b <= 1) return a % mod * b;
	ll tmp = Mul(a, b / 2);
	if (b % 2 == 0) return tmp % mod + tmp % mod;
	else return tmp % mod + tmp % mod + a % mod;
}

Matrix operator*(Matrix A, Matrix B) {
	Matrix C;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			C.dp[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				C.dp[i][j] = C.dp[i][j] % mod + Mul(A.dp[i][k], B.dp[k][j]) % mod;
				C.dp[i][j] %= mod;
			}
		}
	}
	return C;
}

Matrix powMod(Matrix X, ll k) {
	if (k == 1)return X;
	Matrix tmp = powMod(X, k / 2);
	if (k % 2 == 0) return tmp * tmp;
	else return tmp * tmp * X;
}

ll Tribonaci(ll n) {
	if (n <= 5) return tr[n - 1];
	Matrix X;
	Matrix ans = powMod(X, n+2);
	return ans.dp[2][0] - 1;
}

void process() {
    ll n;
    cin >> n;
    cout << Tribonaci(n) << endl;
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