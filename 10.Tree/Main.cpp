#include "Container/Node.h"

int main()
{
	Node<int>* parent = new Node<int>(10);
	Node<int>* child = new Node<int>(5);
	parent->AddChild(child);
	child->SetParent(parent);

	parent->RemoveChild(child);

	int number = 10;
}