
#ifndef COURSE_C1_MATRIX_H
#define COURSE_C1_MATRIX_H

# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
# include "../../algorithms/array/array.h"

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;
//++размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

//размещает в динамической памяти массив из nMatrices матриц разме-
//ром nRows на nCols. Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//++освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix *m);


//++освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

//+ ввод матрицы m
void inputMatrix(matrix *m);

//++ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

//++вывод матрицы m
void outputMatrix(matrix m);

//++вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);


//+++обмен строк с порядковыми номерами i1 и i2 в матрице m.
//Помните, что для этого достаточно обменять указатели соответствующих строк:
void swapRows(matrix m, int i1, int i2);

//+++обмен колонок с порядковыми номерами j1 и j2 в матрице m.
//Обмен колонок будет заключаться в обмене a[i][j1] и a[i][j2] для всех i от 0 до n - 1.
void swapColumns(matrix m, int j1, int j2);

//обмен значениями двух переменных
void swap(int *a,int *b);

//+++выполняет сортировку вставками строк матрицы m по неубыванию
// значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int*, int));

//выполняет сортировку выбором столбцов матрицы m по неубыванию
// значения функции criteria применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int*, int));

// new выполняет сортировку выбором столбцов матрицы m по неубыванию
// значения функции criteria применяемой для столбцов
void sortColsByMinElement(matrix m,
                          int (*criteria)(int*, int));

//int max(int a, int b);

// new 7 Нахождение суммы максимальных элементов всех псевдодиагоналей
// матрицы m
long findSumOfMaxesOfPseudoDiagonal(matrix m);

//new 13
// проверяет, упорядочены ли элементы строк матрицы по по неубыванию
bool hasAllNonDescendingRows(matrix m);

//new 13
//Определяет число матриц, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);


//new 16 Определяет количество "особых" элементов матрицы,
// (в строке слева от него находятся только меньшие элементы, а справа – только б´oльшие)
int CountSpecialElement(matrix m);


//new выполняет сортировку выбором строк матрицы m по неубыванию
// значения функции criteria применяемой для строк
void sortRowsByMaxElement(matrix m,int (*criteria)(int*, int));

//+++возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix *m);

//+++возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае
bool areTwoMatricesEqual(matrix *m1, matrix *m2);

//+++возвращает значение ’истина’, если матрица
//m является единичной, ложь – в противном случае
bool isEMatrix(matrix *m);

//+++возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix *m);

//+++транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix *m);

//+++транспонирует матрицу m
void transposeMatrix(matrix *m);

//+++возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

//+++возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

//+++возвращает матрицу размера nRows на nCols, построенную из элементов массива a
matrix createMatrixFromArray(const int *a,int nRows, int nCols);

//возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices, size_t nRows, size_t nCols);

//+++возвращает количество нулевых строк
int countZeroRows(matrix m, int nRows, int nCols);


#endif //COURSE_C1_MATRIX_H
