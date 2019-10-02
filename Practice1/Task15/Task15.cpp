#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *min = new int[n];
	int *A = new int[n];
	for (int i = 0; i < n; i++)	cin >> A[i];
	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= k && j <= 5; j++) {
			for (int l = 0; l < j; l++) {
				min[l] = A[l];
			}
			for (int b = 0; b < j; b++) {
				for (int b = 0; b < j - 1; b++){
					if (min[b] < min[b + 1]) {
						int temp = min[b];
						min[b] = min[b + 1];
						min[b + 1] = temp;
					}
				}
			}

			cout << min[j-1] << ' ';
		}
		cout << endl;
	}
}
