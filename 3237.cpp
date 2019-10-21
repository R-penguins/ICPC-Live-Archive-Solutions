/**
 * Wiping Words
 * 2004 Tehran
 */
#include <bits/stdc++.h>
using namespace std;
struct Pos
{
    int x, y;
    Pos(int x, int y) : x(x), y(y) { }
};
map<string, int> num;
vector<vector<Pos>> p;
vector<string> txt;
vector<vector<int>> ntxt;
vector<int> sz;
void del(int);
int id(string &str)
{
    if (num.count(str))
        return num[str];
    p.push_back(vector<Pos>());
    sz.push_back(str.size());
    return num[str] = sz.size() - 1;
}
void tryDel(int r, int c)
{
    int curID = ntxt[r][c];
    bool keep = false;
    for (int j = c; j < ntxt[r + 1].size() && j < c + sz[curID]; ++j)
        if (isalpha(txt[r + 1][j]) || txt[r + 1][j] == '*')
        {
            keep = true;
            break;
        }
    if (!keep)
        del(curID);
}
void del(int id)
{
    for (Pos cur : p[id])
    {
        fill(txt[cur.x].begin() + cur.y, txt[cur.x].begin() + cur.y + sz[id], ' ');
        ntxt[cur.x][cur.y] = 0;
        int up = cur.x - 1;
        if (cur.x > 0 && cur.y < txt[up].size())
            // for (int i = cur.x; i < txt[up].size() && i < i + sz[id]; ++i)
            for (int i = cur.y; i < txt[up].size() && i < cur.y + sz[id]; ++i)
                if (isalpha(txt[up][i]))
                {
                    int j = i;
                    while (!ntxt[up][j])
                        --j;
                    tryDel(up, j);
                }
    }
}
int main()
{
    int t;
    cin >> t;
    string junk;
    getline(cin, junk);
    while (t--)
    {
        num.clear();
        p.clear();
        txt.clear();
        ntxt.clear();
        sz = {0};
        p = {vector<Pos>()};
        string line;
        while (getline(cin, line) && line[0] != '#')
        {
            vector<int> nums(line.size(), 0);
            for (int i = 0; i < line.size(); ++i)
                if (isalpha(line[i]))
                {
                    string cur(1, line[i]);
                    int j = i;
                    while (++i < line.size() && isalpha(line[i]))
                        cur += line[i];
                    p[id(cur)].push_back(Pos(txt.size(), j));
                    nums[j] = id(cur);
                }
            txt.push_back(line);
            ntxt.push_back(nums);
        }
        for (int curID : ntxt.back())
            if (curID)
                del(curID);
        for (int row = ntxt.size() - 2; row >= 0; --row)
            for (int i = 0; i < ntxt[row].size(); ++i)
                if (ntxt[row][i])
                    tryDel(row, i);
        for (string &str : txt)
            cout << str << "\n";
        cout << "#\n";
    }
}
