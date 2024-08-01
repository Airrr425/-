#include <iostream>
using namespace std;

const int initcap = 5;		//˳���ĳ�ʼ������5��
template <typename T>
class SqList			//˳�����ģ��
{
public:
	T* data;			//���˳���Ԫ�ؿռ��ָ��
	int capacity;			//˳�������� 
	int length;   			//���˳���ĳ���

	//���Ա�Ļ��������㷨
	void recap(int newcap)		//�ı�˳��������Ϊnewcap
	{
		if (newcap <= 0) return;
		T* olddata = data;
		data = new T[newcap];		//�����¿ռ�
		capacity = newcap;		//��������
		if (capacity < length) length = capacity;
		for (int i = 0; i < length; i++)	//Ԫ�ظ���
			data[i] = olddata[i];
		delete[] olddata;		//�ͷ�ԭ�ռ�
	}
	void CreateList(T a[], int n)	//������a��Ԫ�����彨��˳���
	{
		if (capacity < n)		//����С��nʱ
			recap(n);			//��������
		for (int i = 0; i < n; i++)
		{
			data[length] = a[i];
			length++;			//��Ӻ�Ԫ�ظ�������1
		}
	}
	SqList()				//���캯��
	{
		data = new T[initcap];		//Ϊdata�����ʼ������С�Ŀռ�
		capacity = initcap;		//��ʼ������
		length = 0;			//��ʼʱ��lengthΪ0
	}
	SqList(const SqList<T>& s)	//��ʼ�����ƹ��캯��
	{
		capacity = s.capacity;		//��������
		length = s.length;		//���Ƴ���
		data = new T[capacity];		//Ϊ��ǰ˳������ռ�
		if (capacity < length) length = capacity;
		for (int i = 0; i < length; i++)	//Ԫ�ظ���
			data[i] = s.data[i];
	}
	~SqList()		//��������
	{
		delete[] data;	//�ͷ�dataָ��Ŀռ�
	}
	void Add(T e)			//�����Ա��ĩβ���һ��Ԫ��e
	{
		if (length == capacity)		//˳���ռ���ʱ��������
			recap(2 * length);
		data[length] = e;		//���Ԫ��e
		length++;			//������1
	}
	int Getlength()		//��˳���ĳ��� 
	{
		return length;
	}
	bool GetElem(int i, T& e)	//�����i��Ԫ��ֵ
	{
		if (i < 0 || i >= length)
			return false;		//��������ʱ����false
		e = data[i];			//ȡԪ��ֵ
		return true;			//�ɹ��ҵ�Ԫ��ʱ����true
	}
	bool SetElem(int i, T e)		//�������i��Ԫ��ֵ
	{
		if (i <= 0 || i >= length)	//��������ʱ����false
			return false;
		data[i] = e;
		return true;
	}
	int GetNo(T e)			//���ҵ�һ��Ϊe��Ԫ�ص����
	{
		int i = 0;
		while (i < length&& data[i] != e)
			i++;			//����Ԫ��e
		if (i >= length)		//δ�ҵ�ʱ����-1
			return -1;
		else
			return i;			//�ҵ��󷵻������
	}
	bool Insert(int i, T e)		//�����Ա������iλ�ò���Ԫ��e
	{
		if (i<0 || i>length)		//����i���󷵻�false
			return false;
		if (length == capacity)		//��ʱ��������
			recap(2 * length);
		for (int j = length; j > i; j--)	//��data[i]������Ԫ�غ���һ��λ��
			data[j] = data[j - 1];
		data[i] = e;			//����Ԫ��e
		length++;			//������1
		return true;
	}
	bool Delete(int i) 		//�����Ա���ɾ�����i��Ԫ��
	{
		if (i < 0 || i >= length)		//����i���󷵻�false
			return false;
		for (int j = i; j < length - 1; j++)
			data[j] = data[j + 1];		//��data[i]֮���Ԫ��ǰ��һ��λ��
		length--; 			//���ȼ�1
		if (capacity > initcap && length <= capacity / 4)
			recap(capacity / 2);		//����������������������
		return true;
	}
	void DispList()			//���˳���L������Ԫ��
	{
		for (int i = 0; i < length; i++)	//����˳����и�Ԫ��ֵ
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