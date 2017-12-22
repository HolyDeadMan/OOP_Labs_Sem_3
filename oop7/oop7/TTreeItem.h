#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include <cstdlib>
#include <iostream>
#include <memory>
#include "hexagon.h"
#include "Pentagon.h"
#include "octagon.h"

template <class T> class TTree;

template <class T> class TTreeItem
{
public:
	TTreeItem();
	// TBinaryTreeItem(const std::shared_ptr<T> obj);
	TTreeItem(const std::shared_ptr<T> obj, std::shared_ptr<TTreeItem<T>> l, std::shared_ptr<TTreeItem<T>> r, std::shared_ptr<TTreeItem<T>> p);
	std::shared_ptr<T> GetFigure();
	~TTreeItem();
	std::shared_ptr<TTreeItem<T>> GetNext();
	friend class TTree<T>;
	//template <class A> friend std::ostream& operator<<(std::ostream &os, TTreeItem<A> &obj);
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TTreeItem<T>> left;
	std::shared_ptr<TTreeItem<T>> right;
	std::shared_ptr<TTreeItem<T>> parent;
};

#endif
