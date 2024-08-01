#include <iostream>
using namespace std;
template <class T>
class Queue {
private:
    T* data;   // ��Ŷ���Ԫ�ص�����
    int front; // ��ͷָ��
    int rear;  // ��βָ��
    int maxSize; // �����������
    bool tag;  // ��ʾ���п��ܿգ�false�����������true��
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
            cout << "�����������޷�����Ԫ��" << endl;
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
            cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
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
    cout << "�����Ƿ�Ϊ�գ�" << (q.isEmpty() ? "��" : "��") << endl;
    cout << "�����Ƿ�������" << (q.isFull() ? "��" : "��") << endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "�����Ƿ�Ϊ�գ�" << (q.isEmpty() ? "��" : "��") << endl;
    cout << "�����Ƿ�������" << (q.isFull() ? "��" : "��") << endl;

    cout << "����Ԫ�����γ��ӣ�";
    static int i = 1;
    while (!q.isEmpty()) {
        q.pop(i);
        cout << i << " ";
        i++;
    }
    cout << endl;

    return 0;
}