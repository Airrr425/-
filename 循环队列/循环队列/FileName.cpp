#include <iostream>
using namespace std;
template <class T>
class Queue {
private:
    T* data;   // 存放队列元素的数组
    int front; // 队头指针
    int rear;  // 队尾指针
    int maxSize; // 队列最大容量
    bool tag;  // 表示队列可能空（false）或可能满（true）
public:
    Queue(int size) {
        maxSize = size;
        data = new T[maxSize];
        front = rear = 0;
        tag = false;
    }
    ~Queue() {
        delete[] data;
    }
    bool push( T element) {    
        if (isFull()) {
            cout << "队列已满，无法插入元素" << endl;
            return false;
        }
        data[rear] = element;
        rear = (rear + 1) % maxSize;
        if (front == rear) {
            tag = true;
        }
        return true;
    }
    bool pop( T& element) {
        if (isEmpty()) {
            cout << "队列为空，无法删除元素" << endl;
            return false;
        }
        element = data[front];
        front = (front + 1) % maxSize;
        tag = false;
        return true;
    }
    bool isEmpty() {
        return (front == rear) && !tag;
    }
    bool isFull() {
        return (front == rear) && tag;
    }
    bool gethead( T& element) {
        if (front == rear)
            return false;
        int head = (front + 1) % maxSize;
        element = data[head];
        return true;
    }
};
int main() {
    Queue<int> q(5);
    cout << "队列是否为空：" << (q.isEmpty() ? "是" : "否") << endl;
    cout << "队列是否已满：" << (q.isFull() ? "是" : "否") << endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "队列是否为空：" << (q.isEmpty() ? "是" : "否") << endl;
    cout << "队列是否已满：" << (q.isFull() ? "是" : "否") << endl;

    cout << "队列元素依次出队：";
    static int i = 1;
    while (!q.isEmpty()) {
        q.pop(i);
        cout << i << " ";
        i++;
    }
    cout << endl;

    return 0;
}