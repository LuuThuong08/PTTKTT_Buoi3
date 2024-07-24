#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TimKiemNhiPhanKoDeQui(int arr[], int n, int target) {
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == target) {
			return mid; 
		}
		else if (arr[mid] < target) {
			low = mid + 1; 
		}
		else {
			high = mid - 1; 
		}
	}

	return -1; 
}
int TimKiemNhiPhanDeQui(int arr[], int low, int high, int target) {
	if (low > high) {
		return -1; 
	}
	int mid = (low + high) / 2;

	if (arr[mid] == target) {
		return mid; 
	}
	else if (arr[mid] < target) {
		return TimKiemNhiPhanDeQui(arr, mid + 1, high, target);
	}
	else {
		return TimKiemNhiPhanDeQui(arr, low, mid - 1, target);
	}
}
int main() {
	int chon;
	int n;
	do
	{
		printf("\n---Menu---");
		printf("\n1.Tim kiem nhi phan de qui");
		printf("\n2.Tim kiem nhi phan khong de qui");
		printf("\nNhap lua chon:");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:{
				   int arr[] = { 1, 3, 8, 15, 23, 42, 56, 78, 91, 100 }; 
				   int n = sizeof(arr) / sizeof(arr[0]); 

				   int t;
				   printf("Nhap muc gia tri can tim: ");
				   scanf("%d", &t);

				   int index = TimKiemNhiPhanDeQui(arr, 0, n - 1, t);

				   if (index != -1) {
					   printf("Tim thay %d tai %d\n", t, index);
				   }
				   else {
					   printf("Khong tim thay %d trong mang\n", t);
				   }
		}break;
		case 2:{
				   int arr[] = { 1, 3, 8, 15, 23, 42, 56, 78, 91, 100 };
				   int n = sizeof(arr) / sizeof(arr[0]);

				   int t;
				   printf("Nhap muc gia tri can tim: ");
				   scanf("%d", &t);
				   int index = TimKiemNhiPhanKoDeQui(arr, n, t);
				   if (index != -1) {
					   printf("Tim thay %d tai %d\n", t, index);
				   }
				   else {
					   printf("Khong tim thay %d trong mang\n", t);
				   }
		}break;
		default:
			break;
		}
	} while (chon != 0);

	getchar();
	return 0;
}