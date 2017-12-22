#include "stdafx.h"
#include "TreeItem.h"
#include <iostream>

TreeItem::TreeItem(const Hexagon& hexagon)
{
	this->data = hexagon;
	this->sibling = nullptr;
	this->son = nullptr;
}

TreeItem::TreeItem(const TreeItem& orig)
{
	this->data = orig.data;
	this->son = orig.son;
	this->sibling = orig.sibling;
}

TreeItem * TreeItem::getSon()
{
	return this->son;
}

TreeItem * TreeItem::getSibling()
{
	return this->sibling;
}

TreeItem * TreeItem::setSon(TreeItem* son)
{
	this->son = son;
	return this;
}

TreeItem * TreeItem::setSibling(TreeItem* sibling)
{
	this->sibling = sibling;
	return this;
}

Hexagon TreeItem::getHexagon() const
{
	return data;
}

size_t TreeItem::getData()
{
	return data.Square();
}


TreeItem::~TreeItem()
{
	delete sibling;
	delete son;
	//std::cout << "TreeItem deleted" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const TreeItem & obj)
{
	os << "[" << obj.getHexagon() << "]" << std::endl;
	return os;
}
