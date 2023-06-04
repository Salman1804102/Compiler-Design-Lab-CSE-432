#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

bool isKeyword(string s)
{
    string keyword[4] = {"int", "main", "double", "for"};
    for (auto it : keyword)
    {
        if (it == s) return 1;
    }
    return 0;
}
bool isOperator(string s)
{
    string operators[5] = {"+", "=", "<=", "++", "<"};
    for (auto it : operators)
    {
        if (it == s) return 1;
    }
    return 0;
}
bool isPunctuation(string s)
{
    string punctuations[6] = {",", ";", "(", ")", "{", "}"};
    for (auto it : punctuations)
    {
        if (it == s) return 1;
    }
    return 0;
}
bool isNumber(string s)
{
    for (auto it : s)
    {
        if ((it >= '0' && it <= '9') || (it == '.')) continue;
        return false;
    }
    return true;
}
bool isIdentifier(string s, char arr[], int pos)
{
    string identifiers[6] = {"c", "a", "abc12", "i"};
    for (auto it : identifiers)
    {
        if (it == s)
        {
            string temp = "";
            temp += arr[pos + 1];
            if (isOperator((temp))) return 1;
        }
    }
    return 0;
}

int main()
{
    FILE *ptr;
    ptr = fopen("in.txt", "r");
    char arr[100001];
    set<string>keyword, number, operators, punctuations;
    map<string, int>mp;
    vector<string>identifiers;
    while (fgets(arr, 100001, ptr))
    {
        string curr = "";
        for (int i = 0; arr[i + 1] != '\0'; i++)
        {
            if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n') continue;

            curr += arr[i];
            if (isPunctuation(curr))
            {
                punctuations.insert(curr);
                curr = "";
            }
            else if (isOperator(curr))
            {
                while ((arr[i] != '\0') && isOperator(curr))
                {
                    i++;
                    string temp = "";
                    temp += arr[i];
                    if (isOperator(temp)) curr += arr[i];
                    else break;
                }
                i--;
                operators.insert(curr);
                curr = "";
            }
            else if (isNumber(curr))
            {
                while ((arr[i] != '\0') && isNumber(curr))
                {
                    i++;
                    string temp = "";
                    temp += arr[i];
                    if (isNumber(temp)) curr += arr[i];
                    else break;
                }
                i--;
                number.insert(curr);
                curr = "";
            }
            else if (isKeyword(curr))
            {
                keyword.insert(curr);
                curr = "";
            }
            else if (isIdentifier(curr, arr, i))
            {
                identifiers.push_back(curr);
                curr = "";
            }
            //cout << "curr = " << curr << endl;
        }
    }
    for (auto it : keyword) cout << it << ' '; cout << endl;
    for (auto it : number) cout << it << ' '; cout << endl;
    int seq = 0;
    for (auto it : identifiers)
    {
        if (mp[it] == 0)
        {
            cout << it << ' ';
            mp[it] = ++seq;
        }
    }
    cout << endl;
    for (auto it : operators) cout << it << ' '; cout << endl;
    for (auto it : punctuations) cout << it << ' '; cout << endl;

    cout << endl << "Symbol Table" << endl;

    vector<pair<int, string>>vec;
    for (auto it : mp)
    {
        //cout << it.second << ' ' << it.first << endl;
        vec.push_back({it.second, it.first});
    }
    sort(vec.begin(), vec.end());
    for (auto it : vec)
    {
        cout << it.first << ' ' << it.second << endl;
    }
}



