#pragma once

#include "Node.h"
#include <vector>
#include <iostream>

// 트리 클래스.
template<typename T>
class Tree
{
public:

	Tree(const T& data)
	{
		// 루트 노드 생성.
		root = new Node<T>(data);
	}

	~Node()
	{
		// Todo: 자손 노드 모두 제거하는 함수 구현 후 호출.
		
	}

public:

	// 부모 노드의 값을 사용해 해당 부모에 자손을 추가.
	bool AddChild(const T& parentData, const T& childData)
	{
		// 부모 노드 검색.
		// 검색 함수 구현 후 호출.
		Node<T>* outParent = nullptr;
		bool result = FindRecursive(parentData, root, outParent);

		// 부모 검색에 성공했으면 자손 노드 추가.
		if (result)
		{
			outParent->AddChild(childData);
			return true;
		}

		// 부모 검색에 실패하면 자손 추가 실패.
		return false;
	}

	bool Find(const T& data, Node<T>*& outNode)
	{
		return FindRecursive(data, root, outNode);
	}

private:

	// data: 검색하려는 값.
	// node: 현재 검색하는 노드.
	// outNode: 검색에 성공했을 때 반환할 노드.
	// 함수의 반환 값: 검색 성공 실패 여부.
	bool FindRecursive(const T& data, Node<T>* node, Node<T>*& outNode)
	{
		// 검색 실패(탈출 조건)/
		if (!node)
		{
			// null 값 설정 및 함수 종료 (검색 실패).
			outNode = nullptr;
			return false;
		}

		// 노드가 가진 값이 검색하는 값인지 비교.
		if (node->GetData() == data)
		{
			outNode = node;
			return true;
		}

		// 자손 노드로 내려가면서 재귀적으로 추가 검색 진행.
		std::vector<Node<T>*>& childre = node->GetChildren();
		const int length = static_cast<int>(children.size());
		for (int ix = 0; ix < length; ++ix)
		{
			// 자손 노드 검색 진행.
			bool result = FindRecursive(data, children[ix], outNode);
			if (result)
			{
				return true;
			}
		}
		
		// 검색 실패.
		outNode = nullptr;
		return false;
	}

	bool RemoveRecursive(const T& data, Node<T>* node)
	{
		Node<T>* outNode = nullptr;
		bool result = FindRecursive(data, node, outNode);
		
		// 검색에 성공했으면 삭제 진행.
		if (result)
		{
			// 부모 노드의 자손 목록에서 현재 노드 제거.
			Node<T>* parent = outNode->GetParent();
			if (parent)
			{
				auto it = std::find(
					parent->GetChildren().begin(),
					parent->GetChildren().end(),
					node
				);

				// 목록에서 노드 제거.
				parent->GetChildren().erase(it);
			}

			// 노드가 자손이 있다면 자손 노드 제거.
			std::vector<Node<T>*>& children = outNode->GetChildren();
			while (children.size() > 0)
			{
				outNode->RemoveChild(children[0]);
			}

			// 노드 제거 및 정리.
			safeDelete(outNode);
			outNode = nullptr;

			return true;
		}


		// 검색 못했으면 삭제 실패.
		return false;
	}

	// 전위순회 재귀 함수.
	void PreorderTraversalRecursive(Node<T>* node, int depth = 0)
	{
		// 탈출 조건.
		if (!node)
		{
			return;
		}

		// 계층을 보여주기 위한 깊이 출력.
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << "  ";
		}

		// 전위 순회는 부모 노드를 먼저 처리(방문).
		std::cout << node->GetData() << "\n";

		// 자손 노드 처리(방문).
		std::vector<Node<T>*>& children = node->GetChildren();
		const int length = static_cast<int>(children.size());
		if (length == 0)
		{
			return;
		}

		for (int ix = 0; ix < length; ++ix)
		{
			Node<T>* child = children[ix];
			PreorderTraversalRecursive(child, depth + 1);
		}
	}

private:
	// 루트 노드.
	Node<T>* root = nullptr;
};