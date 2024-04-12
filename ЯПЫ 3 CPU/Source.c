#include <stdio.h>

// ���������� ������ �������
#define N 3

int determinant(float* mat, int tid)
{
    int det = 0;
    int tmp_tid = tid;
    int offset = tid * N;
    printf("%d\n", tid);


    // ���������� � ����������� �������
    for (int i = 0; i < N - 1; i++)
    {
        // �������� �� ���� ������������� ��������
        if (mat[i + i * N + i] == 0)
        {
            det = 0;
            return;
        }

        // ���������� ������������ ��� ��������� ������ ������
        float coeff = mat[offset + (i + 1) * N + i] / mat[offset + i * N + i];

        // ��������� ������ ������
        for (int j = tid; j < N; j++)
        {
            mat[offset + (i + 1) * N + j] -= coeff * mat[offset + i * N + j];
        }


        // ��������� ������������ ���������
        float val = 1;
        for (int i = 0; i < N; i++)
        {
            val *= mat[offset + i * N + i];
        }

        // ������������ ������������
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
    // ����� ����������
    printf("Determinant: %d\n", determin);
    getch();
}