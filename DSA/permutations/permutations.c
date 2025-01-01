void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(int *i, int *j)
{
	--j;

	while (i < j)
	{
		swap(i, j);
		++i; --j;
	}
}

int next_permutation(int *begin, int *end)
{
	if (begin == end) { return 0; }
	
	int *i = begin;
        ++i;

        if (i == end) { return 0; }

        i = end;
        --i;

	while (1)
        {
                int *j = i;
                --i;

                if (*i < *j)
                {
                        int *k = end;

                        while (!(*i < *--k))
                                /* pass */;

                        swap(i, k);
                        reverse(j, end);
                        return 1;
                }

                if (i == begin)
                {
			reverse(begin, end);
                        return 0;
                }
        }
}
