/*
 * This is solution to this task. 
 * https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
 */

#include <stdio.h>

struct Results {
    int *A;
    int N; // Length of the array
};

struct Results solution(int A[], int N, int K) {
    struct Results result;
    result.A = A;
    result.N = N;
    
    printf("N:%d, K:%d, rotating only K mod N = %d times\n", N, K, (K % N));
    
    K = K % N; // rotating an array of size for e.g. 5 is same as rotating it 0 times

    if(K > 0 && result.N > 0) {
        for (int i = 0; i < K; i++) {
            int tmp = result.A[(result.N-1)];
            for (int j = (result.N-1); j > 0; j--) {
                result.A[j] = result.A[j-1];
            }
            result.A[0] = tmp;
        }
    }

    return result;
}
int main() {
    
    int A[] = {1,2,3,4,5}; // example array
//    int A[] = {5,4,3,2,1};
//    int A[] = {3, 8, 9, 7, 6};
    
    int N = sizeof (A)/sizeof (int);
    int K = 1;

    struct Results RES;
    
    printf("Before rotation\n");
    printf("\t");
    for (int i = 0; i < N; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    
    RES = solution(A, N, K);

    printf("After rotating %d time right\n", K);
    printf("\t");
    for (int i = 0; i < RES.N; i++) {
        printf("%d ",RES.A[i]);
    }
    printf("\n");
    
    return 0;
}

