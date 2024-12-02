#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
ll ma[100], sa[100];

ll f(ll ind, ll taka, ll hapi, vector<vector<ll>>& dp, vector<vector<ll>>& sp) {
    if (ind == n-1) {
        if (taka >= ma[ind]) {
            return sa[ind];
        } else {
            return 0;
        }
    }

    if (dp[ind][hapi] != -1 && sp[ind][hapi] >= taka) {
        return dp[ind][hapi];
    }

    ll take = 0, nottake = 0;

    nottake = f(ind+1, taka+m, hapi, dp, sp);
    if (taka >= ma[ind]) {
        take = sa[ind] + f(ind+1, taka+m-ma[ind], hapi+sa[ind], dp, sp);
    }
    
    sp[ind][hapi] = taka;
    return dp[ind][hapi] = max(take, nottake);
}

void solve() {
    cin >> n >> m;
    
    ll c = 0;
    for (ll i = 0; i < n; i++) {
        cin >> ma[i] >> sa[i];
        c += sa[i];
    }
    
    vector<vector<ll>> dp(n, vector<ll>(c+1, -1));
    vector<vector<ll>> sp(n, vector<ll>(c+1, 0));

    ll x = f(0, 0, 0, dp, sp);

    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}