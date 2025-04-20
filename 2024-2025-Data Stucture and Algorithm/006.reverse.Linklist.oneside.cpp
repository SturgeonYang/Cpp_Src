// 题目描述
// 给定一个常数K和一个单链表L，要求按每K个节点反转单链表L。例如，给定L为1->2->3->4->5->6，如果K=3，应输出3->2->1->6->5->4，如果K=4，应输出4->3->2->1->5->6。

// 输入
// 每次输入一个案例，对于每一个案例：

// 第一行包含三个值：第一个节点的地址、节点总数N(<=10^5，正整数)、需要反转的子链表的长度K(<=N， 正整数)。

// 节点的地址是一个5位的非负整数，NULL用-1来代替。

// 下面接着输入N行，一行表示一个节点，格式为Address Data Next。其中Address为该节点的地址，Data为该节点的数据，Next为下一个节点的地址。

// ！！！注意：Address和Next字段都不是节点的真实存储地址，只是用来做示例，用于标识头节点和下一个节点是哪一个，真实的地址仍需要new出来后由计算机分配，不能直接向示例中的地址里写数据。

// 输出
// 对于每一个输入案例，输出反序后的单链表。其中每一个节点占一行，格式与输入一致。

// 样例输入
// 00100 6 4
// 00000 4 99999
// 00100 1 12309
// 68237 6 -1
// 33218 3 00000
// 99999 5 68237
// 12309 2 33218
// 样例输出
// 00000 4 33218
// 33218 3 12309
// 12309 2 00100
// 00100 1 99999
// 99999 5 68237
// 68237 6 -1
// 提示
//注意：可能会有一些节点不在该单链表上，所以反序和输出的结果都不应包含这些节点。
#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
struct Node {
    int address;
    T data;
    int next;
    struct Node<T>* nextNode;
};

template <class T>
class LinkList {
private:
    Node<T>* head;
public:
    LinkList() : head(NULL) {}
    LinkList(int headAddress, int N, Node<T>* nodes) : head(NULL) {
        //初始化addressMap
        Node<T>* addressMap[200000] = {nullptr};

        //输入节点部分
        for (int i = 0; i < N; i++) {
            cin >> nodes[i].address >> nodes[i].data >> nodes[i].next;
            addressMap[nodes[i].address] = &nodes[i];
        }

        //整理顺序，排除出不在链表上的节点
        Node<T>* tail = NULL;
        int currentAddress = headAddress;
        while (currentAddress != -1) {
            Node<T>* currentNode = addressMap[currentAddress];
            if (currentNode == NULL) {
                break;//如果链表为空，直接结束；如果已经是最后一个结点，也直接结束while
            }
            if (head == NULL) {
                head = currentNode;//头部对齐
                tail = currentNode;
            } else {
                tail->nextNode = currentNode;
                tail = currentNode;
            }
            currentAddress = currentNode->next;
        }
        if (tail != NULL) {
            tail->nextNode = NULL;//此处照应下面输出时最后一项对p->nextNode == NULL的判断
        }
    }
    void reverse(int K);
    void print();

};

template <class T>
void LinkList<T>::reverse(int K) {
    if (head == NULL || K <= 1) {
        return; // 如果链表为空或 K <= 1，直接返回
    }
    Node<T>* dummy = new Node<T>{-1, 0, -1, head}; // 哑节点
    Node<T>* prevGroupEnd = dummy;

    while (true) {
        Node<T>* groupStart = prevGroupEnd->nextNode;
        Node<T>* groupEnd = prevGroupEnd;

        // 找到当前组的末尾节点
        for (int i = 0; i < K && groupEnd != NULL; i++) {
            groupEnd = groupEnd->nextNode;
        }

        if (groupEnd == NULL) {
            break; // 剩余节点不足 K 个，退出循环
        }

        Node<T>* nextGroupStart = groupEnd->nextNode;

        // 反转当前组
        Node<T>* prev = NULL;
        Node<T>* curr = groupStart;
        while (curr != nextGroupStart) {
            Node<T>* temp = curr->nextNode;
            curr->nextNode = prev;
            prev = curr;
            curr = temp;
        }

        // 连接反转后的组
        prevGroupEnd->nextNode = groupEnd;
        groupStart->nextNode = nextGroupStart; // 确保连接到下一组的第一个节点

        // 更新 prevGroupEnd 为当前组的末尾节点
        prevGroupEnd = groupStart;

        // 如果剩余节点不足 K 个，退出循环
        if (nextGroupStart == NULL) {
            break;
        }
    }

    head = dummy->nextNode;
    delete dummy;
}
template <class T>
void LinkList<T>::print() {
    //输出
    Node<T>* p = head;//定义工作节点
    while (p != NULL)
    {
        cout << setw(5) << setfill('0') << p->address << ' ' << p-> data << ' ';
        if (p->nextNode == NULL) {
            cout << -1;
        } else {
            cout << setw(5) << setfill('0') << p->nextNode->address;
        }
        cout << endl;
        p = p->nextNode;//最后p为NULL
    }
}
int main() {
    int headAddress, N, K;
    cin >> headAddress >> N >> K;//第一行输入
    Node<int>* nodes = new Node<int>[N];
    for (int i = 0; i < N; i++) {
        nodes[i].nextNode = NULL; // 初始化指针
    }
    LinkList<int> list(headAddress, N, nodes);
    list.reverse(K); // 调用反转函数
    list.print();    // 调用打印函数
    delete[] nodes; // 释放动态分配的节点数组
    return 0;
}