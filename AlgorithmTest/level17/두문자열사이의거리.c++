#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_ = 1001;

int arr[MAX_][MAX_];
int d[MAX_][MAX_] = { 0, };
int ans[MAX_] = { 0, };
int n, m;
char str1[1010];
char str2[1010];
int main() {
	scanf("%s %s", str1, str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i <= len1; i++) {
		d[i][0] = i;
	}
	for (int i = 0; i <= len2; i++) {
		d[0][i] = i;
	}

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				d[i][j] = d[i - 1][j - 1];
			}
			else {
				d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1;
			}
		}
	}
	
// 	for (int i = 1; i <= len1; i++) {
// 		for (int j = 1; j <= len2; j++) {
// 			printf("%d ",d[i][j]);
// 		}
// 		printf("\n");
// 	}

	printf("%d\n", d[len1][len2]);

	return 0;
}
