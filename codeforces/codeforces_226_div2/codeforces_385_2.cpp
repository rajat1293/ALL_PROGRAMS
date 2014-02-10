#include<iostream>
#include<string.h>
#include<set>
#include<utility>
#include<stdlib.h>
using namespace std;
set<pair<int,int> > ss;
//------------------------KMPPPPPPPPPPPPPPPP----------------
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt,int N)
{
    int M = 4;
    //int N = strlen(txt);
 	int cal;
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
       // printf("Found pattern at index %d \n", i-j);
   ////////////////////////////////////////////  
   	for(int al=i-j+M-1;al<N;al++){
        	cal = al - (i-j+M-1);
           for(int k=0;k<=i-j;k++){
           	ss.insert(make_pair(k+1,i-j+M-1+cal));
           }
		   //printf("Pattern found at index %d \n", i);
		}  
   //////////////////////////////////////////////     
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
     cout<<ss.size()<<endl;
    free(lps); // to avoid memory leak
}
 
//----------------------- 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
/* 
//---------------------
void search(char *pat, char *txt,int N)
{
    int M = 4;
    //int N = strlen(txt);
    int i = 0;
    int cal=0;
 
    while(i <= N - M)
    {
        int j;
 
         //For current index i, check for pattern match 
        for (j = 0; j < M; j++)
        {
            if (txt[i+j] != pat[j])
                break;
        }
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        {
        	for(int j=i+M-1;j<N;j++){
        	cal = j - (i+M-1);
           for(int k=0;k<=i;k++){
           	ss.insert(make_pair(k+1,i+M-1+cal));
           }
		   //printf("Pattern found at index %d \n", i);
		}
           i = i + M;
        }
        else if (j == 0)
        {
           i = i + 1;
        }
        else
        {
           i = i + j; // slide the pattern by j
        }
    }
    cout<<ss.size()<<endl;
}
*/
//----------------
int main(){
	char  s[5003];
//	char *j = s+1;
	cin>>s;
	char p[6]="bear";
	//cout<<p[1]<<p[2];
	KMPSearch(p,s,strlen(s));
}
