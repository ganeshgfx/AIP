#include <stdio.h>
#include <stdlib.h>
int difference(int A[3][3], int B[3][3]);
int alter(int A[3][3], int B[3][3]);
int diffup(int A[3][3], int B[3][3]);
int diffdown(int A[3][3], int B[3][3]);
int diffleft(int A[3][3], int B[3][3]);
int diffright(int A[3][3], int B[3][3]);
int minimum(int a, int b, int c, int d);
void display(int A[3][3]);
int main()
{
    int A[3][3] = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}}; // the initial array
    int B[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
    int i, j;
    int d; // difference between the desired array anfd the test array
    int steps = 0;
    printf("Target: \n");
    display(B);
    printf("Original: \n");
    display(A);
    while (1)
    {
        d = difference(A, B);
        if (d == 0)
        {
            printf("TARGET ACHIEVED AT STEP: %d", steps);
            system("PAUSE");
            break;
        }
        steps++;
        printf("\nStep: %d \n", steps);
        alter(A, B); // changes the array according to whichever suitable
        display(A);
        system("PAUSE");
    }
    return 0;
}
void display(int A[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}
int difference(int A[3][3], int B[3][3])
{
    int counter = 0, i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (A[i][j] != B[i][j])
                counter++;
    return counter;
}
int alter(int A[3][3], int B[3][3])
{
    int dup, ddown, dleft, dright;
    int sel, min, temp, i, j, serial = 0;
    char change, ran[4];
    dup = diffup(A, B);
    ddown = diffdown(A, B);
    dleft = diffleft(A, B);
    dright = diffright(A, B);
    printf("%d %d %d %d\n", dright, dleft, dup, ddown);
    min = minimum(dup, ddown, dleft, dright);
    printf("%d\n", min);
    if (min == dright)
        ran[serial++] = 'r';
    if (min == dleft)
        ran[serial++] = 'l';
    if (min == dup)
        ran[serial++] = 'u';
    if (min == ddown)
        ran[serial++] = 'd';
    sel = rand() % serial;
    change = ran[sel];
    if (change == 'r')
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (A[i][j] == 0)
                {
                    A[i][j] = A[i][j + 1];
                    A[i][j + 1] = 0;
                    printf("right\n");
                    return 0;
                }
            }
        }
    }
    else if (change == 'l')
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 1; j < 3; j++)
            {
                if (A[i][j] == 0)
                {
                    A[i][j] = A[i][j - 1];
                    A[i][j - 1] = 0;
                    printf("left\n");
                    return 0;
                }
            }
        }
    }
    else if (change == 'u')
    {
        for (i = 1; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (A[i][j] == 0)
                {
                    A[i][j] = A[i - 1][j];
                    A[i - 1][j] = 0;
                    printf("up\n");
                    return 0;
                }
            }
        }
    }
    else if (change == 'd')
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (A[i][j] == 0)
                {
                    A[i][j] = A[i + 1][j];
                    A[i + 1][j] = 0;
                    printf("down\n");
                    return 0;
                }
            }
        }
    }
    return 0;
}
int diffup(int A[3][3], int B[3][3])
{
    int temp[3][3], i, j;
    for (i = 0; i < 3; i++) // copying the array A in array temp for testing
    {
        for (j = 0; j < 3; j++)
            temp[i][j] = A[i][j];
    }
    for (i = 1; i < 3; i++) // swapping the space in upward direction
    {
        for (j = 0; j < 3; j++)
        // starting the array from i=1 insures that the condition i=0 avoided
        {
            if (A[i][j] == 0)
            {
                temp[i - 1][j] = 0;
                temp[i][j] = A[i - 1][j];
            }
        }
    }
    return difference(temp, B);
}
int diffdown(int A[3][3], int B[3][3])
{
    int temp[3][3], i, j;
    for (i = 0; i < 3; i++) // copying the array A in array temp for testing
    {
        for (j = 0; j < 3; j++)
            temp[i][j] = A[i][j];
    }
    for (i = 0; i < 2; i++) // swapping the space in downward direction
    {
        for (j = 0; j < 3; j++) // ending at i=1 insures that the condition i=0 avoided
        {
            if (A[i][j] == 0)
            {
                temp[i + 1][j] = 0;
                temp[i][j] = A[i + 1][j];
            }
        }
    }
    return difference(temp, B);
}
int diffleft(int A[3][3], int B[3][3])
{
    int temp[3][3], i, j;
    for (i = 0; i < 3; i++) // copying the array A in array temp for testing
    {
        for (j = 0; j < 3; j++)
            temp[i][j] = A[i][j];
    }
    for (i = 0; i < 3; i++) // swapping the space in the left direction
    {
        for (j = 1; j < 3; j++)
        {
            if (A[i][j] == 0)
            {
                temp[i][j - 1] = 0;
                temp[i][j] = A[i][j - 1];
            }
        }
    }
    return difference(temp, B);
}
int diffright(int A[3][3], int B[3][3])
{
    int temp[3][3], i, j;
    for (i = 0; i < 3; i++) // copying the array A in array temp for testing
    {
        for (j = 0; j < 3; j++)
            temp[i][j] = A[i][j];
    }
    for (i = 0; i < 3; i++) // swapping the space in the right direction
    {
        for (j = 0; j < 2; j++)
        {
            if (A[i][j] == 0)
            {
                temp[i][j + 1] = 0;
                temp[i][j] = A[i][j + 1];
            }
        }
    }
    return difference(temp, B);
}
int minimum(int a, int b, int c, int d)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;
    return min;
}
