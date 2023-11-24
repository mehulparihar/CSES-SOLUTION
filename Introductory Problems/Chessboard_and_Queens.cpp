#include <bits/stdc++.h>
using namespace std;
 
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
bool isSafe(int row, int col, int n, vector<string> store)
{
	if (store[row][col] == '*') return false;
	int duprow = row;
	int dupcol = col;
	while (col >= 0)
	{
		if (store[row][col] == 'Q') return false;
		col--;
	}
	row = duprow;
	col = dupcol;
	while (row >= 0 && col >= 0)
	{
		if (store[row][col] == 'Q') return false;
		row--;
		col--;
	}
	row = duprow;
	col = dupcol;
	while (col >= 0 && row < n)
	{
		if (store[row][col] == 'Q') return false;
		row++;
		col--;
	}
	return true;
}
 
void helper(int col, int n, vector<string> store, int &ans)
{
	if (col >= n)
	{
		ans++;
		return;
	}
	for (int row = 0; row < n; row++)
	{
		if (isSafe(row, col, n, store))
		{
			store[row][col] = 'Q';
			helper(col + 1, n, store, ans);
			store[row][col] = '.';
		}
	}
}
void solution()
{
	vector<string> store;
	for (int i = 0; i < 8; i++)
	{
		string temp;
		cin >> temp;
		store.pb({temp});
	}
	int ans = 0;
	helper(0, 8, store, ans);
	cout << ans << endl;
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
