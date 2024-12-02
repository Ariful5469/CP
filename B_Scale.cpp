#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define speedup ios::sync_with_stdio(0);cin.tie(0);

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<vector<char>> grid(n, vector<char>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    ll reducedSize = n / k;
    vector<vector<char>> reducedGrid(reducedSize, vector<char>(reducedSize));

    for (ll i = 0; i < reducedSize; i++) {
        for (ll j = 0; j < reducedSize; j++) {
            reducedGrid[i][j] = grid[i * k][j * k];
        }
    }

    // Output the reduced grid
    for (ll i = 0; i < reducedSize; i++) {
        for (ll j = 0; j < reducedSize; j++) {
            cout << reducedGrid[i][j];
        }
        cout << endl;
    }
}

int main() {
    speedup;
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
