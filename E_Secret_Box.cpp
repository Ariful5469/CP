#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
vector<ll>v;

ll limit = 2000;
ll ok;
void sieve() {
    if(ok==0)v.push_back(1);
    ok++;
    if (limit < 2) return;
    
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            v.push_back(i);
        }
    }
}

void s(ll &a, ll &b, ll &c) {
   vector<ll>d;
   d.push_back(a); d.push_back(b); d.push_back(c);
   sort(d.begin(),d.end());
   a=d[0]; b=d[1]; c=d[2];

}

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
   
   
    ll ans = 0;
    ll ok=0;
    for (size_t i = 1; i <=a; ++i) {
       
        for (size_t j = 1; j <= b; ++j) {

            ll x=i*j;

            if(k%x==0)
            {
                if((k/x)<=c)
                {
                    ll z=(a-i+1)*(b-j+1)*(c-(k/x)+1);
                    ok=max(ok,z);
                }
            }


        }
        
        
        }
          

    cout << ok << endl;
}

int main() {
    ios_base::sync_with_stdio(false); // Speed up input/output
    cin.tie(NULL); // Untie cin from cout for faster I/O
    
    sieve(); // Initialize the sieve to populate vector v

    ll t = 1;
    cin >> t;
    
    

 
    while (t--) {
        solve();
    }

    return 0;
}
