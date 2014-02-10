#include<stdio.h>
#include<string.h>
#define MAX_STACK 1000009
typedef struct book{
	
	int ex;
	char name[20];	
}element;
element stack[MAX_STACK];
int top=-1;
int main()
{
	
	int n,small;
	element f;
	char na[20];
	scanf("%d",&n);
	while(n--)
	{
		int s,m;
	scanf("%d",&s);	
	if(s==-1&&top!=-1)
	{int i=top;
        m=-1;
		small=stack[i].ex;
		for(i=(top-1);i>=0;i--)
		{
			if(stack[i].ex<small)
				small=stack[i].ex;
		}
	while(1)
	{   m++;
		f=stack[top--];
		if(f.ex==small)
		break;
	}
	printf("%d %s\n",m,f.name);
	}
	else if(top==-1&&s==-1);	
	else {
	if(s!=0&&top==-1) {
		scanf("%s",na);
		element item;
		item.ex=s;
		strcpy(item.name,na);
			stack[++top]=item;	
	}
	else if(s!=0)
	{scanf("%s",na);
		
	}
	
	else
	scanf("%s",na);
}}
return 0;
}
