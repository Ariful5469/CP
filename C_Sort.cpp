#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define speedup ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    
    ll n,m;
    cin>>n>>m;

    string  a,b;
    cin>>a>>b;

    vector<vector<ll>>ap(n+1,vector<ll>(26,0)),bp(n+1,vector<ll>(26,0));

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<26;j++)
        {
           
               ap[i+1][j]=ap[i][j]+(j==(a[i]-'a'));
               bp[i+1][j]=bp[i][j]+(j==(b[i]-'a'));
            
        }
    }

    while(m--)
    {
        ll x,y;
        cin>>x>>y;
    

    for(ll i=0;i<26;i++)
    {
        ap[y][i]-=ap[x-1][i];
        bp[y][i]-=bp[x-1][i];
    }
    ll ans=0;
 for(ll i=0;i<26;i++)
    {
        if(bp[y][i]>ap[y][i])
        {
            ans+=bp[y][i]-ap[y][i];
        }
    }

cout<<ans<<endl;
    }

}

int main() {
    speedup;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
