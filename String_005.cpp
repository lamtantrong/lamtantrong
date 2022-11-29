#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void menu();
void xoaXuongDong(char str[]);
void nhapChuoi(char str[]);
void xuatChuoi(char str[]);;
int length(char str[]);
void chuanHoaChuoi(char str[]);

int main()
{
	char str[100];
	int luaChon;
	for (;;)
	{
		system("cls");
		menu();
		printf(">> Nhap lua chon: "); scanf_s("%d", &luaChon);
		if (luaChon == 0)break;
		switch (luaChon)
		{
		case 1:
			nhapChuoi(str);
			printf("Chuoi vua nhap: ");
			xuatChuoi(str);
			break;
		case 2:
			printf("Chuoi vua nhap: ");
			xuatChuoi(str);
			break;
        case 3:
		    printf("Do dai chuoi: %d", length(str));
			break;
		case 4:
			printf("\nChuoi ban dau:\n");
			xuatChuoi(str);
			chuanHoaChuoi(str);
			printf("Sau khi chuan hoa chuoi thanh cong:\n");
			xuatChuoi(str);
			break;

		default:printf("Khong hop le! Vui long lua chon lai!\n");
			break;
		}
		_getch();
	}
	return 0;
}
void menu()
{
	printf("0. Thoat chuong trinh\n");
	printf("1. Nhap xuat chuoi\n");
	printf("2. Xuat chuoi vua nhap\n");
    printf("3. Xuat do dai cua chuoi\n");
	printf("4. Chuan hoa chuoi\n");
}
void xoaXuongDong(char str[])
{
	size_t len = strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
}
void nhapChuoi(char str[])
{
	printf("\n>> Nhap chuoi: ");
	getchar();

	//cách 1: Cần Hàm Xoá Xuống Dòng
	//fgets(str, 100, stdin);

	//cách 2: không cần Hàm Xoá Xuống Dòng
	gets_s(str, 100);
}
void xuatChuoi(char str[])
{
	printf("%s\n", str);
}
int length(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
void chuanHoaChuoi(char str[])
{
	//chuẩn hoá chuỗi bên trái
	while (str[0] == ' ')
		strcpy_s(str, 50, str + 1);

	//chuẩn hoá chuỗi bên phải
	int len = strlen(str);
	while (str[len - 1] == ' ')
	{
		str[len - 1] = '\0';
		len--;
	}
	//chuẩn hoá ở giữa
	char* p;
	while ((p = strstr(str, "  ")) != NULL)
	{
		strcpy_s(p, 50, p + 1);
	}
}
