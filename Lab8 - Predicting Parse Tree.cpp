//Code Credit : Hamim99
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M   1000000007  //998244353 //
#define ll long long
#define pa pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define vi vector<int>
#define vll vector<ll>
#define fr(i,n,j) for(i=j;i<=n;i++)
#define rfr(i,n,j) for(i=n;i>=j;i--)
#define ct continue;
#define yo cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define endl '\n'
ll ar[500005],br[500005],cr[500005],dr[500005];
int main()
{
    ll te,n,m,i,j,k,w1,x,y,z,l2,k2,k1,q,l,r;
    map<char,map<char,string>>mp;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        char first,sec;
        string s;
        cin>>first>>sec>>s;
        mp[first][sec]=s;
    }
    string input,match,st;
    cin>>input;
    //dbg(input);
    stack<char> s1,s2,tmp1,tmp2;
    for(i=input.size()-1;i>=0;i--)s2.push(input[i]);
    s1.push('$');
    s1.push('E');
    while(1)
    {
 
        //cout<<"Matched"<<"\t"<<"\t"<<"Stack"<<"\t"<<"\t"<<"Input"<<"\t"<<"\t"<<"Action"<<"\t"<<"\t"<<endl;
        for(i=0;i<match.size();i++)cout<<match[i];
        cout<<"\t"<<"\t";
        tmp1=s1,tmp2=s2;
        while(!tmp1.empty())
        {
            auto ch=tmp1.top();
            cout<<ch;
            tmp1.pop();
        }
        cout<<"\t"<<"\t";
        while(!tmp2.empty())
        {
            auto ch=tmp2.top();
            cout<<ch;
            tmp2.pop();
        }
        cout<<"\t"<<"\t";
        if(s1.size()==1&&s2.size()==1)
        {
            cout<<endl;
            cout<<"Accepted!!!"<<endl;
            break;
        }
        char ch1=s1.top();
        char ch2=s2.top();
        if(ch1==ch2)
        {
            cout<<"match: "<<ch1<<endl;
            match.push_back(ch1);
            s1.pop();
            s2.pop();
            ct;
        }
        if(mp[ch1][ch2].size()==0)
        {
            cout<<endl;
            cout<<"Rejected!!!"<<endl;
            return 0;
        }
        s1.pop();
        string str=mp[ch1][ch2];
        cout<<"Output: "<<ch1<<" --> "<<str<<endl;
        if(str=="0")ct;
        for(i=str.size()-1;i>=0;i--)s1.push(str[i]);
 
    }
 
}
/*
Input
13
E i Te
E ( Te
e + +Te
e ) 0
e $ 0
T i Ft
T ( Ft
t + 0
t * *Ft
t ) 0
t $ 0
F i i
F ( (E)
 
i+i*i$
*/
