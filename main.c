#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>

typedef unsigned long long ull;

struct timeval stop1, start1;
struct timeval stop2, start2;

// fib(position) = O(n) (bottom up)
ull fib(ull n)
{
    if(n < 1L)
        return 0L;
    else if(n == 1L)
        return 1L;
    else // > 1
    {
        ull i, p1 = 0L, p2 = 0L, s = 1L;
        for(i = 2L; i <= n; i++)
        {
            p1 = s;
            s = p1 + p2;
            p2 = p1;
        }
        return s;
    }
}

// fib2(position) = O(2^n) (recurse)
ull fib2(ull n)
{
    ull r = 0L; // O(1)
    if(n == 1L || n == 2L) // O(1)
        r = 1L; // O(1)
    else
        r = fib2(n - 1L) + fib2(n - 2L); // O(2^n)
    return r;
}

// fac(n) = O(1) + n * O(1)
// fac(n) = n * O(1)
// fac(n) = O(n)
ull fac(ull n)
{
    if(n <= 1) return 1; // O(1)
    else
        return n * fac(n - 1); // n * O(1)
}

int main() {
    ull i;

    gettimeofday(&start1, NULL);
    for(i = 1; i <= 42; i++) {
        printf("fib %llu = %llu\n", i, fib(i));
    }
    gettimeofday(&stop1, NULL);
    printf("took %lu\n", stop1.tv_usec - start1.tv_usec);


    gettimeofday(&start2, NULL);
    for(i = 1; i <= 42; i++) {
            printf("fib2 %llu = %llu\n", i, fib2(i));
        }
    gettimeofday(&stop2, NULL);
    printf("took %lu\n", stop2.tv_usec - start2.tv_usec);

    getch();
    return 0;
}
