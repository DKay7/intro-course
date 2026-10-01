// RUN: gcc -g -O0 arrays.c -o arrays && ./arrays
//
// GDB: gdb ./arrays
//   (gdb) break 29 if i == 2  // set conditional breakpoint inside of the loop
//   (gdb) run
//   (gdb) p a                 // print array: {10, 20, 30, 40, 50}
//   (gdb) p &a[0]             // start address
//   (gdb) p a + i             // ith elemnt address
//   (gdb) p &a[i]             // same
//   (gdb) p *(a + i)          // value of ith elemnt: 30
//   (gdb) p a[i]              // same
//   (gdb) x/5dw a             // memory examine of the array
//   (gdb) x/5xw a             // same in hex
//   (gdb) display i           // print i after each step
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
               i, (void *)(a + i), 
               i, (void *)&a[i], 
               i, *(a + i));
    }
    return 0;
}
