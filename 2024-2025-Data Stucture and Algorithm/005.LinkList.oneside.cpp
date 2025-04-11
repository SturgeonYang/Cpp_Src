#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    struct Node<T>* next;
};

template<typename T>
class LinkList {
private:
    Node<T>* front;
public:
    LinkList() {
        front = new Node<T>;
        front->next = NULL;
    }
    LinkList(T a[], int n);
    ~LinkList();
    void PrintList();
    int GetLength();
    Node<T>* Get(int i);
    int Locate(T x);
    void Insert(int i, T x);
    T Delete(int i);
    void deleteDuplicates();
};

template<typename T>
LinkList<T>::LinkList(T a[], int n) {
    front = new Node<T>;
    front->next = NULL;
    Node<T>* r = front;
    for (int i = 0; i < n; i++) {
        Node<T>* s = new Node<T>;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

template<typename T>
LinkList<T>::~LinkList() {
    Node<T>* p = front;
    while (p) {
        front = p;
        p = p->next;
        delete front;
    }
}

template<typename T>
void LinkList<T>::PrintList() {
    Node<T>* p = front->next; // Skip the head node
    if (!p) {//If p == 0, !p == true
        cout << "empty" << endl;
        return;
    }else{
        cout << p->data;
        p = p->next;
        while (p) {
            cout << ' ' << p -> data;
            p = p->next;
            }
        }
        cout << endl;
    }

template<typename T>
int LinkList<T>::GetLength() {
    Node<T>* p = front->next; // Skip the head node
    int n = 0;
    while (p) {
        p = p->next;
        n++;
    }
    return n;// the length of a linklist does not contain the head node
}

template<typename T>
Node<T>* LinkList<T>::Get(int i) {
    Node<T>* p = front;
    for (int j = 0; j <= i; j++) {
        p = p->next;
    }
    return p;
}

template<typename T>
int LinkList<T>::Locate(T x) {
    Node<T>* p = front->next; // Skip the head node
    int n = 0;
    while (p) {
        if (p->data == x) {
            return n;
        }
        p = p->next;
        n++;
    }
    cout << "not found." << endl;
    return -1;
}

template<typename T>
void LinkList<T>::Insert(int i, T x) {
    Node<T>* p = front;
    if (i != 0) {
        p = Get(i - 1);
    }
    if (p) {
        Node<T>* s = new Node<T>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    } else {
        throw "position error.";
    }
}

template<typename T>
T LinkList<T>::Delete(int i) {
    Node<T>* p = front;
    if (i != 0) {
        p = Get(i - 1);
    }
    Node<T>* q = p->next;
    p->next = q->next;
    T x = q->data;
    delete q;
    return x;
}

template<typename T>
void LinkList<T>::deleteDuplicates() {
    Node<T>* p = front->next; // Skip the head node
    Node<T>* prev = front;// save previous node
    while (p && p->next) {
        if (p->data == p->next->data) {
            T value = p->data;
            while (p && p->data == value) {
                Node<T>* temp = p;//save the data to be deleted
                p = p->next;
                delete temp;
            }
            prev->next = p;
        } else {
            prev = p;
            p = p->next;
        }
    }
}
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "empty" << endl;
        return 0;
    }
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    LinkList<int> L(arr, n);
    L.deleteDuplicates();
    L.PrintList();
    delete[] arr;
    return 0;
}