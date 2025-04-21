#include <iostream>
#include <stdexcept> // 添加此头文件以支持 runtime_error
using namespace std;

// 定义节点结构
struct Node {
    int data;
    Node* next;
};

// 定义队列类
class CircularQueue {
private:
    Node* rear; // 指向队尾节点
    int length; // 队列长度

public:
    // 构造函数
    CircularQueue() {
        rear = new Node{0, nullptr}; // 创建头结点
        rear->next = rear;           // 初始化为循环链表
        length = 0;
    }

    // 析构函数
    ~CircularQueue() {
        while (length > 0) {
            dequeue(); // 释放所有节点
        }
    }

    // 入队操作
    void enqueue(int value) {
        Node* newNode = new Node{value, rear->next}; // 新节点指向头结点
        rear->next = newNode;                        // 队尾节点指向新节点
        rear = newNode;                              // 更新队尾节点
        length++;
    }

    // 出队操作
    int dequeue() {
        if (length == 0) {
            throw runtime_error("Queue is empty");
        }

        Node* front = rear->next->next; // 队头节点
        int value = front->data;

        if (length == 1) { // 如果队列中只有一个元素
            rear->next = rear; // 重置队列为初始状态
        } else {
            rear->next->next = front->next; // 跳过队头节点
        }

        delete front; // 删除队头节点
        length--;
        return value;
    }

    // 获取队头元素
    int getFront() {
        if (length == 0) {
            throw runtime_error("Queue is empty");
        }
        return rear->next->next->data; // 队头节点的数据
    }

    // 获取队列长度
    int getLength() {
        return length;
    }

    // 置空队列
    void clear() {
        while (length > 0) {
            dequeue();
        }
    }
};

int main() {
    int n;
    cin >> n; // 输入队列长度
    CircularQueue queue;

    // 入队操作
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        queue.enqueue(value);
    }

    // 输出队列长度
    cout << queue.getLength() << " ";

    // 输出队头元素
    cout << queue.getFront() << " ";

    // 出队操作
    cout << queue.dequeue() << " ";

    // 再次输出队列长度
    cout << queue.getLength() << endl;

    return 0;
}