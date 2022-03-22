#include <bits/stdc++.h>

using namespace std;

const int maxn=5e3+1;

int t,n;

int bs(long long a[],int l,int r,long long x) {
	while(l<=r){
		int mid=(r+l)/2;
		if (a[mid]==x) return mid;
		else if (a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return -1;
}

void lam(){
	long long a[maxn];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n;j++){
			long long z=sqrt(a[i]*a[i]+a[j]*a[j]);
			if (z*z==a[i]*a[i]+a[j]*a[j]){
				int id=bs(a,j,n,z);
				if (id!=-1){
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
}
int main()
{
    cin>>t;
    while(t--) lam();
    return 0;
}
