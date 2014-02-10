#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
int main( void ) {
    int i, j;
    char s[ 5001 ], *p;
    int sLen, start[ 1251 ] = { -1 }, cnt, ans;
    scanf( "%s", s );
    sLen = strlen( s );

    cnt = 1;
    for ( p = s; ( p = strstr( p, "bear" ) ) != NULL; start[ cnt++ ] = p++ - s ) ;
//	for(int i=1;i<cnt;i++)
	//cout<<start[i]<<" ";
//	cout<<endl;
// the start[i] array stores the indexes of the pattern found 
// that is the starting points of the index at which the pattern is found
//  

    ans = 0;
    for ( i = 1; i < cnt; i++ ){
    
        ans += ( sLen - start[ i ] - 3 ) * ( start[ i ] - start[ i - 1 ] );
	//	cout<<ans<<" ";
		}

    printf( "%d\n", ans );

    return 0;
}
