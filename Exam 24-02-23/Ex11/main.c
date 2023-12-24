#include <stdio.h>

void searchSubArray(float *v, int n, int k) {
    float maxSum = 0.0;
    float maxDiff = 0.0;
    int maxSumIndex = 0;
    int maxDiffIndex_start = 0;
    int maxDiffIndex_end = 0;

    for (int i = 0; i <= n - k; i++) {
        float sum = v[i];
        float diff = 0.0;
        for (int j = i+1; j < i + k; j++) {
            sum += v[j];
            diff= v[i] -v[j];
            if (diff > maxDiff){
                maxDiff=diff;
                maxDiffIndex_start=i;
                maxDiffIndex_end=j; //not needed for the exercise spec.
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxSumIndex = i;
        }
    }

    printf("Maximum sum subarray: ");
    for (int i = maxSumIndex; i < maxSumIndex + k; i++) {
        printf("%f ", v[i]);
    }
    printf("(Sum: %f)\n", maxSum);

    printf("Maximum difference subarray: ");
    for (int i = maxDiffIndex_start; i < maxDiffIndex_start + k; i++) {
        printf("%f ", v[i]);
    }
    printf("(Difference: %f)\n", maxDiff);
}

int main() {
    int n = 10;
    int k = 3;
    float v[] = {12.5, 2.1, 3.3, 4.1, 5.4, 6.2, 7.9, 8.3, -9.9, 5.1};

    searchSubArray(v, n, k);

    return 0;
}
