#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
void menu();
void nhapMang1Chieu(int a[], int& n);
void xuatMang1Chieu(int a[], int n);
float tinhGiaTriTrungBinh(int a[], int n);
int main()
{
	int arr[MAX], soPhanTu, luaChon;
	for (;;)
	{
		system("cls");//làm sạch (xoá) màn hình
		menu();
		printf(">> Nhap lua chon: "); scanf_s("%d", &luaChon);
		if (luaChon == 0)break;
		switch (luaChon)
		{
		case 1:
			nhapMang1Chieu(arr, soPhanTu);
			printf("Mang vua nhap:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 2:
			printf("Mang vua nhap:\n");
			xuatMang1Chieu(arr, soPhanTu);
			break;
		case 3:
			xuatMang1Chieu(arr, soPhanTu);
			printf("\nGia tri trung binh: %.2f", tinhGiaTriTrungBinh(arr, soPhanTu));
			break;
		default:printf("Vui long lua chon lai!\n");
			break;
		}
		_getch();
	}
	return 0;
}
void menu()
{
	printf("0. Thoat chuong trinh\n");
	printf("1. Nhap mang 1 chieu\n");
	printf("2. Xuat mang 1 chieu\n");
	printf("3. Tinh gia tri trung binh cac phan tu cua mot mang\n");
}
void nhapMang1Chieu(int a[], int& n)
{
	do {
		printf(">> Nhap so luong phan tu n (n > 0): "); scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= ", i);
		scanf_s("%d", &a[i]);
	}
}
void xuatMang1Chieu(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);
}
float tinhGiaTriTrungBinh(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	float result = 1.0 * sum / n;
	return result;
}
