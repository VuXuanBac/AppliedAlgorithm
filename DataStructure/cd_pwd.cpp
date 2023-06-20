#include <bits/stdc++.h>
#include <sstream>
using namespace std;
typedef struct node
{
    string name;
    node* parent;
    vector<node*> children;
}NODE;
NODE* current;
NODE* root;
int command_count;
string command;
string params;
vector<string> split(string input)
{
    stringstream strstream(input);
    string seg;
    vector<string> result;
    while(getline(strstream, seg, '/'))
        result.push_back(seg);
    return result;
}
//void print(NODE* node)
//{
//    cout << "NODE: " << node->name << "- PARENT: " <<
//    node->parent->name << "- CHILD_COUNT: " << node->parent->children.size() << "\n";
//}
string pwd()
{
    NODE* temp = current;
    string result;
    while(temp->parent)
    {
        result = temp->name + "/" + result;
        temp = temp->parent;
    }
    result = temp->name + result;
    return result;
}
void addChild(NODE* parent, string child_name)
{
    NODE* child = new NODE;
    child->name = child_name;
    child->parent = parent;
    parent->children.push_back(child);
}
NODE* getNode(NODE* parent, string name)
{
    int count = parent->children.size();
    for(int i = 0; i < count; ++i)
    {
        if(parent->children.at(i)->name == name)
            return parent->children.at(i);
    }
    NODE* child = new NODE;
    child->name = name;
    child->parent = parent;
    parent->children.push_back(child);
    return child;
}
void cd(string path)
{
    vector<string> _split = split(path);
    int count = _split.size();
    int i = 0;
    if(_split[0] == ""){
        current = root;
        i = 1;
    }
    for(; i < count; ++i)
    {
        //cout << "split[" << i << "] = " << _split[i] << "\n";
        if(_split[i] == "..")
            current = current->parent;
        else if(_split[i] != "")
            current = getNode(current, _split[i]);
        //print(current);
    }
}

void free(NODE* node)
{
    for(int i = 0; i < node->children.size(); ++i)
        free(node->children[i]);
    delete node;
}
int main()
{
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\testout.txt", "w", stdout);
    cin >> command_count;
    root = new NODE;
    root->name = "/";
    root->parent = NULL;
    current = root;
    for(int i = 0; i < command_count; ++i)
    {
        cin >> command;
        //cout << "command: " << command << "\t";
        if(command == "cd")
        {
            cin >> params;
            //cout << params << "\n";
            cd(params);
        }
        else
        {
            cout << pwd() << "\n";
        }
    }
    //free(root);
    return 0;
}

