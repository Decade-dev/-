#include <iostream>

using namespace std;
//�������ඨ��
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() {
        next = NULL;
    }
};

//��ͷ���ĵ������ඨ��
class LinkList {
public:
    ListNode* head;
    int len;

    //��������
    LinkList() {
        head = new ListNode();
        len = 0;
    }

    //������գ�Ҫ���������
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

    //���ص�i������ָ�룬��������ڷ���NULL
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

    //��ȡ��i��Ԫ�ص�����
    int LL_get(int i) {
        ListNode* p = LL_index(i);
        return p->data;
    }

    //����ֵitem�����i��λ��
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

    //ɾ����i�����
    int LL_del(int i) {
        if (i <= 0 || i > len)
            return -1;

        ListNode* p = LL_index(i - 1);
        ListNode* q = p->next;
        p->next = q->next;
        delete q;

        return 1;

    }

    //��������������
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