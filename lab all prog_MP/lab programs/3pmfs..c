#include<stdio.h>
#include<conio.h>
 yoyo(int m[])
{

   m[0]=(m[1]+m[2])/2;
    m[4]=m[2]-1;
    m[3]=m[1]+1;
}
main()
{
    int n[10],m[10],k[10],j,i,p;
    printf("enter the limits for first case\n");
    scanf("%d%d",&n[1],&n[2]);
    printf("enter the limits for case 2\n");
    scanf("%d%d",&m[1],&m[2]);
    printf("enter the limits for third case\n");
    scanf("%d%d",&k[1],&k[2]);
    yoyo(k);
    yoyo(m);
    yoyo(n);
    printf("average case\n");
    for(i=0;i<5;i++)
    printf("(%d %d %d)\n",n[0],m[0],k[i]);
    for(i=1;i<5;i++)
    printf("(%d %d %d)\n",n[i],m[0],k[0]);
    for(i=1;i<5;i++)
    printf("(%d %d %d)\n",n[0],m[i],k[0]);
printf("\nprintf the worst case is\n");
for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {
    for(p=0;p<5;p++)
    printf("(%d %d %d)\n",n[i],m[j],k[p]);
}

}
getch();
}












