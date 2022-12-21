#include <iostream>
#include <vector>
using namespace std;
/*
Author: Faizolla Amanbek
                      ......
               .:!?Y5PPPGGPPP5Y?!:.
            .!YPGGP55YYJJJJYY55PGGPY!.
          ^JGBPYJJJJJJJY5PP5YJJJJJYPBGJ^
        :YBG5JJJJJJJJJPBBBBPYJJJJJJJJ5GBY:
       7BB5JJJJJJJJYY5BBBBBB5YYJJJJJJJJ5BB7
      J#GJJJJJJJY555YY5GBBG5YY555YJJJJJJJG#J
     ?#GJJJJJJY5PYJJJJJJJJJJJJJJYP5YJJJJJJG#?
    ^BBJJJJJJYP5JJJJJJJJJJJJJJJJJJ5PYJJJJJJBB^
    J#PJJJJJJ55JJJJJJYPGBBGPYJJJJJJ55JJJJJJP#J
    5#YJJJJJYP5JJJJJJBBBBBBBBJJJJJJ5PYJJJJJY#5
    5#YJJJJJYP5JJJJJJBBBBBBBBJJJJJJ5PYJJJJJY#5
    J#PJJYGYPBBGPYJJJYPGBBGPYJJJCYPGBBPYJJJJP#J
    ^BBJJJGBBBBB#PJJJJJJJJJJJJJJP#BBBBGJJJJBB^
     ?#GJJJPGBBBG5JJJJJJJJJJJJJJ5GBBBBGJJJG#?
      J#GJJJJJJJY555YYJJJJJJYY555YJYGPYJJG#J
       7BB5JJJJJJJJY5555555555YJJJJJJJJ5BB7
        :YBG5JJJJJJJJJJJJJJJJJJJJJJJJ5GBY:
          ^JGBPYJJJJJJJJJJJJJJJJJJYPBGJ^
            .!YPGGP55YYYJJYYY55PGGPY!.
               .:!?Y5PPPGGPPP5Y?!:.
                      ......
*/
long long MOD = 1e9 + 7;
long long X = 31;

long long getHash(string s)
{
    long long hash = 0;
    long long curX = 1;
    for (long long i = 0; i < s.size(); i++)
    {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s)
{
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (long long i = 0; i < s.size(); i++)
    {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0)
        {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

vector<long long> rabinKarp(string s, string t, vector<long long> hashes, long long smallHash)
{
    vector<long long> res;
    for (long long i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
        {
            res.push_back(i);
        };
    }
    return res;
}
bool mine_rabinKarp(string s, string t, vector<long long> hashes, long long smallHash)
{
    bool res = false;
    for (long long i = 0; i < s.size() - t.size() + 1; i++)
    {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0)
            hashDif -= hashes[i - 1];
        if (hashDif < 0)
            hashDif += MOD;
        if (i != 0)
            smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif)
            res = true;
    }
    return res;
}
int main()
{

    string s;
    cin >> s;
    long long n;
    cin >> n;
    vector<string> v(n);
    vector<bool> to_check_small(s.size(), false);
    vector<long long> indeces_of_occurences;
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bool flag = true;
    vector<long long> hashed_longtape = getPrefixHashes(s);
    for (int i = 0; i < n; i++)
    {
        long long smallHash = getHash(v[i]);
        flag = mine_rabinKarp(s, v[i], hashed_longtape, smallHash);
        indeces_of_occurences = rabinKarp(s, v[i], hashed_longtape, smallHash);
        if (flag == false)
            break;
        for (int j = 0; j < indeces_of_occurences.size(); j++)
        {
            int index_of_occurence = indeces_of_occurences[j];
            for (int index = 0; index < v[i].size(); index++)
            {
                to_check_small[index_of_occurence + index] = flag; // This for loop is lit!!!!!!!!!!!!!!!!!!!!!!!!!
            }
        }
    }
    for (long long i = 0; i < to_check_small.size(); i++)
    {
        if (to_check_small[i] == false)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}