/*  Name: Shakeel Sheriff M
    Batch : 24002
    Date: 28/11/2024
    Problem 4: Write a program to generate n random numbers and calculate the 5-point weighted moving average. 
    In a weighted moving average, each point in the window has a different weight. 
    Use the weights {1, 2, 3, 2, 1} for the 5-point window, where the center point has the highest weight.
    Input: Random Numbers = [10, 20, 30, 40, 50, 60, 70]
    Output: Weighted Moving Averages = [26, 36, 46]
    Input: Random Numbers = [5, 10, 15, 20, 25]
    Output: Weighted Moving Averages = [14]
*/
#include <stdio.h>
#define WINDOW_SIZE 5
#define WEIGHT_SUM 9 //sum of {1,2,3,2,1}

void calculate_weighted_avg(int arr[], int n);

int main(){
    int random_num[] = {10,20,30,40,50,60,70,80,90};
    int n = sizeof(random_num)/ sizeof(random_num[0]);
    calculate_weighted_avg(random_num, n);
    return 0;
}

void calculate_weighted_avg(int arr[], int n){
    int weights[] = {1,2,3,2,1};
    printf("Weighted Moving Average: ");
    
    for (int i = 0; i <= n - WINDOW_SIZE; i++){
        int weighted_sum = 0;

        for (int j = 0; j < WINDOW_SIZE; j++){
            weighted_sum += arr[i+j] * weights[j];
        }
        //Calculate Weighted Moving Average
        int weighted_avg = weighted_sum / WEIGHT_SUM;
        printf("%d ",weighted_avg);
    }
    printf("\n");
}