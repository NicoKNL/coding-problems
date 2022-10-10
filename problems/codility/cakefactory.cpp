#include <bits/stdc++.h>

using namespace std;

struct InstructionTree;

InstructionTree * newIT(int start, int end, int flavor);


struct InstructionTree
{
    int start;
    int end;
    int flavor;
    int valid;
    vector<InstructionTree *> children;

    static bool compareIT(InstructionTree * lhs, InstructionTree * rhs) { return lhs->start < rhs->start; };

    bool isExitEvent(int lhs, int rhs, InstructionTree * t)
    {
        return t->start <= lhs && lhs <= t->end && rhs > t->end;
    }

    bool isEnterEvent(int lhs, int rhs, InstructionTree * t)
    {
        return t->start <= rhs && rhs <= t->end && lhs < t->start;
    }

    bool isCrossEvent(int lhs, int rhs, int child_i, vector<InstructionTree *> & children)
    {
        if (child_i + 1 >= children.size() || lhs == rhs) return false;

        InstructionTree * l_child = children[child_i];
        InstructionTree * r_child = children[child_i + 1];

        return lhs == l_child->end && rhs == r_child->start;
    }

    void insert(InstructionTree * t)
    {
        if (!valid) return;
        if (children.size() == 0) return children.emplace_back(t);

        vector<InstructionTree *> new_children;

        // TODO: find closest child

        int child_i = 0;
        int lhs = t->start;

        for (int i = 0; i < children.size(); ++i)
        {
            if (children[child_i]->end < lhs) child_i = min(child_i + 1, (int) children.size() - 1);
            else break;
        }
        int rhs;

        for (rhs = t->start; rhs <= t->end; ++rhs)
        {
            InstructionTree * child = children[child_i];

            if (isEnterEvent(lhs, rhs, child))
            {
                InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
                new_children.emplace_back(new_t);
                new_t->valid = (flavor - 1 == t->flavor);
                lhs = rhs;
            }
            else if (isCrossEvent(lhs, rhs, child_i, children))
            {
                InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
                child->insert(new_t);

                lhs = rhs;
                ++child_i;
            }
            else if (isExitEvent(lhs, rhs, child))
            {
                InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
                child->insert(new_t);

                lhs = rhs;
                if (child_i + 1 < children.size()) ++child_i;
            }

        }

        // Consider "tail" and "inside" cases
        if (children[child_i]->start <= lhs && rhs - 1 <= children[child_i]->end) {
            InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
            children[child_i]->insert(new_t);
        }
        else if (start <= lhs && rhs - 1 <= end)
        {
            InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
            new_children.emplace_back(new_t);
            new_t->valid = (flavor - 1 == t->flavor);
        }
        else if (lhs > children[child_i]->start)
        {
            InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
            new_children.emplace_back(new_t);
            new_t->valid = (flavor - 1 == t->flavor);
        }
        else
        {
            InstructionTree * new_t = newIT(lhs, rhs - 1, t->flavor);
            children[child_i]->insert(new_t);
        }

        delete t;

        if (new_children.size() > 0) children.insert(children.end(), new_children.begin(), new_children.end());

        sort(children.begin(), children.end(), compareIT);
    }

    void markCakes(vector<int> & tracker)
    {
        if (children.size() == 0 && flavor == 1)
        {
            for (int i = start; i <= end; ++i)
            {
                tracker[i] = 1;
            }
        }
        else
        {
            for (auto child : children)
            {
                if (child->flavor == flavor - 1)
                {
                    child->markCakes(tracker);
                }
            }
        }

        // Consider scenarios where we DO have children, but not for all "cakespots"
        if (flavor == 1)
        {
            int min_child_i = 0;

            for (int i = start; i <= end; ++i)
            {
                bool found = false;
                for (int ii = min_child_i; ii < children.size(); ++ii)
                {
                    InstructionTree * child = children[ii];

                    if (child->start <= i && i <= child->end)
                    {
                        i = child->end;
                        min_child_i = ii;
                        found = true;
                        break;
                    }
                }

                if (!found) tracker[i] = 1;
            }
        }
    }
};


bool sufficientAvailableFlavors(int K, vector<int> & C)
{
    set<int> flavorset;
    for (const int & f : C) flavorset.insert(f);
    return flavorset.size() == K;
}

InstructionTree * newIT(int start, int end, int flavor)
{
    InstructionTree * t = new InstructionTree();

    t->start  = start;
    t->end    = end;
    t->flavor = flavor;
    t->valid  = true;

    return t;
}

InstructionTree * buildInstructionTree(int K, vector<int> & A, vector<int> & B, vector<int> & C)
{
    InstructionTree * root = newIT(0, 100001, K + 1);

    for (int i = C.size() - 1; i >= 0; --i)
    {
        InstructionTree * t = newIT(A[i], B[i], C[i]);
        root->insert(t);
    }

    return root;
}

int solution(int N, int K, vector<int> &A, vector<int> &B, vector<int> &C)
{
    // TODO: necessary?
    if (!sufficientAvailableFlavors(K, C)) return 0;

    InstructionTree * t = buildInstructionTree(K, A, B, C);

    vector<int> tracker(100001, 0);
    t->markCakes(tracker);

    return accumulate(tracker.begin(), tracker.end(), 0);
}

int main()
{
    // case 1
//    int N = 5;
//    int K = 3;
//    vector<int> A = {1, 1, 4, 1, 4};
//    vector<int> B = {5, 2, 5, 5, 4};
//    vector<int> C = {1, 2, 2, 3, 3};

// case 2
//    int N = 6;
//    int K = 4;
//    vector<int> A = {1, 2, 1, 1};
//    vector<int> B = {3, 3, 6, 6};
//    vector<int> C = {1, 2, 3, 4};

// case example issue with my code
//    int N = 3;
//    int K = 1;
//    vector<int> A = {1, 2};
//    vector<int> B = {2, 3};
//    vector<int> C = {1, 1};

// case
    int N = 10;
    int K = 2;
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> B = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> C = {1, 1, 1, 1, 1, 1, 1, 1, 1,  1};
    cout << solution(N, K, A, B, C) << endl;
    return 0;
}
