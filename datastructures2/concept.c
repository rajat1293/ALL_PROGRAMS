#include<stdio.h>
 typedef  struct n{
  int dta;
  struct n *link;
  int dtaa;
  }gg;
   gg k;
main()
{int i;
    char *p="gambhir";

    for(i=0;i<4;i++)
    printf("\n%s",p);
    printf("\nenter the element to be pushed");
              scanf("%d",&k);
  printf("\n%d ",k.link);
}


