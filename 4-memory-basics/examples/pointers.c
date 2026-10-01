// RUN: gcc -g -O0 pointers.c -o pointers && ./pointers
//
// GDB: gdb ./pointers
//   (gdb) break 30            // breakpoint on first printf
//   (gdb) run                
//   (gdb) p pc                // address of c
//   (gdb) p pc + 1            // +1 byte
//   (gdb) p pi
//   (gdb) p pi + 1            // +4 bytes
//   (gdb) p pd + 1            // +8 bytes
//   (gdb) p (char *)(pd + 1) - (char *)pd   // byte difference: 8
//   (gdb) p *pi               // value: 42
//   (gdb) p &i                // same as pi
//   (gdb) x/xw pi             // 4 bytes on pi in hex: 0x2a
//   (gdb) x/4xb pi            // same 4 bytes one by one (little-endian)
//   (gdb) next                // run printf and go to the next line
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
