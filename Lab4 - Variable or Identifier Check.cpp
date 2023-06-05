#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define print(v) for(auto it : v) cout << it << ' '; cout << endl;
#define valid(i, j, n, m) (i >= 0 && i < n && j >= 0 && j < m)
#define all(x) (x).begin(), (x).end()
#define revall(x) (x).rbegin(), (x).rend()
#define kase(i) cout << "Case " << i << ": ";
#define debug(x) cout << #x << "--> " << x << endl;
#define int long long
#define pii pair<int, int>
#define ppii pair<pii, int>
#define fi first
#define se second
#define inf 1e18
#define set(x, i) (x | (1 << i))
#define check(x, i) (x & (1 << i))
#define lcm(a, b) ((a  * b) / __gcd(a, b))

using namespace std;
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order and order_of_key
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order and order_of_key

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int IsSpecialCharacter(char ch)
{
	if (ch >= 'a' && ch <= 'z') return 0;
	if (ch >= 'A' && ch <= 'Z') return 0;
	if (ch >= '0' && ch <= '9') return 0;
	if (ch == '_') return 0;
	return 1;
}
bool IsReserved(string s)
{
	string keywords[32] = {
		"auto", "break", "case", "char", "const", "continue", "default",
		"do", "double", "else", "enum", "extern", "float", "for", "goto",
		"if", "int", "long", "register", "return", "short", "signed", "sizeof",
		"static", "struct", "switch", "typedef", "union", "unsigned", "void",
		"volatile", "while"
	};
	for (auto curr : keywords)
	{
		if (curr == s) return 1;
	}
	return 0;
}
main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	map<string, int>mp;
	string s;
	while (getline(cin, s))
	{
		if (s.size() == 0)
		{
			cout << "Invalid" << endl;
			continue;
		}
		if (mp[s])
		{
			cout << "Invalid, already Declared" << endl;
			continue;
		}
		int n = s.size();
		bool f = 1;
		if (s[0] >= '0' && s[0] <= '9') f = 0;
		for (int i = 0; i < n; i++)
		{
			if (IsSpecialCharacter(s[i]))
			{
				f = 0;
				break;
			}
		}
		if (IsReserved(s)) f = 0;

		if (f == 0)
		{
			cout << "Invalid" << endl;
		}
		else
		{
			cout << "Valid" << endl;
			mp[s]++;
		}

	}
}
