#include<bits/stdc++.h>
#define debug(x) cout << #x << "--->" << x << endl;
using namespace std;
vector<string>states, symbol;
vector<pair<string, string>>dfa[27];
map<string, int>mp;
string MakeSymbol(int pos, string sample, string type)
{
    int len = type.size();
    string temp = "";
    for(int i = pos; i < pos + len; i++) temp += sample[i];
    return temp;
}
bool DFS(int pos, string u, string final_state, string sample)
{
    if(pos == sample.size())
    {
        if(u == final_state) return true;
        return false;
    }
    bool IsFound = false;
    for(auto it : dfa[mp[u]])
    {
        string v = it.first;
        string type = it.second;
        string temp = MakeSymbol(pos, sample, type);
        if(temp == type)
        {
            IsFound |= DFS(pos + type.size(), v, final_state, sample);
        }
    }
    return IsFound;
}
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string ch; cin >> ch;
        states.push_back(ch);
        mp[ch] = i;
    }
    int m; cin >> m;
    for(int i = 1; i <= m; i++)
    {
        string ch; cin >> ch;
        symbol.push_back(ch);
    }
    int transition; cin >> transition;
    for(int i = 0; i < transition; i++)
    {
        string u, type, v; cin >> u >> type >> v;
        dfa[mp[u]].emplace_back(v, type);
    }
    int tc; cin >> tc;
    while(tc--)
    {
        string sample; cin >> sample;
        if(DFS(0, states[0], states.back(), sample)) cout << "Accepted" << endl;
        else cout << "Rejected" << endl;
    }
}
