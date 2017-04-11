#include <stdio.h>

#ifdef _WIN32
#define FORMAT "%I64d"
#else
#define FORMAT "%lld"
#endif

int main()
{
	unsigned long long n, m, a;

	while ( scanf( FORMAT" "FORMAT" "FORMAT, &n, &m, &a) == 3 )
	{
		unsigned long long w = n % a == 0 ? n / a : n / a + 1 ;
		unsigned long long h = m % a == 0 ? m / a : m / a + 1 ;

		printf(FORMAT"\n", w*h);
	}

	return 0;
}
