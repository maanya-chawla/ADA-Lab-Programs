#include <stdio.h>

#define MAX 10
#define L -1
#define R 1

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, a[MAX], dir[MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = L;
    }

    print(a, n);

    while (1) {
        int mobile = 0, pos = -1;

        // find largest mobile
        for (int i = 0; i < n; i++) {
            if (dir[i] == L && i > 0 &&
                a[i] > a[i-1] && a[i] > mobile) {
                mobile = a[i];
                pos = i;
            }

            if (dir[i] == R && i < n-1 &&
                a[i] > a[i+1] && a[i] > mobile) {
                mobile = a[i];
                pos = i;
            }
        }

        if (mobile == 0)
            break;

        int next = pos + dir[pos];

        // swap
        int t = a[pos];
        a[pos] = a[next];
        a[next] = t;

        t = dir[pos];
        dir[pos] = dir[next];
        dir[next] = t;

        // reverse larger elements
        for (int i = 0; i < n; i++)
            if (a[i] > mobile)
                dir[i] *= -1;

        print(a, n);
    }

    return 0;
}
