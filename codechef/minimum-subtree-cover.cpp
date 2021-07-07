#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> adj(n + 1, vector<int>());
	vector<int> visited(n + 1, 0);
	vector<vector<pair<int, int>>> height_data(n + 1, vector<pair<int, int>>());
	vector<int> height_source(n + 1, -1);
	vector<int> parent(n + 1, -1);

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int longest_path = 0;
	int path_start = -1;
	int path_end = -1;

	stack<int> S;
	int test_root;
	for (int i = 0; i < adj.size(); ++i)
	{
		if (adj[i].size() > 1)
		{
			test_root = i;
			S.push(test_root);
			break;
		}
	}

	cout << "TEST_ROOT: " << test_root << endl;

	while (!S.empty())
	{
		int u = S.top();
		cout << "    U: " << u << endl;
		S.pop();

		visited[u] = 1;

		if (adj[u].size() == 1)
		{ // leaf
			// backtrack up
			int height = 1;
			int source = u;
			bool must_update = true;
			while (must_update)
			{
				if (height_data[u].size() > 0)
				{ // Already exists another path to node, check if we are better option
					if (height <= height_data[u][0].first)
						must_update = false;
				}

				height_data[u].push_back({height, source});
				sort(height_data[u].begin(), height_data[u].end(), std::greater<pair<int, int>>());

				// TODO: longest path potentially here...
				if (height_data[u].size() > 1 && must_update)
				{
					int path_length = height_data[u][0].first + height_data[u][1].first - 1;
					if (path_length > longest_path)
					{
						longest_path = path_length;
						path_start = height_data[u][0].second;
						path_end = height_data[u][1].second;
					}
				}

				if (u == test_root)
					break;

				u = parent[u];
				++height;
			}
		}
		else
		{ // not a leaf
			for (int v : adj[u])
			{
				if (!visited[v])
				{
					parent[v] = u;
					S.push(v);
				}
			}
		}
	}

	cout << "path length: " << longest_path << endl;
	cout << "path start: " << path_start << endl;
	cout << "path end: " << path_end << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cout << endl
			 << "====" << endl
			 << endl;
		solve();
	}
}