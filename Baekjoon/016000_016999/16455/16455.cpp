#include <bits/stdc++.h>

template <typename T> inline T min(T a, T b) {
    return a < b ? a : b ;
}

int kth(std::vector<int> &a, int k) {
    const int MaxN = 1000000000;
    const int MaxDiv = 50000;

    int radix[MaxDiv]={0,}, order [MaxDiv]={0,};
    int i;
    int idx_radix, idx_order ;

    for ( i = a.size() - 1 ; i >= 0 ; i -- ) {
        a[ i ] += MaxN ;
        radix[ a[i] / MaxDiv ] ++ ;
    }

    for ( i = 0 ; radix[ i ] < k ; i ++) {
        k -= radix[ i ] ;
    }
    idx_radix = i;

    for ( i = a.size() - 1 ; i >= 0 ; i --) {
        if ( a[i] / MaxDiv == idx_radix ) {
            order[ a[i] % MaxDiv ] ++;
        }
    }
    for ( i = 0 ; order[i] < k ; i ++) {
        k -= order[ i ];
    }
    idx_order = i;

    return idx_order - MaxN + idx_radix * MaxDiv;
}

int main() {
    int i ;
    for ( i = 1 ; i <= 9 ; i ++)
    {
        std::vector<int> A {5, 6, 4, 3, 2, 6, 7, 9, 3};
        printf("%d\n", kth(A, i));
    }
}