#include <iostream>
using namespace std;

#include <stdio.h> // C style input and output

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

// largest value <= key
// Invariant:   A[l] <= key and A[r] > key
// Boundary:    |r - l| = 1
// Input:       A[l .... r-1]
// Precondition: A[l] <= key <= A[r]
int Floor(int A[], int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;

        if( A[m] <= key )
            l = m;
        else
            r = m;
    }

    return A[l];
}

int Floor(int A[], int size, int key) {
    // Error checking
    if( key < A[0] )
        return -1; // There is no floor value

    return Floor(A, 0, size, key);
}

void TestCase_01() {
    int A[] = { 1, 3, 4, 7, 9, 13, 18, 23 };
    int size = ARRAY_SIZE(A);

    int key;

    scanf("%d", &key);

    while( key != -1 ) {
        printf("%d\n", Floor(A, size, key));
        scanf("%d", &key);
    }
}

int main() {
    TestCase_01();
    
    return 0;
}
