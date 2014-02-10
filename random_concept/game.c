#include<stdio.h>
 #include<ctype.h>
 
char pos_board[3][3];
 int count=0;
 char name[20];
 int player_count=0;
 int computer_count=0;
 int z;
 int a=3;
 int b=3;
 int blank_row;
 int blank_column;
 int blank_count=0;
 int draw_count=0;
 
void print()
 {
 printf("\n");
 int i,j;
 for(i=0; i<3; ++i)
 {
 printf("\t\t\t");
 for(j=0; j<3; ++j)
 {
 printf("%c\t",pos_board[i][j]);
 }
 printf("\n\n");
 }
 }
 
void player()
 {
 int x,y;
 printf("\nEnter position (x y) where u want to input ( for example : 1 3 ) : ");
 scanf("%d %d",&x,&y);
 if((pos_board[x-1][y-1]!='-')||(x<1)||(x>3)||(y<1)||(y>3))
 {
 printf("Wrong Position\n");
 player();
 }
 else
 {
 pos_board[x-1][y-1]='X';
 printf("\n\nAfter your turn board is : \n\n");
 print();
 count++;
 }
 }
 
int check1()
 {
 a=3;
 b=3;
 int i,j;
 for(i=0; i<3; ++i)
 {
 if((pos_board[i][0]=='X')&&(pos_board[i][1]=='X')&&(pos_board[i][2]!='O'))
 {
 a=i;
 b=2;
 }
 else if((pos_board[i][1]=='X')&&(pos_board[i][2]=='X')&&(pos_board[i][0]!='O'))
 {
 a=i;
 b=0;
 }
 else if((pos_board[i][0]=='X')&&(pos_board[i][2]=='X')&&(pos_board[i][1]!='O'))
 {
 a=i;
 b=1;
 }
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 
int check2()
 {
 a=3;
 b=3;
 int i,j;
 for(j =0;j<3;++j)
 {
 if((pos_board[0][j]=='X')&&(pos_board[1][j]=='X')&&(pos_board[2][j]!='O'))
 {
 a=2;
 b=j;
 }
 else if((pos_board[1][j]=='X')&&(pos_board[2][j]=='X')&&(pos_board[0][j]!='O'))
 {
 a=0;
 b=j;
 }
 else if((pos_board[0][j]=='X')&&(pos_board[2][j]=='X')&&(pos_board[1][j]!='O'))
 {
 a=1;
 b=j;
 }
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 
int check3()
 {
 a=3;
 b=3;
 if((pos_board[0][0]=='X')&&(pos_board[1][1]=='X')&&(pos_board[2][2]!='O'))
 {
 a=2;
 b=2;
 }
 else if((pos_board[1][1]=='X')&&(pos_board[2][2]=='X')&&(pos_board[0][0]!='O'))
 {
 a=0;
 b=0;
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 
int check4()
 {
 a=3;
 b=3;
 if((pos_board[2][0]=='X')&&(pos_board[1][1]=='X')&&(pos_board[0][0]!='O'))
 {
 a=0;
 b=2;
 }
 else if((pos_board[1][1]=='X')&&(pos_board[0][2]=='X')&&(pos_board[2][0]!='O'))
 {
 a=2;
 b=0;
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 
int check_player_line()
 {
 if(check1()==0)
 {
 return 0;
 }
 else if(check2()==0)
 {
 return 0;
 }
 else if(check3()==0)
 {
 return 0;
 }
 else if(check4()==0)
 {
 return 0;
 }
 else
 {
 return 1;
 }
 }
 
void find_blank_c3() // To find blank position in proximity of computer position when count=3 and z=1
 {
 int i,j,k;
 for(i=0; i<3; ++i)
 {
 for(j=0; j<3; ++j)
 {
 if((i+j)%2!=0)
 {
 continue;
 }
 else
 {
 if(pos_board[i][j]=='O')
 {
 if((i==0)&&(j==0))
 {
 if((pos_board[0][1]=='-')&&(pos_board[0][2]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=2;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[1][0]=='-')&&(pos_board[2][0]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=0;
 return;
 }
 }
 }
 else if((i==0)&&(j==2))
 {
 if((pos_board[0][0]=='-')&&(pos_board[0][1]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[1][2]=='-')&&(pos_board[2][2]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=2;
 return;
 }
 }
 }
 else if((i==2)&&(j==2))
 {
 if((pos_board[2][0]=='-')&&(pos_board[2][1]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[0][2]=='-')&&(pos_board[1][2]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=2;
 return;
 }
 }
 }
 else if((i==2)&&(j==0))
 {
 if((pos_board[2][1]=='-')&&(pos_board[2][2]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=2;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[0][0]=='-')&&(pos_board[1][0]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=0;
 return;
 }
 }
 }
 else if((i==1)&&(j==1))
 {
 if((pos_board[1][0]=='-')&&(pos_board[1][2]=='-'))
 {
 blank_count=2;
 }
 if(blank_count==2)
 {
 blank_row=1;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[0][1]=='-')&&(pos_board[2][1]=='-'))
 {
 blank_count=2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=1;
 return;
 }
 else
 {
 if((pos_board[0][0]=='-')&&(pos_board[2][2]=='-'))
 {
 blank_count=2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=0;
 return;
 }
 else
 {
 if((pos_board[2][0]=='-')&&(pos_board[0][2]=='-'))
 {
 blank_count=2;
 }
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=2;
 return;
 }
 }
 }
 }
 }
 }
 }
 }
 }
 
void find_blank_c4() // To find blank position in proximity of computer position when count=4 and z=2
 {
 int i,j,k;
 for(i=0; i<3; ++i)
 {
 for(j=0; j<3; ++j)
 {
 if((pos_board[i][j]=='O'))
 {
 if((i==0)&&(j==0))
 {
 for(k=1; k<3; ++k)
 {
 if(pos_board[0][k]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=2;
 return;
 }
 else
 {
 blank_count=0;
 for(k=1; k<3; ++k)
 {
 if(pos_board[k][0]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=0;
 return;
 }
 }
 }
 else if((i==0)&&(j==2))
 {
 if((pos_board[0][1]=='-')&&(pos_board[0][0]=='-'))
 {
 blank_count++;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[1][2]=='-')&&(pos_board[2][2]=='-'))
 {
 blank_count++;
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=2;
 return;
 }
 }
 }
 else if((i==2)&&(j==2))
 {
 for(k=0; k<2; ++k)
 {
 if(pos_board[2][k]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 for(k=0; k<2; ++k)
 {
 if(pos_board[k][2]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=2;
 return;
 }
 }
 }
 else if((i==2)&&(j==0))
 {
 for(k=1; k<3; ++k)
 {
 if(pos_board[2][k]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=2;
 blank_column=2;
 return;
 }
 else
 {
 blank_count=0;
 for(k=0; k<2; ++k)
 {
 if(pos_board[k][0]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=0;
 return;
 }
 }
 }
 else if((i==1)&&(j==1))
 {
 for(k=0; k<3; k=k+2)
 {
 if(pos_board[k][k]=='-')
 {
 blank_count++;
 }
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[2][0]=='-')&&(pos_board[0][2]=='-'))
 {
 blank_count=blank_count+2;
 }
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=2;
 return;
 }
 else
 {
 if((pos_board[1][0]=='-')&&(pos_board[1][2]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=1;
 blank_column=0;
 return;
 }
 else
 {
 blank_count=0;
 if((pos_board[0][1]=='-')&&(pos_board[2][1]=='-'))
 {
 blank_count=blank_count+2;
 }
 if(blank_count==2)
 {
 blank_row=0;
 blank_column=1;
 return;
 }
 }
 }
 }
 }
 }
 }
 }
 
int check1_AI()
 {
 a=3;
 b=3;
 int i,j;
 for(i=0; i<3; ++i)
 {
 if((pos_board[i][0]=='O')&&(pos_board[i][1]=='O')&&(pos_board[i][2]!='X'))
 {
 a=i;
 b=2;
 }
 else if((pos_board[i][1]=='O')&&(pos_board[i][2]=='O')&&(pos_board[i][0]!='X'))
 {
 a=i;
 b=0;
 }
 else if((pos_board[i][0]=='O')&&(pos_board[i][2]=='O')&&(pos_board[i][1]!='X'))
 {
 a=i;
 b=1;
 }
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 
int check2_AI()
 {
 a=3;
 b=3;
 int i,j;
 for(j =0;j<3;++j)
 {
 if((pos_board[0][j]=='O')&&(pos_board[1][j]=='O')&&(pos_board[2][j]!='X'))
 {
 a=2;
 b=j;
 }
 else if((pos_board[1][j]=='O')&&(pos_board[2][j]=='O')&&(pos_board[0][j]!='X'))
 {
 a=0;
 b=j;
 }
 else if((pos_board[0][j]=='O')&&(pos_board[2][j]=='O')&&(pos_board[1][j]!='X'))
 {
 a=1;
 b=j;
 }
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 int check3_AI()
 {
 a=3;
 b=3;
 if((pos_board[0][0]=='O')&&(pos_board[1][1]=='O')&&(pos_board[2][2]!='X'))
 {
 a=2;
 b=2;
 }
 else if((pos_board[1][1]=='O')&&(pos_board[2][2]=='O')&&(pos_board[0][0]!='X'))
 {
 a=0;
 b=0;
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 int check4_AI()
 {
 a=3;
 b=3;
 if((pos_board[2][0]=='O')&&(pos_board[1][1]=='O')&&(pos_board[0][2]!='X'))
 {
 a=0;
 b=2;
 }
 else if((pos_board[1][1]=='O')&&(pos_board[0][2]=='O')&&(pos_board[2][0]!='X'))
 {
 a=2;
 b=0;
 }
 if(a==3)
 {
 return 1;
 }
 else
 return 0;
 }
 
int check_computer_line()
 {
 if(check1_AI()==0)
 {
 return 0;
 }
 else if(check2_AI()==0)
 {
 return 0;
 }
 else if(check3_AI()==0)
 {
 return 0;
 }
 else if(check4_AI()==0)
 {
 return 0;
 }
 else
 {
 return 1;
 }
 }
 
void draw()
 {
 draw_count=1;
 printf("\n\nGame draw!!!!!\n");
 return;
 }
 
void computer()
 {
 if(z==1)
 {
 if(count==1)
 {
 if(pos_board[1][1]=='X')
 {
 pos_board[0][0]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else
 {
 pos_board[1][1]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else if(count==3)
 {
 check_player_line(); //To check if player has two continous X
 if(a==3)
 {
 find_blank_c3();
 pos_board[blank_row][blank_column]='O';
 count++;
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 }
 else
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else if(count==5)
 {
 check_computer_line();
 if(a==3)
 {
 if(check_player_line()==0)
 {
 pos_board[a][b]='O';
 count++;
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 }
 else
 {
 find_blank_c3();
 pos_board[blank_row][blank_column]='O';
 count++;
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 }
 }
 else
 {
 pos_board[a][b]='O';
 count++;
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 }
 }
 else if(count==7)
 {
 check_computer_line();
 if(a==3)
 {
 if(check_player_line()==0)
 {
 pos_board[a][b]='O';
 count++;
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 }
 else
 {
 draw();
 }
 
}
 else
 {
 pos_board[a][b]='O';
 count++;
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 }
 }
 
}
 
if(z==2)
 {
 if(count==0)
 {
 pos_board[1][1]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else if(count==2)
 {
 if(pos_board[0][0]!='X')
 {
 pos_board[0][0]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else if(pos_board[0][2]!='X')
 {
 pos_board[0][2]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else if(pos_board[2][0]!='X')
 {
 pos_board[2][0]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else if(pos_board[2][2]!='X')
 {
 pos_board[2][2]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else if(count==4)
 {
 check_computer_line();
 if(a==3)
 {
 if(check_player_line()==0)
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else
 {
 find_blank_c4();
 pos_board[blank_row][blank_column]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else if(count==6)
 {
 check_computer_line();
 if(a==3)
 {
 if(check_player_line()==0)
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else
 {
 find_blank_c4();
 pos_board[blank_row][blank_column]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 else if(count==8)
 {
 check_computer_line();
 if(a==3)
 {
 if(check_player_line())
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 else
 {
 draw();
 }
 }
 else
 {
 pos_board[a][b]='O';
 printf("\n\nAfter computer's turn board is : \n\n");
 print();
 count++;
 }
 }
 }
 }
 
void player_win()
 {
 int i;
 for(i=0;i<3;i++)
 {
 if(pos_board[i][0]=='X' && pos_board[i][1]=='X' && pos_board[i][2]=='X')
 {
 player_count=1;
 printf("\n\nCongrats %s you win\n",name);
 return;
 }
 }
 for(i=0;i<3;i++)
 {
 if(pos_board[0][i]=='X' && pos_board[1][i]=='X' && pos_board[2][i]=='X')
 {
 player_count=1;
 printf("\n\nCongrats %s you win\n",name);
 return;
 }
 }
 if(pos_board[0][0]=='X' && pos_board[1][1]=='X' && pos_board[2][2]=='X')
 {
 player_count=1;
 printf("\n\nCongrats %s you win\n",name);
 return;
 }
 else if(pos_board[0][2]=='X' && pos_board[1][1]=='X' && pos_board[2][0]=='X')
 {
 player_count=1;
 printf("\n\nCongrats %s you win\n",name);
 return;
 }
 }
 
void computer_win()
 {
 int i;
 for(i=0;i<3;i++)
 {
 if((pos_board[i][0]=='O')&&(pos_board[i][1]=='O')&&(pos_board[i][2]=='O'))
 {
 computer_count=1;
 printf("\n\nComputer wins!!!!!\n");
 return;
 }
 }
 for(i=0;i<3;i++)
 {
 if(pos_board[0][i]=='O' && pos_board[1][i]=='O' && pos_board[2][i]=='O')
 {
 computer_count=1;
 printf("\n\nComputer wins!!!!!\n");
 return;
 }
 }
 if(pos_board[0][0]=='O' && pos_board[1][1]=='O' && pos_board[2][2]=='O')
 {
 computer_count=1;
 printf("\n\nComputer wins!!!!!\n");
 return;
 }
 else if(pos_board[0][2]=='O' && pos_board[1][1]=='O' && pos_board[2][0]=='O')
 {
 computer_count=1;
 printf("\n\nComputer wins!!!!!\n");
 return;
 }
 }
 
int main()
 {
 int i,j;
 char w;
 printf("\nEnter player name : ");
 scanf(" %s",&name);
 start :printf("\nHello %s ,Wanna play tic tac toe!!! (y or n )\n",name);
 scanf(" %c",&w);
 if(w=='y' || w=='Y')
 {
 char ch='y';
 while((ch=='y')||(ch=='Y'))
 {
 printf("\n%s, You want to start (press 1) or you want computer to start (press 2) : ",name);
 scanf(" %d",&z);
 if((z!=1)&&(z!=2))
 {
 printf("\nYou entered wrong value....... try entering correct value....\n");
 continue;
 }
 
switch(z)
 {
 case 1:
 count=0;
 computer_count=0;
 player_count=0;
 draw_count=0;
 for(i=0; i<3; ++i)
 {
 for(j=0; j<3; ++j)
 {
 pos_board[i][j]='-';
 }
 }
 a=3;
 b=3;
 blank_count=0;
 while((computer_count==0)&&(player_count==0)&&(count<9)&&(draw_count==0))
 {
 player();
 if(count>=5)
 {
 player_win();
 if(player_count==1)
 break;
 }
 computer();
 if(count>=5)
 {
 computer_win();
 if(computer_count==1)
 break;
 }
 if((count==8)&&(check_player_line()==1))
 {
 draw();
 }
 }
 if((count==9)&&(player_count==0)&&(computer_count==0)&&(draw_count==0))
 {
 draw();
 }
 break;
 case 2:
 count=0;
 computer_count=0;
 player_count=0;
 draw_count=0;
 for(i=0; i<3; ++i)
 {
 for(j=0; j<3; ++j)
 {
 pos_board[i][j]='-';
 }
 }
 a=3;
 b=3;
 blank_count=0;
 while((computer_count==0)&&(player_count==0)&&(count<9)&&(draw_count==0))
 {
 computer();
 if(count>=4)
 {
 computer_win();
 if(computer_count==1)
 break;
 }
 player();
 if(count>=4)
 {
 player_win();
 if(player_count==1)
 break;
 }
 if((count==8)&&(check_computer_line()==1))
 {
 draw();
 }
 }
 if((count==9)&&(player_count==0)&&(computer_count==0)&&(draw_count==0))
 {
 draw();
 }
 break;
 
}
 printf("\n\nWant to play again!!!!!!! (y/n)");
 scanf(" %c",&ch);
 }
 }
 else if(w=='n' || w=='N')
 {
 printf("\n\t\tBye %s Have A Nice Day !!!",name);
 }
 else
 {
 printf("\nTry entering valid input (either y/Y or n/N)\n");
 goto start;
 }
 }

/* 
Related posts

 
Read more ?
 
 
Pattern 25 (C Program)
1

Read more ?
 
 
Change Case of a String(C Program)
3

/*convert strint into upper & lower case without using strlwr & strupr*/ /*#include <stdio.h> using namespace std; void upper_string(char*); void lower_string(c[...]
By Ashish

Like us on Facebook

 
Latest Posts

 

    javam
    Print Number in Triangle Shape [Java]
        0
        0
    Pascals Triangle
    Pascal's Triangle [C++]
        0
        3
    Screenshot (20)
    Rock-Paper-Scissors-Lizard-Spock game against Bot ...
        0
        3

Categories

 

    C
    C++
    Java
    Linux
    PHP
    Python
    Ruby
    Uncategorized

*/
