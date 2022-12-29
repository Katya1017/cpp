#include "AVL.h"


int AVL::height(AVLNode* cur) {
	return cur ? cur->getHeight() : 0;
}

int AVL::bFactor(AVLNode* cur) {
	if (cur) {
		return height(cur->getRight()) - height(cur->getLeft());
	}
	return 0;
}

void AVL::fixHeight(AVLNode* cur) {
	cur->setHeight(std::max(height(cur->getRight()), height(cur->getLeft())) + 1);
}

AVLNode* AVL::beBalance(AVLNode* cur) {
	fixHeight(cur);
	if (bFactor(cur) == 2) {
		if (bFactor(cur->getRight()) < 0) {
			cur->setRight(rotateRight(cur->getRight()));
		}

		return rotateLeft(cur);

	}
	else if (bFactor(cur) == -2) {
		if (bFactor(cur->getLeft()) > 0) {
			cur->setLeft(rotateLeft(cur->getLeft()));
		}

		return rotateRight(cur);
	}
	return cur;
}


AVLNode* AVL::add(int x, AVLNode* cur) {
	if (!cur) {
		return new AVLNode(x);
	}

	if (cur->getValue() < x) {
		cur->setRight(add(x, cur->getRight()));
	}
	else {
		cur->setLeft(add(x, cur->getLeft()));
	}

	return beBalance(cur);
}

AVLNode* AVL::rotateRight(AVLNode* y) {
	AVLNode* x = y->getLeft();
	y->setLeft(x->getRight());
	x->setRight(y);
	fixHeight(y);
	fixHeight(x);
	return x;
}

AVLNode* AVL::rotateLeft(AVLNode* x) {
	AVLNode* y = x->getRight();
	x->setRight(y->getLeft());
	y->setLeft(x);
	fixHeight(x);
	fixHeight(y);
	return y;
}

AVLNode* AVL::remove_(int x, AVLNode* cur) {

	if (cur == nullptr) {
		return nullptr;
	}

	if (cur->getValue() == x) {
		if (cur->getRight() == nullptr && cur->getLeft() == nullptr) {
			delete cur;
			return nullptr;
		}

		if (cur->getLeft() == nullptr) {
			AVLNode* right = cur->getRight();
			delete cur;
			return right;
		}

		if (cur->getRight() == nullptr) {
			AVLNode* left = cur->getLeft();
			delete cur;
			return left;
		}

		// If the node has two "children"

		AVLNode* max_node = cur->getLeft();
		cur->setHeight(cur->getHeight() - 1);
		if (cur->getLeft()->getRight() == nullptr) {
			cur->getLeft()->setHeight(cur->getLeft()->getHeight() - 1);
		}

		while (max_node->getRight()) {
			max_node->setHeight(max_node->getHeight() - 1);
			max_node = max_node->getRight();
		}

		cur->setValue(max_node->getValue());
		cur->setLeft(remove_(max_node->getValue(), cur->getLeft()));

	}
	else {
		if (cur->getValue() < x) {
			cur->setRight(remove_(x, cur->getRight()));
		}
		else {
			cur->setLeft(remove_(x, cur->getLeft()));
		}
	}
	return beBalance(cur);
}

void AVL::elms_(AVLNode* cur, bool fl) {
	if (cur == nullptr && fl) {
		return;
	}

	if (cur == nullptr && !fl) {
		cur = root;
	}

	elms_(cur->getRight(), true);
	elms_(cur->getLeft(), true);
	all_elems.push_back(cur->getValue());
}

AVL::AVL() {
	root = nullptr;
}

bool AVL::exist(int x) const {
	AVLNode* root_copy = this->root;
	while (root_copy) {
		if (x > root_copy->getValue()) {
			root_copy = root_copy->getRight();
		}
		else if (x < root_copy->getValue()) {
			root_copy = root_copy->getLeft();
		}
		else {
			return true;
		}
	}
	return false;
}

void AVL::insert(int x) {
	if (exist(x)) {
		return;
	}
	root = add(x, root);
}

AVLNode* AVL::remove(int x) {
	if (exist(x)) {
		if (root->getValue() == x && root->getHeight() == 1) {
			delete root;
			root = nullptr;
			return nullptr;
		}
		root = remove_(x, root);
	}
	return root;
}

void AVL::elements(AVLNode* cur, bool fl) {
	all_elems.erase(all_elems.begin(), all_elems.end());
	elms_(cur, fl);
}

int AVL::getBalanceRoot() const {
	return bFactor(root);
}

int AVL::getHeight(AVLNode* cur) const {
	return cur->getHeight();
}

void AVL::postorder(AVLNode* p, int indent) const {
	if (p != nullptr) {
		if (p->getRight()) {
			postorder(p->getRight(), indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (p->getRight()) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << p->getValue() << "\n ";
		if (p->getLeft()) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			postorder(p->getLeft(), indent + 4);
		}
	}
}

void AVL::bfs() const {
	std::queue<AVLNode> queue_nodes;
	if (root) {
		std::cout << root->getValue() << " ";
		queue_nodes.push(*root);
	}
	else {
		return;
	}
	while (!queue_nodes.empty()) {
		AVLNode upper_node = queue_nodes.front();
		queue_nodes.pop();
		if (upper_node.getLeft()) {
			AVLNode left_node = *upper_node.getLeft();
			std::cout << left_node.getValue() << " ";
			queue_nodes.push(left_node);
		}
		if (upper_node.getRight()) {
			AVLNode right_node = *upper_node.getRight();
			std::cout << right_node.getValue() << " ";
			queue_nodes.push(right_node);
		}
	}
}
