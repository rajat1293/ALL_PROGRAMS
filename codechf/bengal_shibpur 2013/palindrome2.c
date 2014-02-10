#include<stdio.h>
#include<string.h>
inline int input()
    {
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
    }
int main()
{
	char arr[1000003],i,k=0,flag=0;
	int a[27]={0};
	char ff;
	gets(arr);
	for(i=0;i<strlen(arr);i++)
	a[arr[i]-'a']+=1;
	while(1){
		k++;
		flag=0;
		for(i=0;i<26;i++)
		{
			if(flag==2)
		break;
		if(a[i]%2!=0)
		flag++;
	}
	if(i==26&&k%2!=0)
	{printf("Ram");
	break;}
	else if(i==26&&k%2==0)
	{
	printf("Shyam");
	break;}	
	fflush(stdin);
	ff=input();
	a[ff-'a']-=1;	
	}
	return 0;
}
