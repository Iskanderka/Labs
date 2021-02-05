#include <iostream>

using namespace std;

float average(int n, int arr[]) {
    float summ = 0;
    for (int i = 0; i < n; i++)
    {
        summ += arr[i];
    }
    return summ / n;
}

int find_max(int n, int arr[]) {
    int max;
    max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void insert_zero(int* n, int arr[])
{
    int n1;
    n1 = *n;
    for (int i = 0; i < n1; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = n1++; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = 0;
            i++;
        }
    }
    *n = n1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = (int*)malloc(n * sizeof(int));
    cout << "\n" << "Введите массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Среднее арифметическое масссива - " << average(n, arr) << endl;
    cout << "Максимальный элемент массива - " << find_max(n, arr) << "\n" << endl;

    insert_zero(&n, arr);
    cout << "Массив после вставки: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n" << "Среднее арифметическое масссива после вставки - " << average(n, arr) << "\n" << endl;
}
