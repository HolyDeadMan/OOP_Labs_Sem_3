#pragma once
#include "Hexagon.h"
#include "Octagon.h"
#include "Pentagon.h"
#include <memory>
class TreeItem
{
public:
	TreeItem(const std::shared_ptr<Hexagon>& hexagon, const std::shared_ptr<Octagon>& octagon, const std::shared_ptr<Pentagon>& pentagon, size_t key);
	TreeItem(const TreeItem& orig);

	std::shared_ptr<TreeItem> GetSon();
	std::shared_ptr<TreeItem> GetSibling();
	void SetSon(std::shared_ptr<TreeItem> son);
	void SetSibling(std::shared_ptr<TreeItem> sibling);

	size_t GetKey() const;

	std::shared_ptr<Hexagon> GetHexagon() const;
	std::shared_ptr<Pentagon> GetPentagon() const;
	std::shared_ptr<Octagon> GetOctagon() const;
	friend std::ostream& operator<<(std::ostream& os, const TreeItem& obj);

	~TreeItem();
private:
	std::shared_ptr<TreeItem> son;
	std::shared_ptr<TreeItem> sibling;
	std::shared_ptr<Hexagon> hexagon;
	std::shared_ptr<Pentagon> pentagon;
	std::shared_ptr<Octagon> octagon;
	size_t key;
};

