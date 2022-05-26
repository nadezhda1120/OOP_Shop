#include "Product.h"

void Product::setType(const std::string& _type)
{
	this->type = _type;
}

void Product::setBrand(const std::string& _brand)
{
	this->brand = _brand;
}

void Product::setPrice(const float& _price)
{
	this->price = price;
}

void Product::setColor(const std::string& _color)
{
	this->color = _color;
}


std::string Product::getType() 
{
	return this->type;
}

std::string Product::getBrand() const
{
	return this->brand;

}

float Product::getPrice() const
{
	return this->price;
}

const std::string Product::getColor() const
{
	return this->color;
}

