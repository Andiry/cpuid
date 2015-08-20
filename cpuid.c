#include <stdio.h>
 
int main()
{
  int a, b, c;
 
  for (a = 0; a < 8; a++)
  {
    __asm__("cpuid"
            :"=a"(b), "=b"(c)                 // EAX into b (output)
            :"a"(a), "c"(0)                 // a into EAX (input)
            :"%edx");  // clobbered registers
 
    printf("The code %i gives 0x%x, 0x%x\n", a, b, c);
  }
 
  return 0;
}
