#include "TBTree.h"

template <class T>
TBinaryTree<T>::TBinaryTree()
{
	head = nullptr;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTree<T>::find(std::shared_ptr<T> &obj)
{
	std::shared_ptr<TBinaryTreeItem<T>> item = head;
	while (item != nullptr) {
		if (item->item->Side() == obj->Side()) {
			return item;
		}
		else if (item->item->Side() > obj->Side()) {
			item = item->left;
		}
		else if (item->item->Side() < obj->Side()) {
			item = item->right;
		}
	}
	return nullptr;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTree<T>::minValueNode(std::shared_ptr<TBinaryTreeItem<T>> root)
{
	std::shared_ptr<TBinaryTreeItem<T>> min = root;

	while (min->left != nullptr) {
		min = min->left;
	}

	return min;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTree<T>::Successor(std::shared_ptr<TBinaryTreeItem<T>> node)
{
	if (!node->right) {
		return minValueNode(node->right);
	}
	std::shared_ptr<TBinaryTreeItem<T>> parent = node->parent;
	while (parent && node == parent->right) {
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T>> TBinaryTree<T>::deleteNode(std::shared_ptr<TBinaryTreeItem<T>> root, int32_t side)
{
	if (root == nullptr) {
		return root;
	}

	if (side < root->item->Side()) {
		root->left = deleteNode(root->left, side);
	}
	else if (side > root->item->Side()) {
		root->right = deleteNode(root->right, side);
	}
	else {
		if (root->left == nullptr) {
			std::shared_ptr<TBinaryTreeItem<T>> temp = root->right;
			std::shared_ptr<TBinaryTreeItem<T>> parent = root->parent;
			temp->parent = parent;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
			return temp;
		}
		else if (root->right == nullptr) {
			std::shared_ptr<TBinaryTreeItem<T>> temp = root->left;
			std::shared_ptr<TBinaryTreeItem<T>> parent = root->parent;
			temp->parent = parent;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
			return temp;
		}

		std::shared_ptr<TBinaryTreeItem<T>> temp = minValueNode(root->right);
		root->item = temp->item;
		root->right = deleteNode(root->right, temp->item->Side());
	}
	return root;
}

template <class T>
void TBinaryTree<T>::remove(int32_t side)
{
	head = TBinaryTree<T>::deleteNode(head, side);
}

template <class T>
void TBinaryTree<T>::insert(std::shared_ptr<T> &obj)
{
	if (head == nullptr) {
		std::shared_ptr<TBinaryTreeItem<T>> tmp = nullptr;
		head = std::make_shared<TBinaryTreeItem<T>>(obj, nullptr, nullptr, tmp);
		return;
	}


	std::shared_ptr<TBinaryTreeItem<T>> item = head;
	std::shared_ptr<TBinaryTreeItem<T>> parent = head;
	while (true) {
		if (obj->Side() <= item->item->Side()) {
			if (item->left == nullptr) {
				item->left = std::make_shared<TBinaryTreeItem<T>>(obj, nullptr, nullptr, parent);
				break;
			}
			else {
				parent = item->left;
				item = item->left;
			}
		}
		else {
			if (item->right == nullptr) {
				item->right = std::make_shared<TBinaryTreeItem<T>>(obj, nullptr, nullptr, parent);
				break;
			}
			else {
				parent = item->right;
				item = item->right;
			}
		}
	}
}

template <class T>
void TBinaryTree<T>::print_tree(std::shared_ptr<TBinaryTreeItem<T>> item, int32_t a, std::ostream& os)
{
	for (int32_t i = 0; i < a; i++) {
		os << "  ";
	}
	item->GetFigure()->Print();
	if (item->left != nullptr) {
		TBinaryTree<T>::print_tree(item->left, a + 1, os);
	}
	else if (item->right != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
	if (item->right != nullptr) {
		TBinaryTree<T>::print_tree(item->right, a + 1, os);
	}
	else if (item->left != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
}


template <class T>
void TBinaryTree<T>::print()
{
	if (head != nullptr) {
		TBinaryTree<T>::print_tree(head, 0, std::cout);
	}
}

template <class T>
void TBinaryTree<T>::print(std::ostream& os)
{
	if (head != nullptr) {
		TBinaryTree<T>::print_tree(head, 0, os);
	}
}

template <class T>
bool TBinaryTree<T>::empty()
{
	return head == nullptr;
}

template <class T>
TBinaryTree<T>::~TBinaryTree()
{
}

template <class T>
std::ostream& operator<<(std::ostream& os, TBinaryTree<T> &tree)
{
	tree.print(os);
	return os;
}

template <class T>
TIterator<TBinaryTreeItem<T>, T> TBinaryTree<T>::begin()
{
	if (!head || !head->left) {
		return TIterator<TBinaryTreeItem<T>, T>(head);
	}

	std::shared_ptr<TBinaryTreeItem<T>> tmp = head;
	while (tmp->left) {
		tmp = tmp->left;
	}
	return TIterator<TBinaryTreeItem<T>, T>(tmp);
}

template <class T>
TIterator<TBinaryTreeItem<T>, T> TBinaryTree<T>::end()
{
	return TIterator<TBinaryTreeItem<T>, T>(nullptr);
}

template <class T>
void TBinaryTree<T>::Balanced(std::shared_ptr<T> *&arr, int l, int r)
{
	if (l > r) {
		return;
	}
	int m = (l + r) / 2;
	insert(arr[m]);
	Balanced(arr, l, m - 1);
	Balanced(arr, m + 1, r);
}

template <class T>
void TBinaryTree<T>::MySort(std::shared_ptr<T> *&arr, int l, int r)
{
	int x = l + (r - l) / 2;
	int i = l;
	int j = r;

	while (i <= j) {
		while (arr[i]->Side() < arr[x]->Side()) {
			i++;
		}
		while (arr[j]->Side() > arr[x]->Side()) {
			j--;
		}
		if (i <= j) {
			std::shared_ptr<T> tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r) {
		MySort(arr, i, r);
	}

	if (l < j) {
		MySort(arr, l, j);
	}
}

template <class T>
void TBinaryTree<T>::recClear(std::shared_ptr<TBinaryTreeItem<T>> node)
{
	if (!node) {
		return;
	}
	if (node->left) {
		recClear(node->left);
	}
	if (node->right) {
		recClear(node->right);
	}
	node->parent = nullptr;
	node->item = nullptr;
}

template <class T>
void TBinaryTree<T>::Clear()
{
	if (!head) {
		return;
	}
	if (head->left) {
		recClear(head->left);
	}
	if (head->right) {
		recClear(head->right);
	}
}

template <class T>
void TBinaryTree<T>::rm(std::shared_ptr<TBinaryTreeItem<T>> node)
{
	if (!node) {
		return;
	}
	node->parent = nullptr;
	if (node->left) {
		rm(node->left);
	}
	if (node->right) {
		rm(node->right);
	}
}


template <class T>
void TBinaryTree<T>::gg()
{
	if (!head) {
		return;
	}
	if (head->left) {
		rm(head->left);
	}
	if (head->right) {
		rm(head->right);
	}
}

#include "figure.h"
template class TBinaryTree<Figure>;
template std::ostream& operator<<(std::ostream& os, TBinaryTree<Figure> &tree);