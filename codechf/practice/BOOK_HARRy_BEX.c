#include<stdio.h>
#include<string.h>
#define MAX_STACK 1000009
typedef struct book{
	
	int ex;
	char name[20];	
}element;
element stack[MAX_STACK];
int top=-1;
void   push(element item)
        {
                     stack[++top]=item;
                     }
                          element  pop()
     {
      return stack[top--];
      }
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
	if(s==-1)
	{int i=top;
     m=-1;
		small=stack[i].ex;
		for(i=(top-1);i>=0;i--)
		{
			if(stack[i].ex<small&&stack[i].ex>0)
				small=stack[i].ex;
		}
	while(1)
	{m++;
		f=pop();
		if(f.ex==small)
		break;
	}
	printf("%d %s\n",m,f.name);
	}	
	else {
		scanf("%s",na);
		element item;
		item.ex=s;
		strcpy(item.name,na);
	push(item);		
	}
}
return 0;
}
