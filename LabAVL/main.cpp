#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include "Node.h"
#include "AVLNode.h"
#include "AbstractAVL.h"
#include "AVL.h"

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    AVL set;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        set.insert(x);
    }
    set.bfs();
    system("pause");
}