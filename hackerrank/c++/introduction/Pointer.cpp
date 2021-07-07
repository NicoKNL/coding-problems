#include <stdio.h>
#include <cstdlib>
using namespace std;

void update(int *a,int *b) {
    // Complete this function
    int tmp_a = *a + *b;

    (*b) = abs(*a - *b);
    (*a) = tmp_a;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

