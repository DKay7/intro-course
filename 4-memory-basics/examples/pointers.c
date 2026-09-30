// RUN: gcc -g -O0 pointers.c -o pointers && ./pointers
//
// GDB: gdb ./pointers
//   (gdb) break 30            // строка с первым printf
//   (gdb) run
//   (gdb) p pc                // адрес c
//   (gdb) p pc + 1            // +1 байт
//   (gdb) p pi
//   (gdb) p pi + 1            // +4 байта
//   (gdb) p pd + 1            // +8 байт
//   (gdb) p (char *)(pd + 1) - (char *)pd   // разница в байтах: 8
//   (gdb) p *pi               // разыменование: 42
//   (gdb) p &i                // совпадает с pi
//   (gdb) x/xw pi             // 4 байта по адресу pi в hex: 0x2a
//   (gdb) x/4xb pi            // те же 4 байта по одному (little-endian)
//   (gdb) next                // выполнить printf и перейти к следующей строке
//   (gdb) continue

#include <stdio.h>

int main(void) {
  char c = 'A';
  int i = 42;
  double d = 3.14;

  char *pc = &c;
  int *pi = &i;
  double *pd = &d;

  printf("pc = %p, pc + 1 = %p\n", (void *)pc, (void *)(pc + 1));
  printf("pi = %p, pi + 1 = %p\n", (void *)pi, (void *)(pi + 1));
  printf("pd = %p, pd + 1 = %p\n", (void *)pd, (void *)(pd + 1));
  printf("*pi = %d\n", *pi);
  return 0;
}
