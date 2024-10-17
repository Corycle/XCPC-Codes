#include <bits/stdc++.h>
using namespace std ;
int t ;
int n ;
int a[1000010] ;
int main ()
{
	scanf( "%d" , &t ) ;
	while( t -- )
	{
		scanf( "%d" , &n ) ;
		long long ans = 0 ;
		for( int i = 0 ; i < n ; i ++ )
		{
			scanf( "%d" , &a[i] ) ;
		}
		sort( a , a + n ) ;
		if( n == 1 )
		{
			printf( "%d\n" , a[0] ) ;
		}
		else
		{
			ans -= a[0] ;
			ans += a[n - 1] ;
			for( int i = 1 ; i < n - 1 ; i ++ )
			{
				ans += abs( a[i] ) ;
			}
			printf( "%lld\n" , ans ) ;
		}
	}
	return 0 ;
}
