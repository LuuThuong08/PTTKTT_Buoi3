#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int Tong1nKoDeQui(int l, int r) {
	if (l == r) {
		return l;
	}

	int mid = l + (r - l) / 2;

	int leftSum = Tong1nKoDeQui(l, mid);
	int rightSum = Tong1nKoDeQui(mid + 1, r);

	return leftSum + rightSum;
}
int Tong1nDeQui(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return Tong1nDeQui(n - 1) + n;
	}
}
int main() {
	int chon;
	int n;
	do
	{
		printf("\n---Menu---");
		printf("\n1.Tinh tong mang 1 den n khong de Qui");
		printf("\n2.Tinh tong mang 1 den n de quy");
		printf("\nNhap lua chon:");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:{
			printf("\nNhap n");
			scanf("%d", &n);

			int Tong = Tong1nKoDeQui(1, n);

			printf("Tong: %d\n", Tong);
		}break;
		case 2:{
			printf("\nNhap n");
			scanf("%d", &n);
			int Tong = Tong1nDeQui(n);
			printf("Tong cac so tu 1 den %d la: %d\n", n, Tong);
		}break;
		default:
			break;
		}
	} while (chon != 0);
	
	getchar();
	return 0;
}

