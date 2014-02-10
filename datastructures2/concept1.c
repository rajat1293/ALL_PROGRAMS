#include<stdio.h>
#include<stdlib.h>
 typedef  struct n{
  int dta;
  struct n *link;
  int dtaa;
  }gg;
   gg k,f;
main()
{int i;
    char *p="gambhir";

    for(i=0;i<4;i++)
    printf("\n%s",p);
    f.dta=10;
    f.link=&k;
    k.dta=9;
k.dtaa=99;
  printf("\n%d %d ",f.dta,(*(f.link)).dta);
}



