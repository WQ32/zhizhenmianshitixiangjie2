#include <stdio.h>

//// 例7： - 二维数组
//
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%p\n", &a[0][0]);
//	printf("%p\n", a[0] + 1);
//	printf("%p\n", a + 1);
//	printf("%p\n", &a[0] + 1);
//
//	printf("%d\n", sizeof(a));          
//	//48 这里是计算整个数组的大小 3*4*4=48
//	printf("%d\n", sizeof(a[0][0]));	
//	//4  这里是第一行第一列的即第一个元素
//	printf("%d\n", sizeof(a[0]));		
//	//16 把这个二维数组的每一行看做一个元素，元素名分别为a[0],a[1]，a[2]
//	//又由于每一行都是一个一位数组，即a[0][j],a[1][j],a[2][j],所以a[0]指的是第一行这个一维数组，
//	//即把a[0]这个一维数组数组名放在sizeof()里面，表示求一维整个数组的大小，所以结果为 4*4=16
//	printf("%d\n", sizeof(a[0] + 1));
//	//4 a[0]是第一行数组的名字
//	//a[0]放在表达式a[0]+1中，不表示整个数组，而表示二维数组第一行的首元素的地址，即第一个元素的地址，
//	//加一即表示第一行第二个元素的地址（不是变成第二行的地址），他始终是表示一个地址，大小就是 4
//	printf("%d\n", sizeof(*(a[0] + 1)));
//	//4  a[0]+1是第一行第二个元素的地址，解引用就是第一行第二个元素，int型大小4
//	printf("%d\n", sizeof(a + 1));		
//	//4  a是二维数组数组的数组名，没有sizeof(数组名)，也没有&(数组名)，就把二维数组看成一维数组
//	// a就是首元素地址，而二维数组的首元素是它的第一行，a就是第一行（首元素）的地址
//	// 所以a+1表示第二行的地址
//	printf("%d\n", sizeof(*(a + 1)));	
//	//16 a+1是第二行数组的地址，解引用就是这个第二行数组的大小，一共4个元素，即4*4，等价于 sizeof(a[1])
//	printf("%d\n", sizeof(&a[0] + 1));	
//	//4  这里指第二行的地址，&a[0]取出的是二维数组第一行的地址，加一就是第二行的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));
//	//16 第二行数组的大小
//	printf("%d\n", sizeof(*a));			
//	//16 a是（首元素地址）第一行的地址，解引用就是第一行这个一维数组的大小 
//	printf("%d\n", sizeof(a[3]));		
//	//16 sizeof()不会访问括号内的内容，a[3]不会真的访问第四行
//	return 0;
//}
////以上是关于sizeof(),strlen()的相关计算

//面试笔试有两次
// 1.线上笔试（较难）
// 2.线下笔试（打印的卷子，一般都是阅读程序写结果）
//指针相关的笔试题
//// 例1：
//
//
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	// 2,5 
//	// &a是取出整个数组的地址，&a+1跳过整个数组的地址，将它强制转换成整形指针，赋给ptr，
//	//所以ptr-1就是向前挪动了一个整形，解引用就是5
//	//*(a+1)这里的a是首元素地址，加一就是第二个元素的地址，解引用就是第二个元素
//	return 0;
//}

//例二：假设p的值为0x100000，如下表表达式的值分别是多少？已知结构体Test类型的变量大小是20个字节

// 指针+整数，取决于指针类型
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}* p;
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);      
	// p是一个结构体指针类型，结构体指针加一跳过一个结构体，大小已知是20，所以加一就跳过20，
	// 在十六进制中20=14=16+4，所以就是0x00100014(十进制打印，要写全，十六进制打印就是0x100014)
	printf("%p\n", (unsigned long)p + 0x1);
	//0x100000十六进制转换为十进制为1048576，1048576+1=1048577，再将1048577转换成十六进制就是0x100001
	//unsigned long是把p转换成一个整形类型，加一就是相当于在十进制数上加一
	printf("%p\n", (unsigned int*)p + 0x1);
	//unsigned int*是一个无符号的整形指针（占4个字节），加一就相当于跳过一个无符号的整形指针,0x00100004
	return 0;
}
