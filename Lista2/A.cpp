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

            if(head = tail)
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

};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    int Q, T, F;
    char C;

    cin >> S;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        cin >> T;

        if(T == 1)
            reverse(S.begin(), S.end());
        else if(T == 2) {
            cin >> F;
            cin >> C;

            if(F == 1)
                S = C + S;
            else if(F == 2)
                S = S + C;
        }
    }

    cout << S;

    return 0;
}