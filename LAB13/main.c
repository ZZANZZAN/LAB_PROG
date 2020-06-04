#include <stdio.h>
int main() {
 struct {
 unsigned char byte1 : 8;
 unsigned char byte2 : 8;
 unsigned char byte3 : 8;
 unsigned char byte4 : 8;
 } XX;
 int a1 = 0;
 int a2 = 0;
 int a3 = 0;
 int a4 = 0;
 puts("Enter number separated by space:");
 unsigned byte1, byte2, byte3, byte4;
 scanf("%X %X %X %X", &byte1, &byte2, &byte3, &byte4);
 puts("Enter shift 1(if u no need this, u should enter 0):");
 scanf("%d", &a1);
 puts("Enter shift 2(if u no need this, u should enter 0):");
 scanf("%d", &a2);
 puts("Enter shift 3(if u no need this, u should enter 0):");
 scanf("%d", &a3);
 puts("Enter shift 4(if u no need this, u should enter 0):");
 scanf("%d", &a4);
 if (a1>7) a1 = a1%8;
 if (a2>7) a2 = a2%8;
 if (a3>7) a3 = a3%8;
 if (a4>7) a4 = a4%8;
 XX.byte1 = byte1>>a1;
 XX.byte2 = byte2>>a2;
 XX.byte3 = byte3>>a3;
 XX.byte4 = byte4>>a4;
 puts("\nOutput:");
 printf("%X %X %X %X", XX.byte1, XX.byte2, XX.byte3, XX.byte4);
 return 0;
}
