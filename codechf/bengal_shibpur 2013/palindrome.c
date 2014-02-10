#include<stdio.h>
#include<string.h>
int main()
{
	char arr[1000003],i,k=0,j=0,p,flag=0;
	int a[27]={0},b[27]={0};
	char ff;
	fflush(stdin);
	gets(arr);
	for(i=0;i<strlen(arr);i++)
	a[arr[i]-'a']+=1;
	for(i=0;i<26;i++)
	if(a[i])
	b[j++]=i;
	p=0;
	while(1){
		int s=1;
		k++;
		flag=0;
		p=0;
		for(i=b[p];i<=b[j-1]&&(i!=0||s==1);i=b[++p])
		{
			s=0;
		      if(a[i]%2!=0)
		     flag++;
		     if(flag==2)
		     break;
	}
	if(i==0&&k%2!=0)
	{printf("Ram");
	break;}
	else if(i==0&&k%2==0)
	{
	printf("Shyam");
	break;}	
	fflush(stdin);
	scanf("%c",&ff);
	a[ff-'a']-=1;	
	}
	return 0;
}
