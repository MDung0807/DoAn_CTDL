#include <iostream>

#include <time.h>


double HashtableWithSizeDouble(int* arr, int n) {
    clock_t start, end;
    start = clock();
    int k = n * 2;
    int key;
    int* table = new int[k];
    for (int i = 0; i < k; i++)
        table[i] = -1;
    for (int i = 0; i < n; i++)
    {
        key = arr[i] % k;
        while (table[key] != -1)
        {
            if ((key + 1) < k)
            {
                key++;
            }
            else
            {
                key = 0;
            }

        }
        table[key] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x = arr[rand() % n];
        key = x % k;
        while (table[key] != -1 && table[key] != x)
        {
            if ((key + 1) < k)
            {
                key++;
            }
            else
            {
                key = 0;
            }
        }
    }
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    return time;
}

double HashtableWithSizeNotDouble(int* arr, int n) {
    clock_t start, end;
    start = clock();
    int k = n + 1 + rand() % (2 * n - (n + 1) - 2);
    int key;
    int* table = new int[k];
    for (int i = 0; i < k; i++)
        table[i] = -1;
    for (int i = 0; i < n; i++)
    {
        key = arr[i] % k;
        while (table[key] != -1)
        {
            if ((key + 1) < k)
            {
                key++;
            }
            else
            {
                key = 0;
            }

        }
        table[key] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x = arr[rand() % n];
        key = x % k;
        while (table[key] != -1 && table[key] != x)
        {
            if ((key + 1) < k)
            {
                key++;
            }
            else
            {
                key = 0;
            }
        }
    }
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    return time;
}
void main() {
    double sum = 0;
    double sum1 = 0;
    int n = 10;
    while (n <= 10000)
    {
        sum = 0;
        sum1 = 0;
        for (int r = 0; r < 100; r++)
        {

            int* arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand();
            }
            double step = HashtableWithSizeDouble(arr, n);
            sum += step;
            double step1 = HashtableWithSizeNotDouble(arr, n);
            sum1 += step1;
        }
        printf("n: %d\t", n);
        printf("With double Size: %000000f     ", (double)sum / 100);
        printf("\tWith not double size: %000000f\n", (double)sum1 / 100);
        n += 600;
    }
}