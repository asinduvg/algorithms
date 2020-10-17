#include<stdio.h>

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

int main() {

    int arr[] = {2, 3, 7, 1, 4, 5};
    int sum = 7;

    /*
        Algorithm:-
            count = including + excluding
                  = (dp[i - 1][j - arr[i]]) + (dp[i - 1][j])
    */

   int length = LEN(arr);
   int dp[length][sum + 1];
   int i, j;


   for(j = 0; j <= sum; j++) {
       if(arr[0] == j) {
           dp[0][j] = 1;
       } else {
           dp[0][j] = 0;
       }
   }

    for(i = 0; i < length; i++) {
       dp[i][0] = 1;
   }

   for(i = 1; i < length; i++) {
       for(j = 1; j <= sum; j++) {
           
           if(arr[i] > j) {
               dp[i][j] = dp[i - 1][j]; //excluding the value
           } else {
               dp[i][j] = dp[i - 1][j - arr[i]] + dp[i - 1][j]; // including and excluding
           }

       }
   }

    for(i = 0; i < length; i++) {
        for(j = 0; j < sum + 1; j++) {
            printf("%d ", dp[i][j]);
        }
        puts("");
    }

    printf("\nThe count is: %d", dp[length - 1][sum]);

    return 0;

}