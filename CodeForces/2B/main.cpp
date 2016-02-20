#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

int a[1001][1001][2];
char m[1001][1001][2];
int n;
int i, j, k, x = 0;

void print(int x, int y) {
  	if (x == 1 && y == 1) 
  		return ;
  	if (m[x][y][k]) 
  		print(x - 1, y), putchar('D');
  	else 
  		print(x, y - 1), putchar('R');
}

int main () {
	scanf("%d", &n);
  	memset(a, 0, sizeof a);
  	for (i = 2; i <= n; ++i) {
  		a[0][i][0] = a[0][i][1] = a[i][0][0] = a[i][0][1] = 999999999;
  	}
  	for (i = 1; i <= n; ++i) {
    	for (j = 1; j <= n; ++j) {
      		scanf("%d", &k);
      		if (!k) 
      			x = i;
      		else {
    			for (; !(k & 1); k >>= 1) 
    				++a[i][j][0];
    			for (; !(k % 5); k /= 5) 
    				++a[i][j][1];
      		}
      		//dp algorithm
      		for (k = 0; k < 2; ++k)
    			if ((m[i][j][k] = a[i - 1][j][k] < a[i][j - 1][k])) 
    				a[i][j][k] += a[i - 1][j][k];
    			else 
    				a[i][j][k] += a[i][j - 1][k];
    	}
    }

	k = a[n][n][1] < a[n][n][0];
  	if (x && a[n][n][k] > 1) {
    	puts("1");
    	for (i = 2; i <= x; ++i) putchar('D');
    	for (i = 2; i <= n; ++i) putchar('R');
    	for (i = x + 1; i <= n; ++i) putchar('D');
  	} else 
  		printf("%d\n", a[n][n][k]), print(n, n);
	
	return 0;	
}