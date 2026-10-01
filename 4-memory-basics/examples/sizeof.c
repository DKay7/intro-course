// RUN: gcc -g -O0 sizeof.c -o sizeof && ./sizeof
//
// GDB: gdb ./sizeof
//   (gdb) break 32            // line with return: all variables are set already
//   (gdb) run
//   (gdb) info locals         // all local variables
//   (gdb) p sizeof(c)         // gdb can execute some C-expressions: sizeof
//   (gdb) p sizeof(d)
//   (gdb) p sizeof(arr)       // 16: whole array
//   (gdb) p sizeof(p)         // 8: only the pointer
//   (gdb) ptype arr           // var type: int [4]
//   (gdb) ptype p             // int *
//   (gdb) x/4dw arr           // 4 words (w = 4 bytes) as decimal
//   (gdb) x/8xb &d            // 8 bytes double в hex
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
