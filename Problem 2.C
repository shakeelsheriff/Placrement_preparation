/*  Name: Shakeel Sheriff M
    Batch : 24002
    Date: 25/11/2024
    Problem 2: Take a 2D array int a[m][n], write a function to replace each element of the array
    with the 5th prime number starting from the corresponding array element.
*/
#include <stdio.h>
#include <stdbool.h>

void print_arr(int m, int n, int arr[m][n]);
void replace_with_fifth_prime(int m, int n, int arr[m][n]);
int next_prime(int start_value);
bool is_prime(int num);
int main()
{
    int m, n;
    // Getting Array Elements from the User
    printf("Enter no. of Rows and Columns (m & n): ");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    printf("Enter all %d 2D Array Elements one by one: \n", m * n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print Original Array
    printf("Original array:\n");
    print_arr(m, n, arr);

    // Replace with the 5th prime number starting from each element
    replace_with_fifth_prime(m, n, arr);

    // Print modified array
    printf("\nModified array:\n");
    print_arr(m, n, arr);

    return 0;
}

bool is_prime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int next_prime(int start_value)
{
    while (!is_prime(start_value))
    {
        start_value++;
    }
    return start_value;
}

void replace_with_fifth_prime(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int start_value = arr[i][j];
            int prime = next_prime(start_value); // First prime

            // To find next 5 primes
            for (int k = 0; k < 4; k++) // Find next 4 primes (since we already found 1 prime)
            {
                prime = next_prime(prime + 1);
            }

            // Replace with the 5th prime
            arr[i][j] = prime;
        }
    }
}

void print_arr(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}