#include<bits/stdc++.h>

#define input freopen ("in.txt","r",stdin)
#define output freopen ("out.txt","w",stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool endWord;
    node *children[26]; // Nodo para cada letra del alfabeto

    node() {
        endWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

// Función para insertar una palabra en el Trie
void insert(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = new node();
        }
        currentNode = currentNode->children[index];
        currentNode->currentCharacter = word[i];
    }
    currentNode->endWord = true;
}

// Función para buscar una palabra en el Trie
bool search(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->endWord;
}

// Función auxiliar para verificar si un nodo tiene hijos
bool hasChildren(node *currentNode) {
    for (int i = 0; i < 26; i++) {
        if (currentNode->children[i] != NULL) {
            return true;
        }
    }
    return false;
}

// Función para eliminar una palabra del Trie
bool deleteWord(node *currentNode, string word, int depth = 0) {
    if (depth == word.size()) {
        // Caso base: si llegamos al final de la palabra
        if (!currentNode->endWord) {
            return false; // La palabra no existe
        }
        currentNode->endWord = false; // Marcar el fin de la palabra como falso
        // Si el nodo no tiene más hijos, se puede eliminar
        return !hasChildren(currentNode);
    }
    int index = word[depth] - 'a';
    if (currentNode->children[index] == NULL) {
        return false; // La palabra no existe
    }
    bool canDeleteChild = deleteWord(currentNode->children[index], word, depth + 1);
    // Si se puede eliminar el nodo hijo, lo eliminamos
    if (canDeleteChild) {
        delete currentNode->children[index];
        currentNode->children[index] = NULL;
        // Verificar si el nodo actual no es el fin de otra palabra y no tiene más hijos
        return !currentNode->endWord && !hasChildren(currentNode);
    }
    return false;
}

int main() {
    input;
    output;
    
    int wordsNumber;
    cin >> wordsNumber;
    node *trie = new node();

    // Insertar palabras
    while (wordsNumber--) {
        string word;
        cin >> word;
        insert(trie, word);
    }

    // Buscar palabras
    if (search(trie, "pa")) { 
        cout << "existe la palabra pa" << endl;
    } else {
        cout << "no existe la palabra pa" << endl;
    }

    if (search(trie, "pablo")) { 
        cout << "existe la palabra pablo" << endl;
    } else {
        cout << "no existe la palabra pablo" << endl;
    }

    // Eliminar palabras
    deleteWord(trie, "pablo");

    if (search(trie, "pablo")) { 
        cout << "existe la palabra pablo" << endl;
    } else {
        cout << "no existe la palabra pablo" << endl;
    }

    return 0;
}
