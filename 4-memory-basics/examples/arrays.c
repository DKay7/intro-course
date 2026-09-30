// RUN: gcc -g -O0 arrays.c -o arrays && ./arrays
//
// GDB: gdb ./arrays
//   (gdb) break 29 if i == 2  // условная точка останова внутри цикла
//   (gdb) run
//   (gdb) p a                 // весь массив: {10, 20, 30, 40, 50}
//   (gdb) p &a[0]             // адрес начала
//   (gdb) p a + i             // адрес i-го элемента через арифметику
//   (gdb) p &a[i]             // то же самое
//   (gdb) p *(a + i)          // значение: 30
//   (gdb) p a[i]              // то же самое
//   (gdb) x/5dw a             // весь массив в памяти: 5 слов по 4 байта
//   (gdb) x/5xw a             // то же в hex
//   (gdb) display i           // печатать i после каждого шага
//   (gdb) next
//   (gdb) next
//   (gdb) continue

#include <stdio.h>

int main(void) {
    int a[5] = {10, 20, 30, 40, 50};

    printf("a      = %p\n", (void *)a);
    printf("&a[0]  = %p\n", (void *)&a[0]);
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("a + %d = %p   &a[%d] = %p   a[%d] = %d\n",
               i, (void *)(a + i), i, (void *)&a[i], i, *(a + i));
    }
    return 0;
}
