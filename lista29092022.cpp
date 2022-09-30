#include<stdio.h>

typedef int dado;

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct List {

    Node *cabeca, *cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista está vazia ou não
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n)
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x) { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            if (tmp->valor == x) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }

     void removeN(int n) {
        for (int i = 0; i < n && size > 0; i++) {
            popBack();
        }
    }

    void removeSegundo() {
        if (size == 2) {
            popBack();
        } else if (size > 2) {
            Node* segundo = cabeca->prox;
            Node* terceiro = segundo->prox;
            cabeca->prox = terceiro;
            delete(segundo);
            size--;
        }
    }

    void inserirTamanho() {
        pushBack(size);
    }

    void inserirN(int n) {
        for (int i = 1; i <= n; i++) {
            pushBack(i);
        }
    }

    void inserirPenultimo(dado valor) {
        if (size >= 2) {
            Node* penultimo = cabeca;
            while (penultimo->prox != cauda) {
                penultimo = penultimo->prox;
            }
            Node* novo = new Node(valor);
            penultimo->prox = novo;
            novo->prox = cauda;
            size++;
        }
    }

    void removePosicaoN(int n) {
        if (n <= size) {
            if (n == 1) {
                popFront();
            } else if (n == size) {
                popBack();
            } else {
                Node *anterior = NULL;
                Node *excluir = cabeca;
                for (int i = 0; i < n - 1; i++) {
                    anterior = excluir;
                    excluir = excluir->prox;
                }
                Node *posterior = excluir->prox;
                anterior->prox = posterior;
                delete(excluir);
                size--;
            }
        }
    }

    void tamanhoN(int n) {
        size == n;
        pushFront(size);
        if (size>n) {
            popBack();
        } else if (size<n) {
            for (int i = 0; i <= n; i++) {
                pushFront(i);
                size++;
            }
        }
    }

    void inserir_remover (int n) {
        for (int i = 0; i < n; i++) {
            popBack();
        }
    }

    void inserirLista() {
        for (int i = 0; i == size; i++) {
            Node *posterior->prox = cabeca;
            posterior->prox = cauda;
            pushBack(size);
        }
    }

    void receberN(int n) {
        if (size != n) {
            for (int i = 0; i < n; i++) {
                pushBack(i);
                size++;
            }
        }
    }

};

int main() {
    List l;
    l.pushBack(50);
    l.pushBack(30);
    l.pushBack(10);
    l.pushFront(20);
    l.pushFront(10);
    l.popBack();
    /*l.popFront();
    l.popFront();
    l.popBack();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();*/
    l.print();
    printf("%d\n", l.size);
    return 0;
}

