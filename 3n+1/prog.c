#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, cycle, max_cycle, start, end, n, cycles[1000000] = {0};

	while(scanf("%d %d", &i, &j) != EOF)
	{
		max_cycle = 0;
		start = i;
		end = (j < start ? start = j, i : j);

		while(start <= end)
		{
			cycle = cycles[start];
			if(!cycle)
			{
				cycle = 1;
				n = start;
				while(n != 1)
				{
					n = (n & 1 ? n*3 + 1 : n >> 1);
					cycle++;
				}

				cycles[start] = cycle;
			}

			(cycle > max_cycle ? max_cycle = cycle : 0);
			start++;
		}

		printf("%d %d %d\n", i, j, max_cycle);
	}
	return 0;
}
