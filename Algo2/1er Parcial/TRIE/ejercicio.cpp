#include<bits/stdc++.h>

#define input freopen ("inttrie.txt","r",stdin)
#define output freopen ("out.txt","w",stdout)
using namespace std;

struct node {
    char currentNumber;
    bool endCell;
    node *number[10];
    node(){
        endCell=false;
        for (int i = 0; i < 10; i++)
        {
            number[i]=NULL;
        }
    }
};
bool isNumber,isCreated;
void insert(node *trie, string number){
    node *currentNode=trie;
    for(int i = 0; i<number.size();i++){
        int index = number[i]-'0';

        if(currentNode->number[index] == NULL) {
            isCreated = true;
            currentNode->number[index] = new node();
        }
        currentNode = currentNode -> number[index];
        if(currentNode->endCell){
            isNumber=true;
        }
        currentNode -> currentNumber = number[i];
    }
    if(isCreated){
        currentNode->endCell = true;
    }
}

bool search(node *trie, string number){
    node *currentNode=trie;
    for(int i = 0; i<number.size();i++){
        int index=number[i]-'0';
        if(currentNode->number[index] == NULL) {
            return false;
        }
        currentNode = currentNode -> number[index];
    }
    return currentNode->endCell;
}

int main(){
    input;
    output;
    int contacts;
    cin >> contacts;
    node *trie=new node();
    while(contacts--){
        string cell;
        cin >> cell;
        isNumber=false;
        isCreated=false;
        insert(trie, cell);
    }
    if (search(trie,"777")) { 
        cout<<"PREFIJO"<<endl;
    } else {
        cout<<"CORRECT"<<endl;
    }
    if (search(trie,"77722")) { 
        cout<<"PREFIJO"<<endl;
    } else {
        cout<<"CORRECT"<<endl;
    }
}