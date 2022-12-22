// WAP to sort rows of a matrix having m rows and n columns in ascending & columns in descending order
#include <stdio.h>
int main()
{
    int row, col, t, i, j, k;
    printf("Enter number of rows- ");
    scanf("%d", &row);
    printf("Enter number of columns- ");
    scanf("%d", &col);
    int arr[row][col];
    int n = row * col;
    printf("Enter elements- ");
    for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
                {
                    scanf("%d", &arr[i][j]);
                }
        }
    i = 0;
    for (j = 0; j < col; j++)
        {
            for (k = i + 1; k < row; k++)
                {
                    for (t = k; t < row; t++)
                        {
                            if (arr[i][j] < arr[t][j])
                                {
                                    int temp = arr[i][j];
                                    arr[i][j] = arr[t][j];
                                    arr[t][j] = temp;
                                }
                        }
                    i++;
                }
            i = 0;
        }
    j = 0;
    for (i = 0; i < row; i++)
        {
            for (k = j + 1; k < col; k++)
                {
                    for (t = k; t < col; t++)
                        {
                            if (arr[i][j] > arr[i][t])
                                {
                                    int temp = arr[i][j];
                                    arr[i][j] = arr[i][t];
                                    arr[i][t] = temp;
                                }
                        }
                    j++;
                }
            j = 0;
        }
    for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
                {
                    printf("%d ", arr[i][j]);
                }
            printf("\n");
        }
    return 0;
}