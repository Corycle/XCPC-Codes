#include <bits/stdc++.h>
using namespace std ;
int t , n , a[100010] ;
bool bh[100010][4] ;
bool kx[100010] ;
int bz[400010] , as ;

int main ()
{
//	freopen("L.in","r",stdin);
//	freopen("L.out","w",stdout);
	scanf( "%d" , &t ) ;
	while( t -- )
	{
		char tmp ;
		scanf( "%d\n" , &n ) ;
		for( int i = 0 ; i < n ; i ++ )
		{
			scanf( "%c" , &tmp ) ;
			a[i] = tmp - '0' ;
		}
		if( n == 1 )
		{
			if( a[0] == 1 ) printf( "0\n" ) ;
			else printf( "1\n1\n" ) ;
			continue ;
		}
		else if( n == 2 )
		{
			if( a[0] == a[1] && a[0] == 1 ) printf( "0\n" ) ;
			else if( a[0] == a[1] && a[0] == 0 ) printf( "1\n1\n" ) ;
			else printf( "0\n" ) ;
			continue ;
		}
		else if( n == 3 )
		{
			if( a[0] == 0 && a[1] == 0 && a[2] == 0 ) printf( "1\n1\n" ) ;
			else printf( "0\n" ) ;
			continue ;
		}
//		printf( "111" ) ;
		bh[0][1] = bh[1][2] = bh[0][3] = bh[1][3] = 1 ;
		bh[0][0] = bh[1][0] = bh[1][1] = bh[0][2] = 0 ;
		bool flg = 0 ;
		for( int i = 2 ; i < n ; i ++ )
		{
			for( int j = 0 ; j < 4 ; j ++ )
			{
				if( a[i - 1] ^ bh[i - 1][j] ^ bh[i - 2][j] == 1 )
				{
					bh[i][j] = 0 ;
				}
				else
				{
					bh[i][j] = 1 ;
				}
			}
		}
		for( int j = 0 ; j < 4 ; j ++ )
		{
//			for( int i = 0 ; i < n ; i ++ )
//			{
//				printf( "%d " , bh[i][j] ) ;
//			}
//			printf( "\n" ) ;
			if( a[0] ^ bh[0][j] ^ bh[1][j] ^ bh[n - 1][j] == 1 && a[n - 1] ^ bh[0][j] ^ bh[n - 1][j] ^ bh[n - 2][j] == 1 )
			{
				for( int i = 0 ; i < n ; i ++ )
				{
					kx[i] = bh[i][j] ;
				}
				flg = 1 ;
			}
		}
//		for( int j = 0 ; j < n ; j ++ )
//		printf( "%d " , kx[j] ) ;
		if( !flg )
		{
			printf( "0\n" ) ;
			continue ;
		}
		as = 0 ;
		for( int i = 0 ; i < n ; i ++ )
		{
			if( kx[i] )
			if( a[i] == 0 )
			{
				bz[as] = i + 1 ;
				a[(i - 1 + n)% n] ^= 1 ;
				a[i] ^= 1 ;
				a[(i + 1) % n] ^= 1 ;
				as ++ ;
			}
			else
			{
				int j ;
				for( j = i ; j < n ; j ++ )
				{
					if( a[j] == 0 )
					{
						break ;
					}
				}
				if( j == n )
				{
					if( a[i - 1] == 0 )
					{
						bz[as] = i ;
						bz[as + 1] = i + 1 ;
						bz[as + 2] = i ;
						a[(i - 1 + n)% n] ^= 1 ;
						a[i] ^= 1 ;
						a[(i + 1) % n] ^= 1 ;
						as += 3 ;
					}
					else if( a[0] == 0 )
					{
						for( int k = n ; k != i ; k -- )
						{
							kx[k % n] ^= 1 ;
							bz[as] = k % n + 1 ;
							a[(k % n - 1 + n)% n] ^= 1 ;
							a[k % n] ^= 1 ;
							a[(k % n + 1) % n] ^= 1 ;
							as ++ ;
						}
						bz[as] = 1 ;
						a[0] ^= 1 ;
						a[1] ^= 1 ;
						a[n - 1] ^= 1 ;
						as ++ ;
					}
					else
					{
						break ;
					}
				}
				else if( j == n - 1 && i == 0 )
				{
					bz[as] = n ;
					bz[as + 1] = 1 ;
					a[n - 2] ^= 1 ;
					a[1] ^= 1 ;
					as += 2 ;
					kx[n - 1] ^= 1 ;
				}
				else
				{
					for( ; j > i ; j -- )
					{
						kx[j] ^= 1 ;
						bz[as] = j + 1 ;
						a[(j - 1 + n)% n] ^= 1 ;
						a[j] ^= 1 ;
						a[(j + 1) % n] ^= 1 ;
						as ++ ;
					}
					bz[as] = i + 1 ;
					a[(i - 1 + n)% n] ^= 1 ;
					a[i] ^= 1 ;
					a[(i + 1) % n] ^= 1 ;
					as ++ ;
				}
			}
		}
		printf( "%d\n" , as ) ;
		for( int i = 0 ; i < as ; i ++ )
		{
			printf( "%d" , bz[i] ) ;
			if( i != as - 1 ) printf( " " ) ;
		}
		printf( "\n" ) ;
	}
	return 0 ;
}
