#include <cstdio>

#define M 10000000

int a[M + 1], p[M + 1], b[M / 15], c[M + 1], i, j, n, m, k, x, y, t;

int main()
{
	scanf("%d", &n);

	for (i = 0; i < n; i ++)
	{
		scanf("%d", &x), ++c[x];
		if (x > t)
			t = x;
	}

	b[k++] = p[2] = 2;

	for (i = 3; i <= t; i += 2)
	{
		if (p[i] == 0)
			p[i] = b[k ++] = i;
		for (j = 0; j < k && b[j] <= p[i] && i * b[j] <= t; j ++)
			p[i * b[j]] = b[j];
	}

	for (j = 0; j < k; j ++)
		for (i = b[j]; i <= t; i += b[j])
			a[b[j]] += c[i];

	for (i = 3; i <= t; i ++)
		a[i] += a[i - 1];

	scanf("%d", &m);

	while (m--)
	{
		scanf("%d%d", &x, &y);
		if (y > t)
			y = t;
		if (x <= y)
			printf("%d\n", a[y] - a[x - 1]);
		else
			puts("0");
	}

	return 0;
}
