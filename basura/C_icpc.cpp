#include <bits/stdc++.h>
using namespace std;

int L, W, H, MAX = 0;

void rotacion(int l, int w, int h)
{
	int l_size, w_size, h_size;
	l_size = L / l;
	w_size = W / w;
	h_size = H / h;
	
	MAX = max( l_size * w_size * h_size , MAX);
}

int main()
{
	int l, w, h;
	cin >> L >> W >> H;
	cin >> l >> w >> h;
	
	rotacion(l, w, h);
	rotacion(l, h, w);
	rotacion(w, l, h);
	rotacion(w, h, l);
	rotacion(h, w, l);
	rotacion(h, l, w);

	cout << MAX << endl;
}
