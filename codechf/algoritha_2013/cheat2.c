#include <stdio.h>
#include<string.h>
int main()
{
int par[40],t;
par[1]=1; par[2]=1; par[3]=2; par[4]=5; par[5]=14; par[6]=42; par[7]=132; par[8]=429; par[9]=1430; par[10]=4862; par[11]=6796; par[12]=8786; par[13]=8012; par[14]=2900; par[15]=4440; par[16]=4845; par[17]=7670; par[18]=4790; par[19]=8700; par[20]=3190; par[21]=420; par[22]=7020; par[23]=3640; par[24]=3650; par[25]=7324; par[26]=1452; par[27]=2152; par[28]=6004; par[29]=360; par[30]=1368; par[31]=2304; par[32]=6909; par[33]=8198; par[34]=212336130412243110; par[35]=764; par[36]=1262; 
scanf("%d", &t);
while(t--)
{
char ra[40];
int n;
scanf("%s",&ra);
n=strlen(ra);
printf("%d\n", par[n]);
}
return 0;
} 
