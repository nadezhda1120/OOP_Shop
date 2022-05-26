#pragma once
#include <iostream>
#include <string>
#include "product.h"

class Bag : public Product
{
public:
	Bag() = default;
	Bag(const std::string& type, const std::string& brand,  const std::string color, const float& price)
		: Product(type, brand,color, price) {}

	void print() const override;
	void display_product() const override;

	friend class Store;
};
