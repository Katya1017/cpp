#pragma once
#include "AVLNode.h"

class AbstractAVL {
private:
	virtual AVLNode* add(int x, AVLNode* root) = 0;
	virtual AVLNode* remove_(int x, AVLNode* root) = 0;
public:
	virtual void insert(int x) = 0;
	virtual AVLNode* remove(int x) = 0;
	virtual bool exist(int x) const = 0;
};