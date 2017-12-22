#pragma once
#include "Hexagon.h"
class TreeItem
{
public:
	TreeItem(const Hexagon& data);
	TreeItem(const TreeItem& orig);
	TreeItem* getSon();
	TreeItem* getSibling();
	TreeItem* setSon(TreeItem* son);
	TreeItem* setSibling(TreeItem* sibling);
	size_t getData();
	Hexagon TreeItem::getHexagon() const;
	friend std::ostream& operator<<(std::ostream& os, const TreeItem& obj);
	~TreeItem();
private:
	TreeItem *sibling;
	TreeItem *son;
	Hexagon data;
};

