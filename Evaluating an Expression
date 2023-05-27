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
#define pdi pair<double, int>
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

vector<pdi> SeparateToken(string s)
{
	vector<pdi>vec;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') continue;

		string temp = "";
		if (s[i] >= '0' && s[i] <= '9')
		{
			while (i < s.size() && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			{
				temp += s[i];
				i++;
			}
			i--;
			vec.emplace_back(stod(temp), 0); // 0 means number
		}
		else
		{
			int type = (s[i] == '(' || s[i] == ')') ? 2 : 1;
			int ASCII = s[i];
			vec.emplace_back((double)ASCII, type);
		}
	}
	return vec;
}
double DoOperation(double a, double b, char ch)
{
	if (ch == '+') return a + b;
	else if (ch == '-') return a - b;
	else if (ch == '*') return a * b;
	else if (ch == '/') return a / b;
	else if (ch == '%') return (int)a % (int)b;
	else if (ch == '^')
	{
		int res = 1;
		for (int i = 1; i <= (int)b; i++) res *= (int)a;
		return res;
	}
}
void PrintExpression(vector<pdi>vec, int vis[])
{
	int m = vec.size();
	for (int i = 0; i < m; i++)
	{
		if (vis[i] == 0)
		{
			if (vec[i].se != 0)
			{
				char ch = (int)vec[i].fi;
				cout << ch;
			}
			else
			{
				if (vec[i].fi < 0 && i != 0) cout << '(';
				cout << vec[i].fi;
				if (vec[i].fi < 0 && i != 0) cout << ')';
			}
		}
	}
	cout << endl;
}
main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	string s; getline(cin, s);

	vector<pdi>vec = SeparateToken(s);
	// for (auto it : vec) cout << it.fi << ' ' << it.se << endl;
	map<char, int>precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'^', 3}};

	int m = vec.size();
	int vis[m] = {};

	stack<pair<char, int>>operators;
	stack<pdi>operand;

	PrintExpression(vec, vis);

	for (int i = 0; i < m; i++)
	{
		double num  = vec[i].fi;
		int type = vec[i].se;
		if (type == 0)
		{
			// debug(num);
			operand.push({num, i});
		}
		else if (type == 1)
		{
			char sign = (int)num;
			//debug(curr); + ' '
			if (operators.empty() == false && precedence[sign] <= precedence[operators.top().fi])
			{
				pdi fst = operand.top();
				operand.pop();

				pdi snd = operand.top();
				operand.pop();

				pair<char, int>OperatorType = operators.top();
				operators.pop();

				double res = DoOperation(snd.fi, fst.fi, OperatorType.fi);
				operand.push({res, snd.se});
				// debug(res);
				vec[snd.se] = {res, 0};
				for (int j = snd.se + 1; j <= fst.se; j++) vis[j] = true;

				PrintExpression(vec, vis);
			}
			operators.push({num, i});
		}
		else
		{
			char sign = (int)num;
			if (sign == '(')
			{
				operators.push({sign, i});
				continue;
			}
			pdi fst = operand.top();
			operand.pop();

			pdi snd = operand.top();
			operand.pop();

			pair<char, int>OperatorType = operators.top();
			operators.pop();

			pair<char, int> open_bracket = operators.top();
			operators.pop();

			double res = DoOperation(snd.fi, fst.fi, OperatorType.fi);

			// debug(res);
			operand.push({res, open_bracket.se});

			vec[open_bracket.se] = {res, 0};
			for (int j = open_bracket.se + 1; j <= i; j++) vis[j] = true;

			PrintExpression(vec, vis);
		}
	}
	while (operators.empty() == false)
	{
		pdi fst = operand.top();
		operand.pop();

		pdi snd = operand.top();
		operand.pop();

		pair<char, int>OperatorType = operators.top();
		operators.pop();

		double res = DoOperation(snd.fi, fst.fi, OperatorType.fi);
		operand.push({res, snd.se});

		// debug(res);
		vec[snd.se] = {res, 0};
		for (int j = snd.se + 1; j <= fst.se; j++) vis[j] = true;

		PrintExpression(vec, vis);
	}
}
