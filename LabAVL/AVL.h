#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include "AbstractAVL.h"
#include "AVLNode.h"

class AVL : public AbstractAVL {
private:
	static int height(AVLNode* cur);

	static int bFactor(AVLNode* cur);

	static void fixHeight(AVLNode* cur);

	AVLNode* beBalance(AVLNode* cur);


	AVLNode* add(int x, AVLNode* cur);

	static AVLNode* rotateRight(AVLNode* y);

	AVLNode* rotateLeft(AVLNode* x);

	AVLNode* remove_(int x, AVLNode* cur);

	void elms_(AVLNode* cur = nullptr, bool fl = false);


public:
	std::vector<int> all_elems;
	AVLNode* root;

	AVL();

	bool exist(int x) const;

	void insert(int x);

	AVLNode* remove(int x);

	void elements(AVLNode* cur = nullptr, bool fl = false);

	int getBalanceRoot() const;

	int getHeight(AVLNode* cur) const;

	void postorder(AVLNode* p, int indent) const;

	void bfs() const;
};
