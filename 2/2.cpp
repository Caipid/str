#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


void Exchange(int i, int j, int* x) {
    int tmp;
    tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

void Quick_Sort(int left, int right, int* x) {
    int i, j, m;
    i = left;
    j = right;
    m = x[(i + j + 1) / 2];
    do {
        while (x[i] < m) i++;
        while (x[j] > m) j--;
        if (i <= j) {
            Exchange(i, j, x);//обмен i, j элементов местами
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        Quick_Sort(left, j, x);
    if (i < right)
        Quick_Sort(i, right, x);
}

int main() {
    clock_t start = clock();
    setlocale(LC_ALL, "RU");
    int m;
    ifstream fileou("outpu.dat");
    ofstream sortm("sot.dat");
    fileou >> m;
    sortm << "Размер массива:";
    sortm << m << endl;
    int* a = new int[m];
    for (int i = 0; i < m; i++) {
        fileou >> a[i];
    }
    cout << "Исходный массив:" << endl;
    sortm << "Исходный массив:" << endl;
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
        sortm << a[i] << " ";
    }
    sortm << endl;
    Quick_Sort(0, m - 1, a);

    cout << " " << endl;
    cout << "Отсортированный массив:" << endl;
    sortm << "Отсортированный массив:" << endl;
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
        sortm << a[i] << " ";
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя выполнения сортировки:";
    cout << seconds;
    delete[] a;

}