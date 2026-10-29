// PR_6.3.rec.cpp
// Варіант 8 (рекурсивний спосіб)
// Завдання: обчислення суми додатних елементів одновимірного масиву
// Реалізація за допомогою звичайних рекурсивних функцій та шаблонів (сумарно 6 функцій)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Звичайна рекурсивна функція формування масиву
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// 2. Шаблонна рекурсивна функція формування масиву
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = static_cast<T>(Low + static_cast<double>(rand()) / RAND_MAX * (High - Low));
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

// 3. Звичайна рекурсивна функція виведення масиву
void Print(const int* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// 4. Шаблонна рекурсивна функція виведення масиву
template <typename T>
void Print(const T* a, const int size, int i)
{
    cout << setw(8) << fixed << setprecision(2) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// 5. Звичайна рекурсивна функція обчислення суми додатних елементів
int SumPositive(const int* a, const int size, int i)
{
    if (i >= size)
        return 0;
    if (a[i] > 0)
        return a[i] + SumPositive(a, size, i + 1);
    else
        return SumPositive(a, size, i + 1);
}

// 6. Шаблонна рекурсивна функція обчислення суми додатних елементів
template <typename T>
T SumPositive(const T* a, const int size, int i)
{
    if (i >= size)
        return 0;
    if (a[i] > 0)
        return a[i] + SumPositive<T>(a, size, i + 1);
    else
        return SumPositive<T>(a, size, i + 1);
}

template <typename T>
T SumPositiveTemplate(const T* a, const int size, int i)
{
    return SumPositive<T>(a, size, i);
}

#if !defined(_WINDLL)
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    const int Low = -10;
    const int High = 10;

    // 1) Опрацювання за допомогою звичайних функцій (рекурсивно)
    Create(a, n, Low, High, 0);
    cout << "1. Regular recursive functions (int array a):" << endl;
    Print(a, n, 0);
    int s1 = SumPositive(a, n, 0);
    cout << "Sum of positive elements (regular SumPositive) = " << s1 << endl << endl;

    // 2) Опрацювання за допомогою шаблонів функцій для int (рекурсивно)
    Create<int>(a, n, Low, High, 0);
    cout << "2. Template recursive functions for int (array a):" << endl;
    Print<int>(a, n, 0);
    int s2 = SumPositive<int>(a, n, 0);
    cout << "Sum of positive elements (template SumPositive<int>) = " << s2 << endl << endl;

    // 3) Опрацювання за допомогою шаблонів функцій для double (рекурсивно)
    double b[n];
    const double LowD = -10.0;
    const double HighD = 10.0;
    Create(b, n, LowD, HighD, 0);
    cout << "3. Template recursive functions for double (array b):" << endl;
    Print(b, n, 0);
    double s3 = SumPositive(b, n, 0);
    cout << "Sum of positive elements (template SumPositive<double>) = " << s3 << endl;

    return 0;
}
#endif
