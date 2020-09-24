#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, first = -1, last = -1;
    float sum1 = 0, sum2 = 0;
    float arr[100];

    printf("Введите размерность массива: ");
    scanf_s("%d", &n);
    printf("Введите массив: ");
    for (int i = 0; i < n; i++) scanf_s("%f", &arr[i]);

    printf("Массив: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    for (int j = 0; j < n; j++)
    {
        if (((j + 1) % 2) != 0) sum1 += arr[j];

        if (first == -1)
        {
            if (arr[j] < 0) first = j;
        }
    }

    for (int k = (n - 1); k > 0; k--)
    {
        if (arr[k] < 0)
        {
            last = k;
            break;
        }
    }

    if (first != -1 && last != -1)
    {
        first++;
        for (first; first < last; first++) sum2 += arr[first];
    }

    printf("Сумма чисел с нечётными номерами: %.2f\nСумма элементов массива, расположенных между первым и последним отрицательными элементами: %.2f\n", sum1, sum2);

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (fabsf(arr[i]) > 1) arr[i - j] = arr[i];
        else j++;
    }
    for (int i = n - j; i < n; i++) arr[i] = 0;

    printf("Массив после удаления чисел, не превышающих единицу по модулю:\n");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
}