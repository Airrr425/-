#include <iostream>
using namespace std;

const int initcap = 5;		//顺序表的初始容量（5）
template <typename T>
class SqList			//顺序表类模板
{
public:
	T* data;			//存放顺序表元素空间的指针
	int capacity;			//顺序表的容量 
	int length;   			//存放顺序表的长度

	//线性表的基本运算算法
	void recap(int newcap)		//改变顺序表的容量为newcap
	{
		if (newcap <= 0) return;
		T* olddata = data;
		data = new T[newcap];		//分配新空间
		capacity = newcap;		//更新容量
		if (capacity < length) length = capacity;
		for (int i = 0; i < length; i++)	//元素复制
			data[i] = olddata[i];
		delete[] olddata;		//释放原空间
	}
	void CreateList(T a[], int n)	//由数组a中元素整体建立顺序表
	{
		if (capacity < n)		//容量小于n时
			recap(n);			//扩大容量
		for (int i = 0; i < n; i++)
		{
			data[length] = a[i];
			length++;			//添加后元素个数增加1
		}
	}
	SqList()				//构造函数
	{
		data = new T[initcap];		//为data分配初始容量大小的空间
		capacity = initcap;		//初始化容量
		length = 0;			//初始时置length为0
	}
	SqList(const SqList<T>& s)	//初始化复制构造函数
	{
		capacity = s.capacity;		//复制容量
		length = s.length;		//复制长度
		data = new T[capacity];		//为当前顺序表分配空间
		if (capacity < length) length = capacity;
		for (int i = 0; i < length; i++)	//元素复制
			data[i] = s.data[i];
	}
	~SqList()		//析构函数
	{
		delete[] data;	//释放data指向的空间
	}
	void Add(T e)			//在线性表的末尾添加一个元素e
	{
		if (length == capacity)		//顺序表空间满时倍增容量
			recap(2 * length);
		data[length] = e;		//添加元素e
		length++;			//长度增1
	}
	int Getlength()		//求顺序表的长度 
	{
		return length;
	}
	bool GetElem(int i, T& e)	//求序号i的元素值
	{
		if (i < 0 || i >= length)
			return false;		//参数错误时返回false
		e = data[i];			//取元素值
		return true;			//成功找到元素时返回true
	}
	bool SetElem(int i, T e)		//设置序号i的元素值
	{
		if (i <= 0 || i >= length)	//参数错误时返回false
			return false;
		data[i] = e;
		return true;
	}
	int GetNo(T e)			//查找第一个为e的元素的序号
	{
		int i = 0;
		while (i < length&& data[i] != e)
			i++;			//查找元素e
		if (i >= length)		//未找到时返回-1
			return -1;
		else
			return i;			//找到后返回其序号
	}
	bool Insert(int i, T e)		//在线性表中序号i位置插入元素e
	{
		if (i<0 || i>length)		//参数i错误返回false
			return false;
		if (length == capacity)		//满时倍增容量
			recap(2 * length);
		for (int j = length; j > i; j--)	//将data[i]及后面元素后移一个位置
			data[j] = data[j - 1];
		data[i] = e;			//插入元素e
		length++;			//长度增1
		return true;
	}
	bool Delete(int i) 		//在线性表中删除序号i的元素
	{
		if (i < 0 || i >= length)		//参数i错误返回false
			return false;
		for (int j = i; j < length - 1; j++)
			data[j] = data[j + 1];		//将data[i]之后的元素前移一个位置
		length--; 			//长度减1
		if (capacity > initcap && length <= capacity / 4)
			recap(capacity / 2);		//满足缩容条件则容量减半
		return true;
	}
	void DispList()			//输出顺序表L中所有元素
	{
		for (int i = 0; i < length; i++)	//遍历顺序表中各元素值
			cout << data[i] << " ";
		cout << endl;
	}
};

template <typename T>
void Reverse(SqList<T>& L)
{
	T r = L.data[0];
	int i = 0, j = L.length - 1;
	while (i < j)
	{
		r = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = r;
		i++;
		j--;
	}
}

int main() {
	int a[] = { 555, 913, 315 };
	SqList<int> L;
	L.CreateList(a, 3);
	L.DispList();
	Reverse(L);
	L.DispList();

	return 0;
}