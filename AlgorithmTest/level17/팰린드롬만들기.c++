#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int d[MAX][MAX] = { 0, };
char str1[1010];

int main() {
  
	scanf("%s", str1);

	int len1 = strlen(str1);
	
	d[len1][len1];
	
	d[0][0] = 0;

	for (int i = 1; i < len1; i++) {
		for (int j = 0; j < len1-i; j++) {
			if (str1[j] == str1[i+j]) {
				d[j][i+j] = d[j+1][i+j-1];
			}
			else {
				d[j][i+j] = 1+ min(d[j][i+j-1], d[j+1][i+j]);
			}
		}
	}
	
// 	for (int i = 0; i < len1; i++) {
// 		for (int j = 0; j < len1; j++) {
// 			printf("%d ",d[i][j]);
// 		}
// 		printf("\n");
// 	}

	printf("%d\n", d[0][len1-1]);

	return 0;
} 
