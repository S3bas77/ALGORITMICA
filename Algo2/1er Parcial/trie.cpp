#include<bits/stdc++.h>

#define input freopen ("inttrie.txt","r",stdin)
#define output freopen ("out.txt","r",stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool endWord;
    node *children[26]; //el asterisco dice que no importa donde van a crear el children
    node(){
        endWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        } 
    }
};

void insert(node *trie, string word){
    node *currentNode=trie;
    for(int i = 0; i<word.size();i++){
        int index = word[i] - 'a';
        if(currentNode->children[index] == NULL) {
            currentNode->children[index] = new node();
        }
        currentNode = currentNode -> children[index];
        currentNode -> currentCharacter = word[i];
    }
    currentNode->endWord = true;
}

bool search(node *trie, string word){
    node *currentNode = trie;
    for (int i = 0; i < word.size();i++){
        int index = word[i] - 'a';
        if(currentNode->children[index] == NULL) {
            return false;
        }
        currentNode = currentNode -> children[index];
    }
    return currentNode->endWord;
}

int main(){
    int wordsNumber;
    cin >> wordsNumber;
    node *trie = new node();
    while(wordsNumber--){
        string word;
        cin >> word;
        insert(trie, word);
    }
    if (search(trie,"apt")) { 
        cout<<"existe la palara apt"<<endl;
    } else {
        cout<<"no exite la palabra apt"<<endl;
    }
    if (search(trie,"appli")) { 
        cout<<"existe la palara appli"<<endl;
    } else {
        cout<<"no exite la palabra appli"<<endl;
    }
}