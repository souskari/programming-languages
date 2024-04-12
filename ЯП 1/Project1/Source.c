﻿/* ────────────────────────────────────────────────────────── *
 │                                                            │
 │   Серия тестов PC Tech Journal                             │
 │   Тест оптимизации кода Си                                 │
 │                                                            │
 │   Copyright (c) 1988 Ziff-Devis Publishing Company         │
 │                                                            │
 │   Эта  программа-тест  была  разработана  для  проверки    │
 │   методов оптимизации  кода,  применяемых  компилятором    │
 │   Си. Она  не  вырабатывает  разумные  результаты  и  не   │
 │   представляет хороший стиль программирования.             │
 │                                                            │
 * ────────────────────────────────────────────────────────── */


#include <stdio.h>
#include <string.h>
#define max_vector    2
#define constant5     5

typedef unsigned char    uchar;

int    i, j, k, l, m;
int    i2, j2, k2;
int    g3, h3, i3, k3, m3;
int    i4, j4;
int    i5, j5, k5;

double flt_1, flt_2, flt_3, flt_4, flt_5, flt_6;

int    ivector[3];
uchar  ivector2[3];
short  ivector4[6];
int    ivector5[100];

#ifndef NO_PROTOTYPES
void   dead_code(int, char*);
void   unnecessary_loop(void);
void   loop_jamming(int);
void   loop_unrolling(int);
#else
void   dead_code();
void   unnecessary_loop();
void   loop_jamming();
void   loop_unrolling();
#endif

int jump_compression(i, j, k, l, m)
int i, j, k, l, m;
{
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
beg_1:
    i2 = 4;
    goto beg_2;
beg_2: 
    goto beg_3;
beg_3:
    j5 = 5;
   /* if (i < j)
        if (j < k)
            if (k < l)
                if (l < m)
                    l += m;
                else
                    goto end_1;
            else
                k += l;
        else {
            j += k;
        end_1:
            goto beg_1;
        }
    else
        i += j;
    return(i + j + k + l + m);*/
} /* Конец jump_compression */
int /* cdecl */  main(argc, argv)           /* optbench */
int argc;
char** argv;
{
    /* ──────────────────────────── *
         │ Отказ от циклов │
         *──────────────────────────────*/
    for (i = 0; i < 3; i++) ivector[i] = 1;

    /* ──────────────────────────── *
         │ Переприсваивание│
         *──────────────────────────────*/
    i2 = 5;
    j4 = 6;
    i2 = j4;
    /* ──────────────────────────── *
         │ Размножение констант и копий │
         *──────────────────────────────*/

    j4 = 2;
    if (i2 < j4 && i4 < j4) {
        i2 = 2;
        printf("Hello");
    }

    j4 = k5;
    if (i2 < j4 && i4 < j4) {
        i5 = 3;
        printf("Hello");
    }

    /* ────────────────────────────────────────── *
 │ Свертка констант, арифметические тождества │
     │ и излишние операции загрузки/сохранения    │
     * ────────────────────────────────────────── */

    i3 = 1 + 2;
    flt_1 = 2.4 + 6.3;
    i2 = 5;
    j2 = i + 0;
    k2 = i / 1;
    i4 = i * 1;
    i5 = i * 0;



    /* ──────────────────── *
     │  Лишнее присваивание │
     * ──────────────────── */

    k3 = 1;
    /* ────────────────── *
     │  Снижение мощности │
     * ────────────────── */

    k2 = 4 * j5;
    for (i = 0; i <= 5; i++)
        ivector4[i] = i * 2;

    /* ───────────── *
         │  Простой цикл │
         * ───────────── */

    j5 = 0;
    k5 = 10000;
    do {
        k5 = k5 - 1;
        j5 = j5 + 1;
        i5 = (k5 * 3) / (j5 * constant5);
    } while (k5 > 0);

    /* ────────────────────────────────────── *
 │  Управление переменной индукции цикла  │
     * ────────────────────────────────────── */
    for (i = 0; i < 100; i++)
        ivector5[i * 2 + 3] = 5;

    /* ─────────────────────── *
     │  Глубокие подвыражения  │
     * ─────────────────────── */

    if (i < 10)
        j5 = i5 + i2;
    else
        k5 = i5 + i2;

    /* ──────────────────────────────────────────────── *
     │  Проверка того, как компилятор генерирует адрес  │
     │  переменной с константным индексом, размножает   │
     │  копии и регистры                                │
     * ──────────────────────────────────────────────── */

    ivector[0] = 1;  /* генерация константного адреса */
    ivector[i2] = 2; /* значение i2 должно быть скопировано*/
    ivector[i2] = 2; /* копирование регистров */
    ivector[2] = 3;  /* генарация константного адреса */


    /* ───────────────────────────── *
         │  Удаление общих подвыражений  │
         * ───────────────────────────── */

    if ((h3 + k3) < 0 || (h3 + k3) > 5)
        printf("Common subexpression elimination\n");
    else {
        m3 = (h3 + k3) / i3;
        g3 = i3 + (h3 + k3);
    }

    /* ────────────────────────────────────── *
     │  Вынесение инвариантного кода          │
     │  (j * k) может быть вынесено из цикла  │
 * ────────────────────────────────────── */

    for (i4 = 0; i4 <= max_vector; i4++) {
        printf("Hello");
        ivector2[i4] = j * k;
    }

    /* ───────────────────────────── *
     │  Вызов функции с аргументами  │
     * ───────────────────────────── */

    dead_code(1, "This line should not be printed");

    /* ────────────────────────────── *
         │  Вызов функции без аргументов  │
         * ────────────────────────────── */

    unnecessary_loop();

    //------------------------------------------------------
    loop_jamming(7);
    loop_unrolling(7);
    jump_compression(1, 2, 3, 4, 5);

}    /* Конец функции main */


