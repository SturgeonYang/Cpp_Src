// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     struct Node* next;
// };
// class LinkedList {
//     private:
//     Node* front;
//     Node* rear;
//     int length;

//     public:
//     LinkedList() {
//         front = NULL;
//     }
//     LinkedList(int n) {
//         Node* circle = new Node[n];
//         for (int i = 0; i < n; i++) {
//             circle[i].data = i + 1;
//             if (i != n-1) {
//                 circle[i].next = &circle[i+1];
//             } else {
//                 circle[i].next = front;
//             }
//         }
//         circle[n-1].next = &circle[0];
//         front = circle;
//         length = n;
//         rear->next = front;
//     }
//     ~LinkedList() {
//         Node* p = front;
//         while (p != NULL) {
//             Node* temp = p;
//             p = p->next;
//             delete temp;
//         }
//     }
//     int loop(int k) {
//         Node* p = front;
//         int count = 1;
//         while (true) {

//             for (int i = 0; i < k; i++) {
//                 for (int j = 0; j < length; j++)
//                 {
//             //         Node* q = front;
//             //         if (j != length-1) {
//             //             cout << q->data << ' ';
//             //         } else {
//             //             cout << q->data << endl;
//             //         }
//             //         q = q->next;
//             //     }

//                     if (i == k-1) {
//                         if (length != 1) {
//                             Node* temp = p->next;
//                             cout << Delete(count) << ' ';
//                             p = temp;
//                         } else {
//                             cout << Delete(count);
//                             break;
//                         }
//                         length--;
//                     }
//                     if (count == length) {
//                         count = 1;
//                         p = front;
//                     } else {
//                         p = p->next;
//                         count++;
//                     }
//                 }
//             }
//         }
//     }
//     int Delete(int x) {
//         Node* p = front;
//         if (x != 1) {
//             p = get(x - 1);
//             Node* q = p->next;
//             p->next = q->next;
//             int num = q->data;
//             delete q;
//             return num;
//         } else {
//             front = front->next;
//             rear->next = front;
//             int num = p->data;
//             delete p;
//             return num;
//         }
//     }
//     Node* get(int i) {
//         Node* p = front;
//         int j =1;
//         while (p && j != i) {
//             p = p->next;
//             j++;
//         }
//         return p;
//     }
// }; 

// int main() {
//     int n,k;
//     cin >> n >> k;
//     LinkedList josephus(n);
//     josephus.loop(k);
//     return 0;
// }

// #include<iostream>
// using namespace std;
// typedef struct node
// {
// 	int data;
// 	struct node* next;
// }Node;
// int n, k;
// void josephus(int n, int k)
// {
// 	//开始创建循环链表
// 	Node* head = NULL, * p = NULL, * r = NULL;
// 	head = new Node;
// 	head->data = 1;
// 	head->next = NULL;
// 	p = head;
// 	for (int i = 2; i <= n; i++)
// 	{
// 		Node* r = new Node;
// 		r->data = i;
// 		r->next = NULL;
// 		p->next = r;
// 		p = r;
// 	}
// 	p->next = head;//首尾相接
// 	p = head;//恢复初始状态
// 	while (p->next != p)//结束条件是只剩下最后一个（当然用cnt计数也可以）
// 	{
// 		for (int i = 1; i < k; i++)
// 		{
// 			r = p;//用r保存该删结点的上一个结点
// 			p = p->next;
// 		}
// 		//循环结束后p指针的位置是该删结点的位置
// 		cout << p->data << " ";
// 		r->next = p->next;
// 		p = p->next;
// 	}
// 	//whlie循环结束后还剩最后一个结点要输出
// 	cout << p->data;
// }
// int main()
// {
// 	cin >> n >> k;
// 	josephus(n,k);
// 	return 0;
// }


#include <iostream>
using namespace std;

// 定义节点结构
struct Node {
    int data;
    Node* next;
};

// Josephus 环问题解决函数
void josephus(int n, int k) {
    // 创建循环链表
    Node* head = new Node{1, nullptr};
    Node* p = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node{i, nullptr};
        p->next = newNode;
        p = newNode;
    }
    p->next = head; // 首尾相接，形成循环链表

    // 开始解决 Josephus 环问题
    Node* prev = p; // 指向尾节点
    p = head;       // 指向头节点

    while (p->next != p) { // 当链表中还有多个节点时
        // 找到第 k 个节点
        for (int i = 1; i < k; i++) {
            prev = p;
            p = p->next;
        }

        // 输出当前节点的值
        cout << p->data << " ";

        // 删除当前节点
        prev->next = p->next;
        delete p;
        p = prev->next; // 移动到下一个节点
    }

    // 输出最后一个节点的值
    cout << p->data << endl;
    delete p; // 删除最后一个节点
}

int main() {
    int n, k;
    cin >> n >> k; // 输入 n 和 k
    josephus(n, k); // 调用 Josephus 环问题解决函数
    return 0;
}