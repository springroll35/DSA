#include<bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define fo "out.out"
#define ll long long
#define fr first
#define sc second

typedef pair<int,int> ii;

const int maxn=1e4+5;
const ll mod = 1e9+7;;

int n;
int a[maxn];

void  process(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> max_sum_inc(n,0);
    vector<int> max_sum_dec(n,0);
    for(int i=0;i<n;i++) {
        max_sum_inc[i]=max_sum_dec[i]=a[i];
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if (a[i] > a[j] && max_sum_inc[i] < max_sum_inc[j]+a[i]) {
                max_sum_inc[i]=max_sum_inc[j]+a[i];
            }
        }
    }

    for(int i=n-2;i>=0;i--) {
        for(int j=n-1;j>i;j--) {
            if (a[i] > a[j] && max_sum_dec[i] < max_sum_dec[j]+a[i]) {
                max_sum_dec[i]=max_sum_dec[j]+a[i];
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,max_sum_inc[i]+max_sum_dec[i]-a[i]);
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




