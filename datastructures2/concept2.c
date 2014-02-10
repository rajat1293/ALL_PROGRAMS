#include<stdio.h>
#include<stdlib.h>
int *val;
main()
{
    val=(int*)malloc(sizeof(int));//if we dont expilicity declare a memory the pointer points to address 0
    // as the address of global variale is to zero,ehich is under the OS.So explicit defonotion is reqired
    //if we dntdeclare it as a global variabl we might get right results some times ,depending upon the
    //the memory status of the RAM
*val=2;
   printf("%d",*val);

}
