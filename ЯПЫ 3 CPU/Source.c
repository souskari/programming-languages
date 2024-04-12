#include <stdio.h>

// Определяем размер матрицы
#define N 3

int determinant(float* mat, int tid)
{
    int det = 0;
    int tmp_tid = tid;
    int offset = tid * N;
    printf("%d\n", tid);


    // Приведение к треугольной матрице
    for (int i = 0; i < N - 1; i++)
    {
        // Проверка на ноль диагонального элемента
        if (mat[i + i * N + i] == 0)
        {
            det = 0;
            return;
        }

        // Нахождение коэффициента для обнуления нижней строки
        float coeff = mat[offset + (i + 1) * N + i] / mat[offset + i * N + i];

        // Обнуление нижней строки
        for (int j = tid; j < N; j++)
        {
            mat[offset + (i + 1) * N + j] -= coeff * mat[offset + i * N + j];
        }


        // Умножение диагональных элементов
        float val = 1;
        for (int i = 0; i < N; i++)
        {
            val *= mat[offset + i * N + i];
        }

        // Присваивание определителя
        det = val;
    }
    return det;
}

int main()
{
    float matrix[N][N] = { {1, 2, 7}, {12, 5, 6}, {5, 8, 9} };
    //printf("M: %f\n", matrix[0][1]);
    int determin = 0;
    for (int i = 0; i < N; i++) {
        determin += determinant(matrix, i);
    }
    // Вывод результата
    printf("Determinant: %d\n", determin);
    getch();
}