#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

char * getdate()
{
   time_t timer;
   struct tm *tblock;
   timer = time(NULL);
   tblock = localtime(&timer);
   return asctime(tblock);
}

int main()
{
    
    struct tm *t;
    time_t t2;
    while(!kbhit())
    {
                     system("cls");
                     printf("%s",getdate());
    }
    fflush(stdin);
    getch();
}
