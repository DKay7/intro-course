// RUN: gcc -g -O0 sizeof.c -o sizeof && ./sizeof
//
// GDB: gdb ./sizeof
//   (gdb) break 32            // строка с return: все переменные уже заданы
//   (gdb) run
//   (gdb) info locals         // все локальные переменные
//   (gdb) p sizeof(c)         // gdb тоже умеет считать sizeof
//   (gdb) p sizeof(d)
//   (gdb) p sizeof(arr)       // 16: весь массив
//   (gdb) p sizeof(p)         // 8: только указатель
//   (gdb) ptype arr           // тип переменной: int [4]
//   (gdb) ptype p             // int *
//   (gdb) x/4dw arr           // 4 слова (w = 4 байта) в десятичном виде
//   (gdb) x/8xb &d            // 8 байт double в hex
//   (gdb) continue

#include <stdio.h>

int main(void) {
  char c = 'A';
  int i = 42;
  double d = 3.14;
  int arr[4] = {1, 2, 3, 4};
  int *p = arr;

  printf("sizeof(c)   = %zu\n", sizeof(c));
  printf("sizeof(i)   = %zu\n", sizeof(i));
  printf("sizeof(d)   = %zu\n", sizeof(d));
  printf("sizeof(arr) = %zu\n", sizeof(arr));
  printf("sizeof(p)   = %zu\n", sizeof(p));
  printf("элементов в arr: %zu\n", sizeof(arr) / sizeof(arr[0]));
  return 0;
}
