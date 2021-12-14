#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

/*!
 \brief Функция заполняет массив случайными числами
 \param[in] arraySize - длина массива.
 \param[in] *ptrarray - указатель на первый элемент динамического массива.

 Данная функция заполняет динамический массив символами char.
 В данной функции используется генератор псевдослучайных чисел, реализуемый функцией srand().
 Диапазон генерируемых чисел выбран такой, что генерируются char, соответствующие по таблице ASII заглавным английским буквам.
*/

void fillArray(int arraySize, int* ptrarray);

/*!
 \brief Функция сортировки массив по убыванию.
 \param[in] arraySize - длина массива.
 \param[in] *ptrarray - указатель на первый элемент динамического массива.

 Функция сортирует элементы динамического массива по убыванию.
*/

void sortArray(int arraySize, int* ptrarray);

/*!
 \brief Функция вывода динамического массива на печать..
 \param[in] arraySize - длина массива.
 \param[in] *ptrarray - указатель на первый элемент динамического массива.

 Функция выводит элементы динамического массивая на печать.
*/

void printArray(int arraySize, int* ptrarray);

/*!
 \brief Функция очистки зарезервированной под динамический массив памяти.
 \param[in] *ptrarray - указатель на первый элемент динамического массива.

 Функция очищает память, выделенную под динамический массив.
*/

void cleanUp(int* ptrarray);

/*!
 \brief Главная функция.
 Функция предлагает пользователю указать длинну динамического массива.
 Инициализирует динамический массив и заполняет его случайными числами в фиксированном диапазоне.
 Выводит массив на печать, производит сортировку элементов по убыванию и выводит отсортированный массив на печать снова.
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    int arraySize;
    cout << "Введите размерность динамического массива:";
    cin >> arraySize;
    int* ptrarray = new int[arraySize];
    fillArray(arraySize, ptrarray);
    cout << endl << "Заполнение массива псевдослучайными числами";
    cout << endl << "Одномерный массив" << endl;
    printArray(arraySize, ptrarray);
    cout << endl << "Сортировка массива по убыванию" << endl;
    sortArray(arraySize, ptrarray);
    printArray(arraySize, ptrarray);
    cleanUp(ptrarray);
}

void fillArray(int arraySize, int* ptrarray) {
    const int start = -99;
    const int end = 100;
    const int step = 1;
    srand(unsigned(time(NULL)));
    for (int count = 0; count < arraySize; count++) {
        ptrarray[count] = start + rand() % (end - start + step);
    }
}
void sortArray(int arraySize, int* ptrarray) {
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < arraySize; i++) {
        j = i;
        for (int k = i; k < arraySize; k++) {
            if (ptrarray[j] < ptrarray[k]) {
                j = k;
            }
        }
        tmp = ptrarray[i];
        ptrarray[i] = ptrarray[j];
        ptrarray[j] = tmp;
    }
}
void printArray(int arraySize, int* ptrarray) {
    for (int count = 0; count < arraySize; count++) {
        cout << ptrarray[count] << " ";
    }
    cout << endl;
}
void cleanUp(int* ptrarray) {
    if (ptrarray != nullptr)
    {
        delete[] ptrarray;
        ptrarray = nullptr;
    }
}