#include <iostream>
#include <random>

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;
};

struct AVLBinTree {
    Node *NIL;
    Node *root;

    int height (Node *z) {
        return (z != NIL) ? z->height : 0;
    }

    int bfactor (Node *z) {
        int a = 0;
        if (z != NIL) a = height (z->right) - height(z->left);
        return a;
    }

    void fix_height (Node *z) {
        int hl = height(z->left);
        int hr = height(z->right);
        z->height = std::max(hl, hr) + 1;
    }

    Node * rotateright (Node *z) {
        Node *q = z->left;
        z->left = q->right;
        q->right = z;
        fix_height(z);
        fix_height(q);
        return q;
    }

    Node * rotateleft (Node *z) {
        Node *q = z->right;
        z->right = q->left;
        q->left = z;
        fix_height(z);
        fix_height(q);
        return q;
    }

    Node * balance (Node *z) {
        fix_height(z);
        if( bfactor(z) == 2) {
            if( bfactor(z->right) < 0) z->right = rotateright(z->right);
            return rotateleft(z);
        }
        if( bfactor(z) == -2) {
            if( bfactor(z->left) > 0) z->left = rotateleft(z->left);
            return rotateright(z);
        }
        return z;
    }

    Node * rec_insert (Node *par, Node *z) { //вспомогательная функция для вставки
        if (par == NIL) return z;
        if (z->key < par->key) par->left = rec_insert(par->left, z);
        else par->right = rec_insert(par->right, z);
        return balance(par);
    }

    void insert (Node *z) { //сама вставка
        root = rec_insert(root, z);
    }

    Node * search (Node *z, int key) { // поиск в ветке с родителем z по ключу key
        if (z == NIL or key == z->key) return z;
        if (key < z->key) return search(z->left, key);
        else return search(z->right, key);
    }

    Node * fmin (Node *z) { //поиск min max в ветке с родителем z
        while (z->left != NIL) z = z->left;
        return z;
    }

    Node * fmax (Node *z) {
        while (z->right != NIL) z = z->right;
        return z;
    }

    Node * removemin (Node *z) { //вспомогательная функция для удаления
        if (z->left == NIL) return z->right;
        z->left = removemin(z->left);
        return balance(z);
    }

    Node * rec_remove (Node *par, Node *z) { //вспомогательная функция для удаления
        if (par == NIL) return NIL;
        if (z->key < par->key) par->left = rec_remove(par->left, z);
        else if (z->key > par->key) par->right = rec_remove(par->right, z);
        else {
            Node *pl = par->left;
            Node *pr = par->right;
            if (pr == NIL) return pl;
            Node *min = fmin(pr);
            min->right = removemin(pr);
            min->left = pl;
            return balance(min);
        }
        return balance(par);
    }

    void remove (Node *z) { //удоление
        root = rec_remove(root, z);
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
    AVLBinTree tree;
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
    std::cout << (tree.fmin(tree.root))->key << ' ' << (tree.fmax(tree.root))->key << '\n'; //выводим мин макс
    return 0;
}
