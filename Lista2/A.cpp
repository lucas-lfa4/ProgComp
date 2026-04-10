#include <bits/stdc++.h>

using namespace std;

class List {
    private:
        typedef struct Link{
            char letra;
            struct Link* next;
        } Link;

        Link* head;
        Link* tail;
        Link* curr;
        int qnt;
    
    public:
        List() {
            head = new Link;
            assert(head);

            head->letra = ' ';
            head->next = NULL;

            curr = head;
            tail = head;

            qnt = 0;
        }
        ~List() {
            moveToStart();

            Link* tmp;

            while(curr != NULL) {
                tmp = curr->next;
                delete curr;
                curr = tmp;
            }
            delete curr;
        }
        int size() {
            return qnt;
        }
        void next() {
            if(curr != tail) {
                curr = curr->next;
            }
        }
        void moveToStart() {
            curr = head;
        }
        void reverse() {
            Link* tmp = head;
            head = tail;
            tail = head;
        }
        void append(char it) {
            Link* novo = new Link;

            novo->next = head->next;
            head->next = novo;
            novo->letra = it;
            qnt++;

            if(head == tail)
                tail = head->next;
        }
        void push_back(char it) {
            Link* novo = new Link;

            novo->next = NULL;
            tail->next = novo;
            novo->letra = it;
            qnt++;
            tail = novo;
        }
        void print() {
            moveToStart();

            while(curr->next != NULL) {
                cout << curr->next->letra;
                next();
            }
        }
        void print_invertido() {
            string cadeia(qnt, ' ');
            int i = 0;
            moveToStart();

            while(curr->next != NULL) {
                cadeia[i] = curr->next->letra;
                next();
                i++;
            }
            std::reverse(cadeia.begin(), cadeia.end());
            cout << cadeia;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    int Q, T, F;
    char C;
    bool invertida = false;

    cin >> S;
    List str;
    for(auto it = S.begin(); it != S.end(); it++)
        str.push_back(*it);
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        cin >> T;

        if(T == 1)
            invertida = !invertida;
        else if(T == 2) {
            cin >> F;
            cin >> C;

            if(F == 1) {
                if(invertida) {
                    str.push_back(C);
                }
                else {
                    str.append(C);
                }
            }
            else if(F == 2) {
                if(invertida) {
                    str.append(C);
                }
                else {
                    str.push_back(C);
                }
            }
        }
    }

    if(invertida) 
        str.print_invertido();
    else
        str.print();

    return 0;
}