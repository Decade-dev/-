#include <iostream>

using namespace std;
//链表结点类定义
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() {
        next = NULL;
    }
};

//带头结点的单链表类定义
class LinkList {
public:
    ListNode* head;
    int len;

    //操作定义
    LinkList() {
        head = new ListNode();
        len = 0;
    }

    //链表回收，要逐个结点回收
    ~LinkList() {
        ListNode* p, * q;
        p = head;
        while (p != NULL) {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }

    //返回第i个结点的指针，如果不存在返回NULL
    ListNode* LL_index(int i) {
        if (i < 0 || i > len)
            return NULL;

        int k = 0;
        ListNode* p = head;
        while (p && k < i) {
            p = p->next;
            k++;
        }
        return p;
    }

    //获取第i个元素的数据
    int LL_get(int i) {
        ListNode* p = LL_index(i);
        return p->data;
    }

    //把数值item插入第i个位置
    int LL_insert(int i, int item) {
        if (i <= 0 || i > len + 1)
            return -1;


        ListNode* p = LL_index(i - 1);

        ListNode* newNode = new ListNode();

        newNode->data = item;
        newNode->next = p->next;
        p->next = newNode;

        len++;


        return 1;
    }

    //删除第i个结点
    int LL_del(int i) {
        if (i <= 0 || i > len)
            return -1;

        ListNode* p = LL_index(i - 1);
        ListNode* q = p->next;
        p->next = q->next;
        delete q;

        return 1;

    }

    //输出单链表的内容
    void LL_display() {
        ListNode* p;
        p = head->next;
        cout << len << ": ";
        while (p->next) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << endl;
        //cout << endl;
    }

    void deleteSame() {
        ListNode* p = head->next;
        ListNode* q = p->next;
        while (p) {
            while (q) {
                //cout << "2" << endl;
                if (q->data == p->data) {
                    //cout << "3" << endl;
                    ListNode* temp = head->next;
                    while (temp->next != q)
                        temp = temp->next;
                    temp->next = q->next;
                    delete q;
                    len--;
                    q = temp->next;
                }
                else
                    q = q->next;
            }
            p = p->next;
            if (p)
                q = p->next;
            else
                break;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        LinkList list;
        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            list.LL_insert(i + 1, data);
        }
        list.deleteSame();
        list.LL_display();
    }

    return 0;

}