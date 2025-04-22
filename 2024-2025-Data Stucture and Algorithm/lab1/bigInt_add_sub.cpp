#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 链表节点结构
struct Node {
    int data;       // 存储一位数字
    Node* next;     // 指向下一个节点
    Node(int val) : data(val), next(nullptr) {}
};

// 随机生成一个1~50位的大整数，并存储到链表中
Node* generateRandomBigInt(int length) {
    if (length <= 0 || length > 50) {
        throw invalid_argument("长度必须在1到50之间");
    }

    Node* head = new Node(rand() % 9 + 1); // 确保第一位不是0
    Node* current = head;

    for (int i = 1; i < length; i++) {
        current->next = new Node(rand() % 10);
        current = current->next;
    }

    return head;
}

// 打印链表表示的大整数
void printBigInt(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;
}

// 释放链表内存
void freeBigInt(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// 链表反转（用于加减法操作）
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

// 大整数加法
Node* addBigInts(Node* num1, Node* num2) {
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    Node* result = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (num1 || num2 || carry) {
        int digit1 = (num1) ? num1->data : 0;
        int digit2 = (num2) ? num2->data : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        Node* newNode = new Node(sum % 10);
        if (!result) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    return reverseList(result);
}

// 大整数减法（假设num1 >= num2）
Node* subtractBigInts(Node* num1, Node* num2) {
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    Node* result = nullptr;
    Node* tail = nullptr;
    int borrow = 0;

    while (num1 || num2) {
        int digit1 = (num1) ? num1->data : 0;
        int digit2 = (num2) ? num2->data : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        Node* newNode = new Node(diff);
        if (!result) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    // 去掉前导零
    result = reverseList(result);
    while (result && result->data == 0 && result->next) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return result;
}

int main() {
    srand(time(0));

    try {
        // 随机生成两个大整数
        int length1 = rand() % 50 + 1;
        int length2 = rand() % 50 + 1;

        Node* num1 = generateRandomBigInt(length1);
        Node* num2 = generateRandomBigInt(length2);

        // 打印生成的两个大整数
        cout << "Number 1: ";
        printBigInt(num1);
        cout << "Number 2: ";
        printBigInt(num2);

        // 选择加法或减法操作
        char operation;
        cout << "输入想要的运算符 (+ 或 -): ";
        cin >> operation;

        if (operation == '+') {
            // 执行加法
            Node* sum = addBigInts(num1, num2);
            cout << "和: ";
            printBigInt(sum);
            freeBigInt(sum);
        } else if (operation == '-') {
            // 确保num1 >= num2
            Node* temp1 = num1;
            Node* temp2 = num2;
            bool swapped = false;

            while (temp1 && temp2) {
                if (temp1->data < temp2->data) {
                    swap(num1, num2);
                    swapped = true;
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            if (swapped) {
                cout << "Number1 小于 Number2, 将两数调换顺序后相减." << endl;
            }

            // 执行减法
            Node* diff = subtractBigInts(num1, num2);
            cout << "差: ";
            printBigInt(diff);
            freeBigInt(diff);
        } else {
            cout << "无效运算" << endl;
        }

        // 释放内存
        freeBigInt(num1);
        freeBigInt(num2);
    } catch (const exception& e) {
        cout << "发生异常: " << e.what() << endl;
    }

    return 0;
}