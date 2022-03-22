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

struct Matrix {
    ll c[2][2];
    Matrix() {
        c[0][0]=0;
        c[0][1]=1;
        c[1][0]=1;
        c[1][1]=1;
    }
};

Matrix operator * (Matrix a, Matrix b) {
    Matrix ans;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ans.c[i][j] = 0;
            for(int k = 0; k < 2; k++)
                ans.c[i][j] = (ans.c[i][j] + a.c[i][k] * b.c[k][j]) % mod;
        }
    }
    return ans;
}

Matrix powermod (Matrix a, ll n) {
    if (n == 1) return a;
    if (n % 2) return powermod(a,n-1)*a;
    Matrix tmp = powermod(a,n/2);
    return tmp*tmp;
}

void process() {
    int n;
    cin >> n;
    Matrix F;
    F = powermod(F,n);
    cout << F.c[0][1] << endl;
    
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