#include"LIST.h"
int main()
{
	Node plist;
	Init_List(&plist);
	Insert_head(&plist, 1);
	Insert_head(&plist, 2);
	Insert_head(&plist, 3);
	Insert_head(&plist, 4);
	Insert_head(&plist, 5);
	Show_list(&plist);
	Contrary_list(&plist);
	Show_list(&plist);
	printf("ÔÚµÚ%d¸ö", Search(&plist, 4));
	system("pause");
	return 0;
}