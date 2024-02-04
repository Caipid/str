#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
void random(int a[],int m) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        a[i] = rand() % 21;
    }
    
}

void min(int a[], int m) {
    int min = 200;
    for (int i = 0; i < m; i++) {
        if (a[i] < min and a[i] > 0) {
            min = a[i];
        }
    }
    for (int i = 0; i < m; i++) {
        a[i] += min;
    }
    
}

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
void create() {
    int x,y;
    cout << "Введите размер массива:";
    cin >> x;
    ofstream filein("input.dat");
    filein << x;
    filein << " - Размер массива";
}

int main(){
    setlocale(LC_ALL, "RU");
    create();
    int m;
    ifstream filein("input.dat");
    ofstream fileout("output.dat");
    filein >> m;
    fileout << "Размер массива:";
    fileout << m << endl;
    int* a = new int[m];
    random(a, m);
    cout << "Исходный массив:" << endl;
    fileout << "Исходный массив:" << endl;
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
        fileout << a[i] << " ";
    }
    fileout << endl;
    min(a, m);
    Quick_Sort(0, m-1, a);
    cout << " " << endl;
    cout << "Отсортированный массив:" << endl;
    fileout << "Отсортированный массив:" << endl;
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
        fileout << a[i] << " ";
    }
}