
#include <bits/stdc++.h>
using namespace std;
#define MAX_TYPE int(1e+9)
#define MAX_N int(1e+5)+1
int N, Q;
int _type[MAX_N];
typedef struct node {
    int _end;
    int _type;
    node *_next;
} NODE;
NODE* head;
int node_count;
void _merge(NODE* a, NODE* b)
{
    while(b != NULL && b->_type == a->_type) {
        //cout << "MERGE " << a->_end << " with " << b->_end << "\n";
        a->_end = b->_end;
        a->_next = b->_next;
        delete b;
        b = a->_next;
        node_count--;
    }
}
void addNode(NODE* prev, int en, int type)
{
    NODE* newnode = new NODE;
    newnode->_type = type;
    newnode->_end = en;
    if(prev != NULL){
        newnode->_next = prev->_next;
        prev->_next = newnode;
    }
    else{
        newnode->_next = (head != NULL ? head->_next : NULL);
        head = newnode;
    }
    node_count++;
}
void _split(NODE* a, int start_a, int pos, int type, NODE* prev_a)
{
    if(pos == a->_end && pos == start_a) {
        //cout << "SINGLE NODE\n";
        a->_type = type;
        if(type == prev_a->_type){
            //cout << " and EQUAL PREV TYPE\n";
            _merge(prev_a, a);
        }
        else if(a->_next != NULL && type == a->_next->_type)
        {
            //cout << " and EQUAL NEXT TYPE\n";
            _merge(a, a->_next);
        }
    } else if(pos == a->_end) {
        //cout << "CHANGE AT END";
        (a->_end)--;
        if(a->_next != NULL && a->_next->_type == type) {
             //cout << " and MERGE AFTER\n";
        } else {
            addNode(a, pos, type);
            //cout << " and CREATE new NODE\n";
        }
    } else if(pos == start_a) {
        //cout << "CHANGE AT START: ";
        if(prev_a == NULL) {
            //cout << "ADD TO HEAD\n";
            addNode(NULL, pos, type);
        }
        else if(prev_a->_type == type) {
            //cout << "MERGE PREV\n";
            (prev_a->_end)++;
        } else {
            addNode(prev_a, pos, type);
            //cout << "CREATE new SINGLE NODE\n";
        }
    }
    else{
        //cout << "CHANGE AT MID\n";
        int e = a->_end;
        a->_end = pos-1;
        addNode(a, pos, type);
        addNode(a->_next, e, a->_type);
    }
}
void change(int pos, int newt)
{
    //cout << "CHANGE AT POS " << pos << " " << newt << "\n";
    NODE* cur_node = head;
    int _start = 1;
    NODE* prev_node = NULL;
    while(cur_node != NULL) {
        //cout << "REACH: " << cur_node->_end << " " << cur_node->_type << "\n";
        if(cur_node->_end >= pos) {
            if(cur_node->_type == newt)
                return;
            //cout << "SPLIT::\n";
            _split(cur_node, _start, pos, newt, prev_node);
            break;
        }
        prev_node = cur_node;
        _start = cur_node->_end + 1;
        cur_node = cur_node->_next;
    }
}
int main()
{
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    int pos, cur_type;
    cin >> N;
    cin >> cur_type;
    addNode(NULL, 1, cur_type);

    NODE* cur_node = head;
    for(int i = 2; i <= N; ++i) {
        cin >> cur_type;
        if(cur_node->_type == cur_type)
            cur_node->_end = i;
        else {
            addNode(cur_node, i, cur_type);
            cur_node = cur_node->_next;
        }
    }
    cur_node->_next = NULL;
//    cur_node = head;
//    while(cur_node != NULL) {
//        cout << " " << cur_node->_end << " : " << cur_node->_type << "\n";
//        cur_node = cur_node->_next;
//    }
    cin >> Q;
    for(int i = 0; i < Q; ++i) {
        cin >> pos >> cur_type;
        change(pos, cur_type);
        cout << node_count << "\n";
    }
    return 0;
}
