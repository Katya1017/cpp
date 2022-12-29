#include "AVLNode.h"

AVLNode::AVLNode(int value, int l_int, int r_int, AVLNode* l, AVLNode* r) {
	_left = l;
	_right = r;
	_value = value;
	_height = 1;
}

AVLNode::AVLNode() {
	_height = 1;
	_left = nullptr;
	_right = nullptr;
	_value = 0;
}

int AVLNode::getHeight() {
	return _height;
}

void AVLNode::setHeight(int height) {
	_height = height;
}

int AVLNode::getValue() {
	return _value;
}

void AVLNode::setValue(int value) {
	_value = value;
}

AVLNode* AVLNode::getLeft() {
	return _left;
}

AVLNode* AVLNode::getRight() {
	return _right;
}

void AVLNode::setRight(AVLNode* right) {
	_right = right;
}

void AVLNode::setLeft(AVLNode* left) {
	_left = left;
}