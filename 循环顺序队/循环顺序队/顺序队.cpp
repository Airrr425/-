#include<iostream>
using namespace std;
const int MaxSize = 100;
class CSqQueue
{
private:
	int queue[MaxSize];//����һ�������͵�˳���
	int rear;
	int size;
public:
	CSqQueue() {
		rear = 0;
		size = 0;
	}
	~CSqQueue() {
	}
	int pop() {                  //�����ͷָ��λ��,�����ض�ͷָ����ָԪ��
		if (size == 0)
		{
			return -1;
		}
		int front_index = (rear - size + 1 + MaxSize) % MaxSize;
		size--;
		return queue[front_index];
	}
	void push(int element) {      //��Ӳ���
		if (size == MaxSize)
		{
			return;
		}
		rear = (rear + 1) % MaxSize;
		queue[rear] = element;
		size++;
	}
	bool empty() {
		return ((rear - size + 1 + MaxSize) % MaxSize == rear);
	}
};
int main() {
	CSqQueue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	queue.push(6);
	while (!queue.empty()) {
		cout << queue.pop() << " ";
	}
	return 0;
}