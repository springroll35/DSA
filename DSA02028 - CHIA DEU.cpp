#include<bits/stdc++.h>
 
using namespace std;
 
#define fi "inp.in"
#define fo "out.out"
 
const int maxn=1001;
 
long long n,k;
long long sum[maxn];
long long ans=0;
 
 
void Try(long long s,int l,int r,long long val) {
    if (l>r) return;
    if (val==0) return;
    else if (val==1) {
        if (sum[r]-sum[l-1]==s) {
            ans++;
        }
        return;
    }
    else {
        for(int i=l;i<=r;i++) {
            int tmp=l-1;
            if (sum[i]-sum[tmp]==s) Try(s,i+1,r,val-1);
        }
    }
}
 
 
void lam(){
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;i++) {
        long long x;
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    if (k==1) ans=1;
        for(int i=1;i<=n;i++) {
            long long cur=sum[i];
            Try(cur,i+1,n,k-1);
        }
    cout<<ans;
 
 
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    lam();
 
    return 0;
}