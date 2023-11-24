#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define INF LLONG_MAX
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < n; i++)
#define forr(i, a, b) for (int i = a; i <= b; i++)
#define trav(x, v) for (auto &x : v)
const int mod = 1e9 + 7;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
 
inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
 
template<typename T>
T gcd(T a, T b) { return (b == 0) ? a : gcd(b, a % b); }
 
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
 
// ------------------------------------------------------------------------------------------------------------------------------ -
// const int N = 1e6 + 2;
vector<int> a;
vector<ll> lazy;
void update(int ind, int start, int end, int l, int r, int val)
{
	if (start == l && end == r)
	{
		lazy[ind] += val;
		return;
	}
	if (start > r || end < l) return;
	int mid = (start + end) >> 1;
	update(ind * 2 + 1, start, mid, l, min(r, mid), val);
	update(ind * 2 + 2, mid + 1, end, max(l, mid + 1), r, val);
}
ll get(int ind, int start, int end, int k)
{
	if (start == end) return lazy[ind];
	if (start > end) return 0;
	ll re = lazy[ind];
	int mid = (start + end) >> 1;
	if (mid >= k) return re + get(ind * 2 + 1, start, mid, k);
	else return re + get(ind * 2 + 2, mid + 1, end, k);
}
void solution()
{
	ll n, q;
	cin >> n >> q;
	a.assign(n, 0);
	lazy.assign(n * 4, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < q; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int a, b, u;
			cin >> a >> b >> u;
 
			update(0, 0, n - 1, a - 1, b - 1, u);
		}
		else
		{
			int k;
			cin >> k;
			// k--;
			cout << a[k - 1] + get(0, 0, n - 1, k - 1) << endl;
		}
	}
}
 
int32_t main()
{
	fastio;
	debugMode();
	// ll t;
	// cin >> t;
	// while (t--)
	solution();
 
	return 0;
}
