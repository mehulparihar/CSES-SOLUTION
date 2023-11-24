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
ll helper(vector<ll> &a, ll total, ll n, vector<vector<ll>> &dp)
{
	if (total < 0 || n <= 0) return 0;
	if (total == 0) return 1;
	if (dp[n][total] != -1) return dp[n][total];
	if (a[n - 1] > total) return dp[n][total] = helper(a, total, n - 1, dp) % mod;
	else return dp[n][total] = (helper(a, total, n - 1, dp) % mod + helper(a, total - a[n - 1], n - 1, dp) % mod) % mod;
}
void solution()
{
	ll n;
	cin >> n;
	vector<ll> a;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
		a.push_back(i);
	}
	if (sum & 1) {cout << 0 << endl; return;}
	ll total = sum / 2;
	vector<vector<ll>> dp(n + 1, vector<ll>(total + 1, 0));
	// cout << helper(a, total, n, dp) << endl;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= total; j++)
		{
			if (j - i >= 0) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % mod;
			else dp[i][j] = dp[i - 1][j] % mod;
		}
	}
	cout << dp[n - 1][total];
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
