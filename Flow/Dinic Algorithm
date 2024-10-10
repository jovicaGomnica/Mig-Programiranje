#include<bits/stdc++.h>
using namespace std;

class GraphAdjListDinic
{
    vector<vector<int>> capacity, start_capacity;
    vector<vector<int>> adj;
    vector<int> level;
    int Num_Nodes;
public:
    GraphAdjListDinic(int nodes) : Num_Nodes(nodes)
    {
        adj.resize(nodes);
        capacity.resize(nodes, vector<int>(nodes, 0));
        start_capacity.resize(nodes, vector<int>(nodes, 0));
        level.resize(nodes);
    }

    void addEdge(int from, int to, int cap)
    {
        adj[from].push_back(to);
        adj[to].push_back(from);
        capacity[from][to] = cap;
        start_capacity[from][to] = cap;
    }

    bool bfs(int source, int sink)
    {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur])
            {
                if (level[next] == -1 && capacity[cur][next] > 0)
                {
                    level[next] = level[cur] + 1;
                    q.push(next);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int cur, int sink, int flow, vector<int>& start)
    {
        if (cur == sink) return flow;

        for (; start[cur] < adj[cur].size(); start[cur]++)
        {
            int next = adj[cur][start[cur]];

            if (level[next] == level[cur] + 1 && capacity[cur][next] > 0)
            {
                int new_flow = dfs(next, sink, min(flow, capacity[cur][next]), start);
                if (new_flow > 0)
                {
                    capacity[cur][next] -= new_flow;
                    capacity[next][cur] += new_flow;
                    return new_flow;
                }
            }
        }
        return 0;
    }

    int solveDinic(int source, int sink)
    {
        capacity = start_capacity;
        int total_flow = 0;

        while (bfs(source, sink))
        {
            vector<int> start(Num_Nodes, 0);
            while (int flow = dfs(source, sink, INT_MAX, start))
            {
                total_flow += flow;
            }
        }
        return total_flow;
    }
};

int main()
{
    GraphAdjListDinic g(6);
    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);

    cout << "Dinic's Algorithm: " << g.solveDinic(0, 5) << endl;

    return 0;
}
