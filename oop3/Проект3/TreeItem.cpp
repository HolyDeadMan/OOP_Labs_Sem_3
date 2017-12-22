#include "stdafx.h"
#include "TreeItem.h"

#include <iostream>

TreeItem::TreeItem(const std::shared_ptr<Hexagon>& hexagon, const std::shared_ptr<Octagon>& octagon, const std::shared_ptr<Pentagon>& pentagon, size_t key)
{
	this->hexagon = hexagon;
	this->octagon = octagon;
	this->pentagon = pentagon;
	this->sibling = nullptr;
	this->son = nullptr;
	this->key = key;
}

TreeItem::TreeItem(const TreeItem& orig)
{
	this->hexagon = orig.hexagon;
	this->son = orig.son;
	this->sibling = orig.sibling;
}

std::shared_ptr<TreeItem> TreeItem::GetSon()
{
	return this->son;
}

std::shared_ptr<TreeItem> TreeItem::GetSibling()
{
	return this->sibling;
}

void TreeItem::SetSon(std::shared_ptr<TreeItem> son)
{
	this->son = son;
}

void TreeItem::SetSibling(std::shared_ptr<TreeItem> sibling)
{
	this->sibling = sibling;
}

std::shared_ptr<Hexagon> TreeItem::GetHexagon() const
{
	return this->hexagon;
}

std::shared_ptr<Pentagon> TreeItem::GetPentagon() const
{
	return this->pentagon;
}

std::shared_ptr<Octagon> TreeItem::GetOctagon() const
{
	return this->octagon;
}

size_t TreeItem::GetKey() const
{
	return key;
}


TreeItem::~TreeItem()
{
	//std::cout << "TreeItem deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const TreeItem& obj)
{
	os << "[" << *obj.GetHexagon() << " " <<*obj.GetOctagon() << " " <<*obj.GetPentagon() << "]" << ":"<< obj.GetKey() << std::endl;
	return os;
}
