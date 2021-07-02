#include <stdio.h>
#include <stdbool.h>

/**
 * @brief utility method to return sum of square of digit of n
 * @param n int number
 * @return int
 */
int numSquareSum(int n)
{
    int squareSum = 0;
    while (n)
    {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

/**
 * @brief function return true if n is Happy number
 * @param n int number
 * @return int
 */
bool isHappyNumber(int n)
{
    int slow, fast;
    // initialize slow and fast by n
    slow = fast = n;
    do
    {
        //    move slow number by one iteration
        slow = numSquareSum(slow);
        //    move fast number by two iteration
        fast = numSquareSum(numSquareSum(fast));

    } while (slow != fast);
    // if both number meet at 1, then return true
    return (slow == 1);
}

int main(int argc, char const *argv[])
{
    int numberQnt;
    scanf("%d", &numberQnt);
    int entries[numberQnt];
    for (int i = 0; i < numberQnt; i++)
    {
        int number;
        scanf("%d", &number);
        entries[i] = number;
    }
    for (int i = 0; i < numberQnt; i++)
    {
        int entry = entries[i];
        bool isHappy = isHappyNumber(entry);
        printf("Entrada #%d: %d e um numero %s.\n", i + 1, entry, isHappy ? "feliz" : "infeliz");
    }

    return 0;
}
