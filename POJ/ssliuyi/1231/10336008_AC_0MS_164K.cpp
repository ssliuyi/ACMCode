#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct rect {
    int left, right, top, bottom;
    int rank_x;
} rec[32];
int T, K, P;

int cmp_x(const void *a, const void *b)
{
    return ((struct rect *)a)->left - ((struct rect *)b)->left;
}

int cmp_y(const void *a, const void *b)
{
    return ((struct rect *)a)->top - ((struct rect *)b)->top;
}

inline int solve()
{
    int i, last, rank, mask;

    qsort(rec, K, sizeof(rec[0]), cmp_x);
    rank = 0;
    for (i = 0; i < K; ) {
        last = rec[i].right;
        while (i < K && rec[i].left <= last) {
            rec[i].rank_x = rank;
            last = max(last, rec[i].right);
            i++;
        }
        rank++;
    }

    qsort(rec, K, sizeof(rec[0]), cmp_y);
    for (i = 0; i < K; ) {
        mask = 0;
        last = rec[i].bottom;
        while (i < K && rec[i].top <= last) {
            if (mask & (1 << rec[i].rank_x))
                return 0;
            mask |= 1 << rec[i].rank_x;
            last = max(last, rec[i].bottom);
            i++;
        }
    }

    return 1;
}

int main()
{
    int i, j, x, y;

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &K, &P);
        for (i = 0; i < K; i++) {
            rec[i].left = rec[i].top = 1000000;
            rec[i].right = rec[i].bottom = 0;
            for (j = 0; j < P; j++) {
                scanf("%d%d", &x, &y);
                if (x < rec[i].left)
                    rec[i].left = x;
                if (x > rec[i].right)
                    rec[i].right = x;
                if (y < rec[i].top)
                    rec[i].top = y;
                if (y > rec[i].bottom)
                    rec[i].bottom = y;
            }
        }
        printf("%s\n", solve() ? "YES" : "NO");
    }

    return 0;
}

