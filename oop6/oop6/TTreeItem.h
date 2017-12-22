#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include <cstdlib>
#include <iostream>
#include <memory>
#include "hexagon.h"
#include "Pentagon.h"
#include "octagon.h"
#include "TAllocationBlock.h"

template <class T> class TTree;

template <class T> class TTreeItem
{
public:
	TTreeItem();
	TTreeItem(const std::shared_ptr<T> &obj);

	std::shared_ptr<T> GetFigure();
	~TTreeItem();
	std::shared_ptr<TTreeItem<T>> GetNext();

	void *operator new(size_t size);
	void operator delete(void *ptr);

	friend class TTree<T>;
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TTreeItem<T>> left;
	std::shared_ptr<TTreeItem<T>> right;
	std::shared_ptr<TTreeItem<T>> parent;

	static TAllocationBlock btree_allocator;
};

#endif
