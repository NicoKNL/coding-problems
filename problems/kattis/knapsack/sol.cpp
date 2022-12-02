#include <vector>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
struct Item
{
    size_t id;           // Identifier for the client
    T value;             // Value of the item
    unsigned int weight; // Weight of the item
};

template <typename T>
struct Solution
{
    T value;                     // Total value of chosen items
    unsigned int weight;         // Total weight of chosen items
    vector<size_t> chosen_items; // Item identifiers
};

template <typename T>
Solution<T> knapsack(const vector<Item<T>> &items,
                     const unsigned int capacity)
{
    /* Knapsack solver for positive, integer weights.
     * $O(N\cdot capacity)$. */
    Solution<T> solution{};
    vector<T> max_value(capacity + 1);
    vector<vector<bool>> items_used(
        capacity + 1, vector<bool>(items.size()));

    /* Build solution by considering items with index <= n,
     * and increasing n */
    for (size_t n = 0; n < items.size(); n++)
    {
        for (unsigned int m = capacity; m > 0; m--)
        {
            if (m >= items[n].weight)
            {
                /* If (new) item n fits, then: */
                if (max_value[m] < (max_value[m - items[n].weight] +
                                    items[n].value))
                {
                    /* Add it if it improves the value */
                    max_value[m] = max_value[m - items[n].weight] +
                                   items[n].value;
                    items_used[m][n] = true;
                };
            };
        }
    }

    /* Backtrack to reconstruct the selected items */
    solution.value = max_value[capacity];
    int m = capacity;
    for (int n = items.size() - 1; n >= 0; n--)
    {
        if (items_used[m][n])
        {
            solution.chosen_items.push_back(items[n].id);
            solution.weight += items[n].weight;
            m -= items[n].weight;
        }
    }

    return solution;
}

int main()
{
    int cap, n;
    while (cin >> cap >> n)
    {
        vector<Item<int>> items(n);
        for (int i = 0; i < n; ++i)
        {
            items[i].id = i;
            cin >> items[i].value >> items[i].weight;
        }

        auto sol = knapsack(items, cap);
        sort(sol.chosen_items.begin(), sol.chosen_items.end());

        cout << sol.chosen_items.size() << endl;
        for (int i = 0; i < sol.chosen_items.size(); ++i)
        {
            if (i > 0)
                cout << " ";
            cout << sol.chosen_items[i];
        }
        cout << endl;
    }
}