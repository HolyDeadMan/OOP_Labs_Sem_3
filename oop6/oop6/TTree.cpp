#include "TTree.h"

template <class T>
TTree<T>::TTree()
{
	head = nullptr;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTree<T>::find(std::shared_ptr<T> &obj)
{
	std::shared_ptr<TTreeItem<T>> item = head;
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
std::shared_ptr<TTreeItem<T>> TTree<T>::minValueNode(std::shared_ptr<TTreeItem<T>> root)
{
	std::shared_ptr<TTreeItem<T>> min = root;

	while (min->left != nullptr) {
		min = min->left;
	}

	return min;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTree<T>::deleteNode(std::shared_ptr<TTreeItem<T>> root, int32_t side)
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
			std::shared_ptr<TTreeItem<T>> temp = root->right;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
			return temp;
		}
		else if (root->right == nullptr) {
			std::shared_ptr<TTreeItem<T>> temp = root->left;
			root->left = nullptr;
			root->right = nullptr;
			root->parent = nullptr;
			return temp;
		}

		std::shared_ptr<TTreeItem<T>> temp = minValueNode(root->right);
		root->item = temp->item;
		root->right = deleteNode(root->right, temp->item->Side());
	}
	return root;
}

template <class T>
void TTree<T>::remove(int32_t side)
{
	head = TTree<T>::deleteNode(head, side);

}

template <class T>
void TTree<T>::insert(std::shared_ptr<T> &obj)
{
	if (head == nullptr) {
		head = std::make_shared<TTreeItem<T>>(obj);
		return;
	}


	std::shared_ptr<TTreeItem<T>> item = head;
	while (true) {
		if (obj->Side() <= item->item->Side()) {
			if (item->left == nullptr) {
				item->left = std::make_shared<TTreeItem<T>>(obj);
				break;
			}
			else {
				item = item->left;
			}
		}
		else {
			if (item->right == nullptr) {
				item->right = std::make_shared<TTreeItem<T>>(obj);
				break;
			}
			else {
				item = item->right;
			}
		}
	}
}

template <class T>
void TTree<T>::print_tree(std::shared_ptr<TTreeItem<T>> item, int32_t a, std::ostream& os)
{
	for (int32_t i = 0; i < a; i++) {
		os << "  ";
	}
	item->GetFigure()->Print();
	if (item->left != nullptr) {
		TTree<T>::print_tree(item->left, a + 1, os);
	}
	else if (item->right != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
	if (item->right != nullptr) {
		TTree<T>::print_tree(item->right, a + 1, os);
	}
	else if (item->left != nullptr) {
		for (int32_t i = 0; i <= a; i++) {
			os << "  ";
		}
		os << "null" << std::endl;
	}
}


template <class T>
void TTree<T>::print()
{
	if (head != nullptr) {
		TTree<T>::print_tree(head, 0, std::cout);
	}
}

template <class T>
void TTree<T>::print(std::ostream& os)
{
	if (head != nullptr) {
		TTree<T>::print_tree(head, 0, os);
	}
}

template <class T>
bool TTree<T>::empty()
{
	return head == nullptr;
}

template <class T>
TTree<T>::~TTree()
{
}

template <class T>
std::ostream& operator<<(std::ostream& os, TTree<T> &tree)
{
	tree.print(os);
	return os;
}

template <class T>
TIterator<TTreeItem<T>, T> TTree<T>::begin()
{
	return TIterator<TTreeItem<T>, T>(head);
}

template <class T>
TIterator<TTreeItem<T>, T> TTree<T>::end()
{
	std::shared_ptr<TTreeItem<T>> tmp = head;
	while (tmp->right) {
		tmp = tmp->right;
	}
	return TIterator<TTreeItem<T>, T>(tmp);
}

#include "figure.h"
template class TTree<Figure>;
template std::ostream& operator<<(std::ostream& os, TTree<Figure> &tree);
