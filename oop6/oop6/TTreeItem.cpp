#include "TTreeItem.h"

template <class T>
TTreeItem<T>::TTreeItem()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class T>
TTreeItem<T>::TTreeItem(const std::shared_ptr<T> &obj)
{
	this->item = obj;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class T> TAllocationBlock
TTreeItem<T>::btree_allocator(sizeof(TTreeItem<T>), 100);

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
	if (this->left) {
		return this->left;
	}
	else if (this->right) {
		return this->right;
	}
	else if (!this->parent) {
		return nullptr;
	}
	else {
		std::shared_ptr<TTreeItem<T>> tmp = this->parent;
		while (!tmp->right) {
			if (!tmp->parent) {
				return nullptr;
			}
			tmp = tmp->parent;
		}
		return tmp->right;
	}
}

template <class T>
void *TTreeItem<T>::operator new(size_t size)
{
	return btree_allocator.allocate();
}

template <class T>
void TTreeItem<T>::operator delete(void *ptr)
{
	btree_allocator.deallocate(ptr);
}

#include "figure.h"
template class TTreeItem<Figure>;
//template std::ostream& operator<<(std::ostream &out, TBinaryTreeItem<Figure> &obj);