/* ────────────────────────────────────────────────────── *
 │  Функция: dead_code                                    │
 │           Проверка недостижимого кода и лишних         │
 │           присваиваний. Не должен генерироваться код.  │
 * ────────────────────────────────────────────────────── */

void dead_code(a, b)
int a;
char* b;
{
    int idead_store;

    idead_store = a;
    if (0)
        printf("%s\n", b);
} /* Конец dead_code */


/* ──────────────────────────────────────────────────── *
 │  Функция: unnecessary_loop                           │
 │           Цикл в следующей функции ненужен, так как  │
 │           значение присваивания постоянно. В идеале  │
 │           цикл должен быть удален.                   │
 * ──────────────────────────────────────────────────── */

void unnecessary_loop()
{
    int x;
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    x = 0;
    for (i = 0; i < 5; i++)  /* Цикл не должен
                                   генерироваться*/
        k5 = x + j5;
} /* Конец unnecessary_loop */

/* ──────────────────────────────────────────────────── *
 │  Функция: loop_jamming                               │
│           Два цикла в этой функции имеют одинаковые  │
│           заголовки и могут быть слиты в один.       │
* ──────────────────────────────────────────────────── */


void loop_jamming(x)
int x;
{
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU");
    for (i = 0; i < 5; i++)
        k5 = x + j5 * i;
    for (i = 0; i < 5; i++)
        i5 = x * k5 * i;
} /* Конец loop_jamming */

/* ────────────────────────────────────────────────────── *
 │  Функция: loop_unrolling                               │
 │           Цикл в этой функции должен быть заменен      │
 │           тремя присваиваниями с использованием        │
│           константной индексации массива или машинно-  │
    │           зависимыми командами для инициализации       │
    │           блока памяти.                                │
    * ────────────────────────────────────────────────────── */

void loop_unrolling(x)
int x;

{
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU"); printf("HFJDDFSDFJSDFSDFU");
    for (i = 0; i < 6; i++)
        ivector4[i] = 0;
} /* Конец loop_unrolling */

/* ───────────────────────────────────────────────────── *
│  Функция: jump_compression                            │
    │           Эта программа полезна для демонстрации      │
    │           сжатия цепочки переходов. goto end_1 может  │
    │           быть заменен на прямой переход на beg_1.    │
    * ───────────────────────────────────────────────────── */



