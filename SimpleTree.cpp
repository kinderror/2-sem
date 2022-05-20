#include <iostream>
#include <random>

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *par;
};

struct BinTree {
    Node *NIL;
    Node *root;

    Node * search (Node *z, int key) { // поиск в ветке с родителем z по ключу key
        if (z == NIL or key == z->key) return z;
        else if (key < z->key) return search(z->left, key);
        else return search(z->right, key);
    }

    Node * min (Node *z) { //поиск min max в ветке с родителем z
        while (z->left != NIL) z = z->left;
        return z;
    }

    Node * max (Node *z) {
        while (z->right != NIL) z = z->right;
        return z;
    }

    void insert (Node *z) { //вставка узла z с потомками NIL.
        Node *y = NIL;
        Node *x = this->root;
        while (x != NIL) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->par = y;
        if (y == NIL) this->root = z;
        else if (z->key < y->key) y->left = z;
        else y->right = z;
    }

    void transplant (Node *z1, Node *z2) { // Вместе ветки с роидетелм z1 ставит ветку z2
        if (z1->par == NIL) this->root = z2;
        else if (z1 == (z1->par)->left) (z1->par)->left = z2;
        else (z1->par)->right = z2;
        if (z2 != NIL) z2->par = z1->par;
    }

    void remove (Node *z) { // удаление по указателю на узел
        if (z->left == NIL) transplant(z, z->right);
        else if (z->right == NIL) transplant(z, z->left);
        else {
            Node *y = min(z->right);
            if (y->par != z) {
                transplant(y, y->right);
                y->right = z->right;
                (y->right)->par = y;
            }
            transplant(z, y);
            y->left = z->left;
            (y->left)->par = y;
        }

    }
    void print(Node *z, int level)  //вывод дерева(в 1 столбике 1 уровень, во втором-второй и тд). При несбалансированном дереве может быть не оч красивым, но структуру сохранит
    {
        if(z != NIL)
        {
            print(z->left,level + 1);
            for(int i = 0;i< level;i++) std::cout << "   ";
            std::cout << z->key << '\n';
            print(z->right,level + 1);
        }
    }
};

int main() {
    Node *NIL = nullptr; //узлы будем хранить в векторе.
    int key;
    int n = 10;
    BinTree tree;
    tree.NIL = NIL;
    tree.root = NIL;
    std::vector <Node> a(n);

    std::random_device dev; //генерим n случайных ключей и печатаем их
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < n; i++) {
        key = dist(rng);
        a[i].left = NIL;
        a[i].right = NIL;
        a[i].key = key;
        std::cout << a[i].key << ' ';
    }
    std::cout << "-------------------------------------------------------------------------------------------" << '\n';
    for (int i = 0; i < n; i++) {
        tree.insert(&a[i]); //заполняем дерево и выводим его
    }
    tree.print(tree.root, 0);
    std::cout << "-------------------------------------------------------------------------------------------" << '\n';
    tree.remove(&a[1]); //удаляем элемент и выводим дерево
    tree.print(tree.root, 0);
    std::cout << "-------------------------------------------------------------------------------------------" << '\n';
    std::cout << (tree.min(tree.root))->key << ' ' << (tree.max(tree.root))->key << '\n'; //выводим мин макс
    return 0;
}
