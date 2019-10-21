/**
 * Food Cubes
 * 2004 Tehran
 */
#include <bits/stdc++.h>
using namespace std;
struct Pos
{
    int x, y, z;
    Pos(int x, int y, int z) : x(x), y(y), z(z) { }
    Pos step(Pos dir)
    {
        return Pos(x + dir.x, y + dir.y, z + dir.z);
    }
    bool valid()
    {
        return 0 <= x && x <= 101 && 0 <= y && y <= 101 && 0 <= z && z <= 101;
    }
};
const array<Pos, 6> DIRS {Pos(1, 0, 0), Pos(-1, 0, 0), Pos(0, 1, 0), Pos(0, -1, 0), Pos(0, 0, 1), Pos(0, 0, -1)};
vector<vector<vector<int>>> g;
void dfs(Pos cur)
{
    g[cur.x][cur.y][cur.z] = 2;
    for (Pos dir : DIRS)
    {
        Pos next = cur.step(dir);
        if (next.valid() && g[next.x][next.y][next.z] == 0)
            dfs(next);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        g = vector<vector<vector<int>>>(102, vector<vector<int>>(102, vector<int>(102, 0)));
        for (int i = 0; i < m; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[x][y][z] = 1;
        }
        queue<Pos> q;
        q.push(Pos(0, 0, 0));
        g[0][0][0] = -1;
        while (!q.empty())
        {
            Pos cur = q.front();
            q.pop();
            for (Pos dir : DIRS)
            {
                Pos next = cur.step(dir);
                if (next.valid() && g[next.x][next.y][next.z] == 0)
                {
                    g[next.x][next.y][next.z] = -1;
                    q.push(next);
                }
            }
        }
        int ans = 0;
        for (int x = 1; x <= 100; ++x)
            for (int y = 1; y <= 100; ++y)
                for (int z = 1; z <= 100; ++z)
                    if (g[x][y][z] == 0)
                    {
                        dfs(Pos(x, y, z));
                        ++ans;
                    }
        cout << ans << "\n";
    }
}
