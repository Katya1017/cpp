#pragma once
#include "Node.h"

class AVLNode : Node {
private:
	AVLNode* _left;
	AVLNode* _right;
	int _value;
	int _height;
public:
	explicit AVLNode(int value, int l_int = 0, int r_int = 0, AVLNode* l = nullptr, AVLNode* r = nullptr);
	AVLNode(); 
	int getHeight();
	void setHeight(int height);
	int getValue();
	void setValue(int value);
	AVLNode* getLeft();
	AVLNode* getRight();
	void setRight(AVLNode* right);
	void setLeft(AVLNode* left);
};