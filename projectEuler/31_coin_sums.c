#include <stdio.h>
#define f(i,a,b) for(int i = (a); i <= (b); ++i)
#define ll long long 

int main()
{
	ll sum = 1;

	f(b,0,2)
	{
		f(c,0,4)
		{
			f(d,0,10)
			{
				f(e,0,20)
				{
					f(f,0,40)
					{
						f(g,0,100)
						{
							f(h,0,200)
							{
								if (b*100 + c*50 + d*20 + e*10 + f*5 + g*2 + h*1 == 200)
								{
									++sum;
								}
							}
						}
					}
				}
			}
		}
	}

	printf("%lld\n", sum);
}
