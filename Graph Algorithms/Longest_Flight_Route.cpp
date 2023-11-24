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
 
void solution()
{
	ll n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	int cnt[n + 1];
	memset(cnt, 0, sizeof(cnt));
	vector<int> from(n + 1, -1);
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(1);
	vector<bool> vis(n + 1, 0);
	while (!q.empty())
	{
		int node = q.top();
		q.pop();
		// if (vis[node]) continue;
		// vis[node] = 1;
		for (auto it : adj[node])
		{
			if (cnt[node] != -1 && cnt[node] + 1 > cnt[it])
			{
				cnt[it] = cnt[node] + 1;
				from[it] = node;
				q.push(it);
			}
		}
	}
	if (!cnt[n]) cout << "IMPOSSIBLE" << endl;
	else
	{
		vector<int> store;
		int temp = from[n];
		store.pb(n);
		while (temp != 1)
		{
			store.pb(temp);
			temp = from[temp];
		}
		store.pb(1);
		cout << store.size() << endl;
		for (int i = store.size() - 1; i >= 0; i--) cout << store[i] << " ";
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
