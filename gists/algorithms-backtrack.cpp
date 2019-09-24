#include <iostream>
#include <vector>

void print(std::vector<int>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[sol.size() - i - 1];
    }
    std::cout << std::endl;
}

void permutate(int n, int l, int k, std::vector<int>& sol) {
    if (k == l) {
        print(sol);
    } else {
        for (int i = 1; i <= n; i++) {
            sol[l - k - 1] = i;
            permutate(n, l, k+1, sol);
        }
    }
}

int main() {
    std::vector<int> solutions(5);
    permutate(5, 5, 0, solutions);
    return 0;
}

\begin{algorithmic}[1]
\Function{Sequence\_BruteForce}{A, n, l, k}
\If{$k = l$}
\State print(Solution)
\Else
\For{$i = 1$ to $n$}
\State $A[l - k] = i$
\State Sequence\_BruteForce(A, n, l, k + 1)
\EndFor
\EndIf
\EndFunction
\end{algorithmic}