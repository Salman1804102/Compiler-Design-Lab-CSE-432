#include<bits/stdc++.h>
#define debug(x) cout << #x << "--->" << x << endl;
using namespace std;

vector<string>states, symbol;
vector<pair<string, string>>nfa[27];

map<string, int>isfinal;
map<string, int>mp;

string MakeSymbol(int pos, string sample, string type)
{
    int len = type.size();
    string temp = "";
    for(int i = pos; i < min(pos + len, (int)sample.size()); i++) temp += sample[i];
    return temp;
}
bool DFS(int pos, string curr_state, string sample)
{
    //debug(curr_state);
    if(pos == sample.size())
    {
        if(isfinal[curr_state] == true) return true;

        for(auto it : nfa[mp[curr_state]])
        {
            string input_type = it.second;
            if(input_type == "epsillon" && isfinal[it.first]) return true;
        }
        return false;
    }

    bool IsFound = false;
    for(auto it : nfa[mp[curr_state]])
    {
        string target_state = it.first;
        string input_type = it.second;

        string temp = MakeSymbol(pos, sample, input_type);
        if(temp == input_type)
        {
            IsFound |= DFS(pos + input_type.size(), target_state, sample);
        }
    }
    return IsFound;
}
int main()
{
    cout << "Enter the number of states: ";
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string ch; cin >> ch;
        states.push_back(ch);
        mp[ch] = i;
    }
    cout << "Enter the number of symbols: ";
    int m; cin >> m;
    for(int i = 1; i <= m; i++)
    {
        string ch; cin >> ch;
        symbol.push_back(ch);
    }

    cout << "Enter the initial state: ";
    string initial_state; cin >> initial_state;

    cout << "Enter the number of final states: ";
    int p; cin >> p;
    for(int i = 1; i <= p; i++)
    {
        string ch; cin >> ch;
        isfinal[ch] = 1;
    }
    int transition; cin >> transition;
    for(int i = 0; i < transition; i++)
    {
        string u, type, v; cin >> u >> type >> v;
        nfa[mp[u]].emplace_back(v, type);
    }
    int tc; cin >> tc;
    while(tc--)
    {
        string sample; cin >> sample;
        if(DFS(0, initial_state, sample)) cout << "Accepted" << endl;
        else cout << "Rejected" << endl;
    }
}
