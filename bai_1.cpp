#include<stdio.h>
#include<conio.h>

//---- DANH SACH LIEN KET DON---- 
// TO CHUC DANH SACH 
typedef int ItemType; //ItemType có thể là kiểu  float, SINHVIEN,PHÁNO,

struct SNode
{
	ItemType Info; //  Lưu thông tin( dữ liệu) của bản thân .
	SNode* Next;   // Con trỏ đến SNode kế tiếp 

};

struct SList
{// kiểu danh sách liên kêt đơn 
	SNode* Head; //lưu địa chỉ của SNode đầu tiên trong danh sách 
	SNode* Tail; //lưu địa chỉ của SNode cuối cùng trong danh sách 
};

// Hàm trrar về phần tử mới tạo như sau:
SNode* createSNode(ItemType x)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		printf("Không đủ bộ nhớ để cấp phát nút mới! ");
		//B_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

//Khởi tạo danh sách rỗng 
void initSList(SList& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}

//Kiểm tra danh sách đơn rỗng 
int isEmpty(SList sl)
{
	if (sl.Head == NULL)
	   return	 1; // Nếu danh sách rỗng 
	else
		return 0; // Nếu danh sách không rỗng 
}

//Thêm 1 phần tử vào đầu danh sách 
int insertHead(SList& sl, SNode* p)
{
	if (p == NULL)
		return 0; //Thực hiện không thành công 
	if (isEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;//Thực hiện thành công 
}

//Thêm 1 phần tử vào cuối danh sách 
int insertTail(SList& sl, SNode* p)
{
	if (p == NULL)
		return 0; //Thực hiện không thành công 
	if (isEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Head->Next = p;
		sl.Tail = p;
	}
	return 1;//Thực hiện thành công 
}

//Thêm 1 phần tử vào sau phần tử q 
int insertAfter(SList& sl, SNode* q, SNode* p)
{
	if (q == NULL || p == NULL)
		return 0;// Thực hiện không thành công 
	p->Next = q->Next;
	q->Next = p;
	if (sl.Tail == q)
		sl.Tail = p;
	return 1;// Thực hiện thành công 
}

//Tìm kiếm phần tử trong danh sách 
SNode* findSNode(SList sl, ItemType x)
{
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
		if (p->Info == x)
			return p; //Trả về p khác NULL: tìm thấy 
	return NULL; //Trả về NULL không tìm thấy 
}

// Xóa phần tử đầu danh sách 
int deleteHead(SList sl, ItemType& x)
{
	if (isEmpty(sl) == 1)
		return 0; //Thực hiệ không thành công
	SNode* p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL)
		sl.Tail == NULL;
	x = p->Info; //Lấy thông tin của nút bị hủy
	delete p; //Hủy nút do p trỏ đến 
	return 1; //Thực hiện thành công
}

// Xóa phần tử cuối danh sách 
int deleteTail(SList sl, ItemType& x)
{
	if (isEmpty(sl) == 1)
		return 0; //Thực hiệ không thành công
	SNode* p = sl.Tail;
	SNode* q = sl.Head;
	if (p == q)
		sl.Head = sl.Tail;
	else
	{
		while (q->Next != p) //Tìm nút kế trước nút Tail
			q = q->Next;
		sl.Tail = q;
		sl.Tail->Next = NULL;
	}
	x = p->Info; // Lấy thông tin của nút bị hủy
	delete p; //Hủy nút p trỏ đến 
	return 1; // Thực hiện thành công 
}

//Xóa phần tử sau phầng tử q của danh sách 
int deleteAfter(SList& sl, SNode* q, ItemType& x)
{
	if (q == NULL || q->Next == NULL)
		return 0;// Thực hiện không thành công 
	SNode* p = q->Next;
	q->Next = p->Next;
	if (sl.Tail == q)
		sl.Tail = p;
	x = p->Info; // Lấy thông tin của nút bị hủy
	delete p; //Hủy nút p trỏ đến 
	return 1;// Thực hiện thành công 
}

//Xóa một phần tử có khóa x 
int deleteSNodeX(SList sl, ItemType& x)
{
	if (isEmpty(sl) == 1)
		return 0; //Thực hiệ không thành công
	SNode* p = sl.Head;
	SNode* q = NULL; //sẽ trỏ đến nút kế trước p
	while ((p != NULL) && (p->Info != x))
	{// vòng lặp tìm nút p chứ x , q là nút trước p
		q = p;
		p = p->Next;
	}
	if (p == NULL)// không tìm thấy phần tử có khóa bằng x 
		return 0; // thực hiện không thành công 
	if (p == sl.Head) // p có khóa bằng x là nút đầu danh sách 
		deleteHead(sl, x);
	else //xóa nút p có khóa x nằm kế sau nút q
		deleteAfter(sl, q, x);
	return 1; // thực hiện thành công
}

// Duyệt danh sách 
// cài đặt (tổng quát )
void processSList(SList sl)
{
	if (isEmpty(sl) == 1)
	{
		printf("\n Danh sach rong!");
		return;
	}
	SNode* p = sl.Head;
	while (p != NULL)
	{
		//< Xử lí nút p trường hợp cụ thể >
		p = p->Next;
	}
}

//Hàm in nội dung danh sách ra màn hình 
void showSList(SList sl)
{
	if (isEmpty(sl) == 1)
	{
		printf("\n Danh sach rong!");
		return;
	}
	printf("\n Noi dung danh sach la: ");
	SNode* p = sl.Head;
	while (p != NULL)
	{
		printf("%4d", p->Info); // xuất nội dung của nút p
		p = p->Next;
	}
}

//Hủy toàn bộ danh sách 
int  deleteSList(SList& sl)
{
	if (isEmpty(sl) == 1)
		return 0; // thực hiện không thành công
	while (sl.Head != NULL)
	{
		SNode* p = sl.Head;
		sl.Head = sl.Head->Next;
		delete p; // Hoặc gọi hàm đã viết deleteSNode(p);
	}
	sl.Tail = NULL;
	return 1; //Thực hiện thành công

}