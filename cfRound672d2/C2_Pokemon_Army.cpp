#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> pi;
int a[1000005];
int cal(int x){
	return max(0LL,a[x]-a[x-1]);
}
int n,q;
void solve(){
	cin>>n>>q;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=cal(i);
	}
	a[n+1]=0;
	cout<<ans<<"\n";
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		ans-=cal(l)+cal(l+1)+(l+1<r)*cal(r)+(l<r)*cal(r+1);
		swap(a[l],a[r]);
		ans+=cal(l)+cal(l+1)+(l+1<r)*cal(r)+(l<r)*cal(r+1);
		cout<<ans<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.inp","r",stdin);
	int test;
	cin>>test;
	while(test--){
		solve();
	}
	
}
