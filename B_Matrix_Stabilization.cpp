#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define N 200005    //FOR DSU
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define ha cout<<'Y'<<'E'<<'S'<<endl
#define na cout<<'N'<<'O'<<endl
#define pb push_back
#define F first
#define S second
#define speedup ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mmx (ll)1000000
const int inf = 1LL<<62;
const int md = 1000000007;
//..................................................SEGMENT TREE -> RANGE..............................................................
pair<ll,ll> seg[9999999];
ll mark[3000005];
void push(ll k) {
    if (mark[k]) {
        mark[k] = 0;
        seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
        seg[2*k].S = seg[2*k + 1].S = 0;
        mark[2*k] = mark[2*k + 1] = 1;
    }
}
void update(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x | a > y) return;
    if (a<=x && b>=y) {
        seg[k].S += v;
        return;
    }
    ll h = min(b,y) - max(a,x) + 1;
    push(k);
    seg[k].F += h*v;
    ll d = (x+y)/2;
    update(v, a, b, 2*k, x, d);
    update(v, a, b, 2*k + 1, d + 1, y);
}
ll assign(ll v, ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return seg[k].F + (y - x + 1)*seg[k].S;
    if (a <= x && b >= y) {
        seg[k].F = (y-x+1)*v;
        seg[k].S = 0;
        mark[k] = 1;
        return seg[k].F;
    }
    push(k);
    ll d = (x+y)/2;
    seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    seg[k].F = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
    return seg[k].F;
}
ll sum(ll a, ll b, ll k, ll x, ll y) {
    if (b < x || a > y) return 0;
    if (a <= x && b >= y) {
        return seg[k].F + (y-x+1)*seg[k].S;
    }
    push(k);
    seg[k].F += (y-x+1)*seg[k].S;
    seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
    seg[k].S = 0;
    ll d = (x+y)/2;
    return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
}
//.................................................... Random value generator...................................................................
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}
//........................................................BITWISE OPERATION.......................................................................
#define SetBit(x, k) (x = (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1)
//....................................................VECTOR SORT DIFFERENT WAY....................................................................
bool cmp(pair<ll, ll>& x, pair<ll, ll>& y) {
    if (x.second != y.second) {
        return x.second < y.second;
    }
    return x.first > y.first;
}
//.....................................................MOD ,FACT ,POWERMOD,INVERSEMOD,nCr,nPr........................................................
const ll mod = 1000000007;
int64_t fact(ll n) {
    if (n == 0) return 1;
    return (n * fact(n - 1)) % mod;
}
int64_t powermod(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll x = powermod(a, b / 2);
        return (x * x) % mod;
    } else {
        ll x = powermod(a, b / 2);
        return ((x * x) % mod * a) % mod;
    }
}
int64_t inversemod(ll a) {
    return powermod(a, mod - 2);
}
int64_t ncr(ll n, ll r) {
    if (r == 0) return 1;
    if (r > n) return 0;
    return ((fact(n)) * inversemod((fact(r) * fact(n - r)) % mod)) % mod;
}
//............................................................DSU............................................................................
int parent[N];
int sz[N];
void make_set(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
void solve() {

   ll n,m;
   cin>>n>>m;

   ll ar[n][m];

   for(ll i=0;i<n;i++)
   {
    for(ll j=0;j<m;j++)
    {
        cin>>ar[i][j];
    }
   }


   for(ll i=0;i<n;i++)
   {
    for(ll j=0;j<m;j++)
    {
        ll x1,x2,x3,x4;
        if(i-1>=0)
         x1=ar[i-1][j];
         else x1=INT_MIN;
        if(i+1<n)
         x2=ar[i+1][j];
         else x2=INT_MIN;
         if(j-1>=0)
         x3=ar[i][j-1];
         else x3=INT_MIN;
         if(j+1<m)
         x4=ar[i][j+1];
         else x4=INT_MIN;


         ll mn=max({x1,x2,x3,x4});

         if(ar[i][j]<=mn)continue;
         else ar[i][j]=mn;
    }
   }

   for(ll i=0;i<n;i++)
   {
    for(ll j=0;j<m;j++)
    {
        cout<<ar[i][j]<<" ";
    }
    cout<<endl;
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