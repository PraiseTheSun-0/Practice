#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n, counter=1, temp;
	cin >> n;
	int *min = new int[n];
	int *A = new int[n];
	for (int i = 0; i < n; i++)	cin >> A[i];
	while (counter <= n) {
		for (int k = 0; k < counter; k++)min[k] = A[k];
		for (int m = 1; m < counter; m++) {
			for (int l = 0; l < counter-1; l++) {
				if (min[l] > min[l + 1]) {
					temp = min[l];
					min[l] = min[l + 1];
					min[l + 1] = temp;
				}
			}
		}
		for (int f = 1; f < counter && f < 5; f++) {
			for (int r = 0; r < counter - 1 && r < 4; r++) {
				if (min[r + 1] > min[r]) {
					temp = min[r];
					min[r] = min[r + 1];
					min[r + 1] = temp;
				}
			}
		}
		for (int b = 0; b < counter && b < 5; b++) {
			cout << min[b] << ' ';
		}
		cout << endl;
		counter++;
	}
	delete[] min;
	delete[] A;
}
