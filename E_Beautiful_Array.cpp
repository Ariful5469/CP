#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define speedup ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> ar(n);

    for (ll i = 0; i < n; i++) {
        cin >> ar[i];
    }

    map<ll, vector<ll>> v;

    // Grouping elements based on their modulo m values
    for (ll i = 0; i < n; i++) {
        v[ar[i] % m].pb(ar[i]);
    }

    ll cnt = 0;
    for (auto it : v) {
        if (it.second.size() % 2 == 1) cnt++;
    }

    if (cnt > 1) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    for (auto it : v) {
        vector<ll> vv = it.second;
        sort(all(vv));

        if (vv.size() % 2 == 0) {
            for (ll i = 0; i < vv.size(); i += 2) {
                ans += (vv[i + 1] - vv[i]) / m;
            }
        } else {
            ll ok = vv.size();
            if (ok == 1) continue;

            vector<ll> pre(ok+2, 0), suf(ok+2, 0);

            // Compute prefix sums
            for (ll i = 0; i < ok - 2; i += 2) {
                if (i == 0) {
                    pre[i] = (vv[i + 1] - vv[i]) / m;
                } else {
                    pre[i] = pre[i - 2] + ((vv[i + 1] - vv[i]) / m);
                }
                
            }

            // Compute suffix sums
            for (ll i = ok - 2; i >=1; i -= 2) {
                if (i == ok - 2) {
                    suf[i] = (vv[i + 1] - vv[i]) / m;
                } else {
                    suf[i] = suf[i + 2] + ((vv[i + 1] - vv[i]) / m);
                }
                
            }

            // Find the minimum difference
            ll min_diff = INT_MAX;
            for (ll i = 0; i < ok; i += 2) {

                if(i==0)
                {
                    min_diff = min(min_diff,suf[i+1]);
                }
                else if(i==n-1)
                {
                    min_diff = min(min_diff,pre[i-2]);
                }
                else
                min_diff = min(min_diff, pre[i - 2] + suf[i + 1]);
            }

            ans += min_diff;
        }
    }

    cout << ans << endl;
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
