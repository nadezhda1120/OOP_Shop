#pragma once
#include "Product.h"


class Clothes : public Product
{
private:
	std::string size;
public:
	Clothes() : size("") {}
	Clothes(const std::string& type, const std::string& brand, const std::string color, const std::string size,  const float& price)
		: Product(type, brand, color, price), size(size) {}

	void setSize(const std::string& _size);
	const std::string getSize() const;

	void print() const override;
	void display_product() const override;

	friend class Store;

	//friend std::istream& operator>>(std::istream& is, Clothes& p) {
	//	is >> std::ws;
	//	std::getline(is, p.type);
	//	is >> p.brand;
	//	is >> p.size;
	//	is >> p.price;
	//	return is;

	//}

};
