#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k,i,fact[300005],mod=998244353,l,r,cnt,ans;
vector<pair<ll,bool>>p;
ll pw(ll a,ll b){
    if(!b)return 1ll;
    if(b&1)return (a*pw(a,b-1))%mod;
    ll x=pw(a,b>>1ll);
    return (x*x)%mod;
}
ll C(ll n,ll k){
    return (fact[n]*pw((fact[n-k]*fact[k])%mod,mod-2))%mod;
}
int main(){
    fact[0]=1;
    for(i=1;i<300005;i++)fact[i]=(fact[i-1]*i)%mod;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>l>>r;
        p.push_back({l,0});
        p.push_back({r,1});
    }
    sort(p.begin(),p.end());
    for(i=0;i<n*2;i++)
        if(p[i].second)cnt--;
        else{
            cnt++;
            if(cnt>=k)ans=((((ans+C(cnt,k))%mod)-(cnt!=k?C(cnt-1,k):0))%mod+mod)%mod;
        }
    cout<<ans;
}
