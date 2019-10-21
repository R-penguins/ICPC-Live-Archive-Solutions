/**
 * Points
 * 2004 Tehran
 */
#include <bits/stdc++.h>
using namespace std;
struct Axis
{
    int n;
    vector<int> val, sz, vis;
    vector<vector<bool>> g;
    Axis(int n) : n(n), val(n + 1), sz(n + 1, 1), vis(n + 1, 0),
                  g(n + 1, vector<bool>(n + 1, false))
    {
        iota(val.begin(), val.end(), 0);
    }
    int fin(int i)
    {
        while (i != val[i])
        {
            val[i] = val[val[i]];
            i = val[i];
        }
        return i;
    }
    void uni(int i, int j)
    {
        int ir = fin(i), jr = fin(j);
        if (ir == jr)
            return;
        if (sz[ir] > sz[jr])
        {
            swap(ir, jr);
            swap(i, j);
        }
        val[ir] = jr;
        sz[jr] += sz[ir];
        for (int k = 1; k <= n; ++k)
            g[jr][k] = g[jr][k] || g[ir][k];
    }
    void relate(int i, int j)
    {
        int ir = fin(i), jr = fin(j);
        g[ir][jr] = true;
    }
    bool dfs(int i)
    {
        vis[i] = -1;
        for (int k = 1; k <= n; ++k)
            if (g[i][k])
            {
                int rk = fin(k);
                if (vis[rk] < 0 || !dfs(rk))
                    return false;
            }
        vis[i] = 1;
        return true;
    }
    bool tsort()
    {
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && !dfs(i))
                return false;
        return true;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Axis x(n), y(n);
        while (m--)
        {
            int i, j;
            string rel;
            cin >> i >> rel >> j;
            // x axis
            if (rel == "N" || rel == "S")
                x.uni(i, j);
            else if (rel.back() == 'E')
                x.relate(i, j);
            else
                x.relate(j, i);
            // y axis
            if (rel == "E" || rel == "W")
                y.uni(i, j);
            else if (rel.front() == 'N')
                y.relate(i, j);
            else
                y.relate(j, i);
        }
        if (x.tsort() && y.tsort())
            cout << "POSSIBLE\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}
