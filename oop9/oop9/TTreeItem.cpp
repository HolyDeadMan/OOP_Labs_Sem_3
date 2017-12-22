#include "TTreeItem.h"

template <class T>
TTreeItem<T>::TTreeItem()
{
	item = nullptr;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class T>
TTreeItem<T>::TTreeItem(const std::shared_ptr<T> obj, std::shared_ptr<TTreeItem<T>> l, std::shared_ptr<TTreeItem<T>> r, std::shared_ptr<TTreeItem<T>> p)
{
	item = obj;
	left = l;
	right = r;
	parent = p;
}

template <class T>
TTreeItem<T>::~TTreeItem()
{
}

template <class T>
std::shared_ptr<T> TTreeItem<T>::GetFigure()
{
	return this->item;
}

template <class T>
std::shared_ptr<TTreeItem<T>> TTreeItem<T>::GetNext()
{
	if (this->right) {
		std::shared_ptr<TTreeItem<T>> temp = this->right;
		while (temp->left) {
			temp = temp->left;
		}
		return temp;
	}

	std::shared_ptr<TTreeItem<T>> succ = nullptr;
	std::shared_ptr<TTreeItem<T>> n = std::make_shared<TTreeItem<T>>(*this);
	std::shared_ptr<TTreeItem<T>> root = std::make_shared<TTreeItem<T>>(*this);
	while (root->parent) {
		root = root->parent;
	}


	while (root) {
		if (n->item->Side() < root->item->Side()) {
			succ = root;
			root = root->left;
		}
		else if (n->item->Side() > root->item->Side()) {
			root = root->right;
		}
		else {
			break;
		}
	}
	return succ;
}

#include "figure.h"
template class TTreeItem<Figure>;
//template std::ostream& operator<<(std::ostream &out, TBinaryTreeItem<Figure> &obj);