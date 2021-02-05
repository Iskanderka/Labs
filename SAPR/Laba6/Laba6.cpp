#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swapping(int i, int j, int* x) {
    int tmp;
    tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

void Shell_Sort(bool flag, int n, int* x) {
    int h, i, j, p;
    for (h = (n / 4) * 2; h > 0; h = (h / 4) * 2)
    {
        for (i = (flag) ? 1 : 0; i < n - h; i+=2)
        {
            for (j = i; j >= 0; j = j - h)
            {
                if (((x[j] > x[j + h]) && flag) || ((x[j] < x[j + h]) && !flag))
                {
                    p = j + h;
                    swapping(j, p, x);
                }
                else j = 0;
            }
        }
    }
}

void make_arr(int n, int *x) {
    for (int i = 0; i < n; i++)
    {
        x[i] = rand() % 201 - 100;
    }
}

void print_arr(int n, int *x) {
    cout << "Массив: " << endl;
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int n = 15;
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = (int*)malloc(n * sizeof(int));
    
    make_arr(n, arr);
    cout << "Создали массив случайных чисел:\n";
    print_arr(n, arr);
    
    Shell_Sort(true, n, arr);
    Shell_Sort(false, n, arr);

    cout << "Произвели сортировку.\n";
    print_arr(n, arr);
}