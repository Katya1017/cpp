#pragma once
class Node {
public:
	int virtual getHeight() = 0;
	void virtual setHeight(int height) = 0;
	int virtual getValue() = 0;
	void virtual setValue(int value) = 0;
};