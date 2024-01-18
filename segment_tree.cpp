//
// Created by Ihor Orlenko on 18.01.2024.
//
#include <iostream>
#include <vector>

using namespace std;

#define NEUTRAL 0

vector<int> a;              // Изначальный массив
vector<int> tree;           // Дерево отрезков

void update(
        int v,              // Индекс вершины
        int l, int r,       // Левая и правая границы подотрезка
        int pos, int val    // Позиция и значение обновляемого элемента
        ){

    if (l == r) {
        tree[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if (pos <= m) {         // Элемент лежит в левом поддереве
        update(2 * v, l, m, pos, val);
    } else {                // Элемент лежит в правом поддереве
        update(2 * v + 1, m + 1, r, pos, val);
    }

    tree[v] = tree[2 * v] + tree[2 * v + 1];
}


int get(
        int v,              // Индекс вершины
        int l, int r,       // Левая и правая границы подотрезка
        int ql, int qr      // Границы искомого отрезка
        ) {
    if (ql <= l && r <= qr) {
        return tree[v];
    }

    if (ql > r || qr < l) {
        return NEUTRAL;
    }

    int m = (l + r) / 2;

    int left_ans = get(2 * v, l, m, ql, qr);
    int right_ans = get(2 * v + 1, m + 1, r, ql, qr);

    return left_ans + right_ans;

 }