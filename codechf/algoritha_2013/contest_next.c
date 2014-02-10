#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	int arr[40]={0},i;
	char m[30];
	scanf("%d",&t);
		scanf("%s",m);
		for(i=0;i<strlen(m);i++)
		arr[m[i]-97]=i;
	while(t--)
	{
		int arr1[40]={0},arr2[40]={0};
		char a[120],b[120];
		int s=0;
		int l=0;
		scanf("%s",a);
		scanf("%s",b);
		for(i=0;i<strlen(a);i++)
		arr1[a[i]-97]=1;
		for(i=0;i<strlen(b);i++)
		arr2[b[i]-97]=1;
		for(i=0;i<strlen(b);i++)
		{if(arr1[i]==arr2[i])
		{
		arr1[i]=0;
		arr2[i]=0;}
	}
	for(i=0;i<strlen(b);i++)
	if(arr1[i]==1)
	s+=m[i];
	for(i=0;i<strlen(b);i++)
	if(arr2[i]==1)
	l+=m[i];
	if(l>s)
printf("BOB\n");
else if(s>l)
printf("ALICE\n");
else
printf("TIE\n");
}

return 0;
}
