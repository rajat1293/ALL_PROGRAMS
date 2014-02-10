//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i=0;
		int flag=0;
		char arr[1005];
		int a[27]={0};
		scanf("%s",arr);
		int k=strlen(arr);
		if(k%2!=0)
		flag=1;
		if (flag){
		  while(i<k){
		    if(i!=k/2)
         	 a[arr[i]-97]+=1;
            i++;	 
         }
		 }
        else {
          while(i<k) 	
			 a[arr[i++]-97]+=1; 
      }
      for(i=0;i<26;i++)
	  {
	  if(a[i]%2!=0)
	  break;
}
if(i==26)
printf("YES\n");
else 
printf("NO\n");
}
return 0;
}
         
