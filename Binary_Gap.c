/*
 * This is my solution to this task. 
 * https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
 */

#include <stdio.h>

int solution(int N) {
    int arr[32] = {0}, startCounting = 0, countA = 0, countB = 0;

    // converting the integer to binary
    for (int i = 0; i < 32; i++) {
        arr[(31 - i)] = ((N >> i) & 1) ? 1 : 0;
    }

    /*
    printf("Binary eq. of %d \n\t", N);
    for (int i = 0; i < 32; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    */
    
    for (int i = 0; i < 32; i++) {

        if (arr[i] == 1 && startCounting == 0) {
            // start counting when 1 is found and counting had not started
            startCounting = 1;
            
        } else if (arr[i] == 0 && startCounting == 1) {
            // if found 0 and counting had started, than increase count
            countB++;
            
        } else if (arr[i] == 1 && startCounting == 1) {
            // Restart counting, if found 1 while counting was started
            // check if current count is the biggest
            countA = countA > countB ? countA : countB;
            
            // counting again, since 1 was found
            startCounting = 1;
            
            // reset counter
            countB = 0;
        }
    }

    return countA;
}

int main() {
    // testing with few different digits
    printf("Gap length: %d\n", solution(9));
    printf("Gap length: %d\n", solution(15));
    printf("Gap length: %d\n", solution(200));
    printf("Gap length: %d\n", solution(3256));
    printf("Gap length: %d\n", solution(52369));
    printf("Gap length: %d\n", solution(104128));
    return 0;
}

