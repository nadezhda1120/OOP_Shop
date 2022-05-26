#include "clothes.h"


void Clothes::setSize(const std::string& _size)
{
	this->size = _size;
}

const std::string Clothes::getSize() const
{
	return this->size;
}

void Clothes::print() const
{

	std::cout << "Type: " << this->type << " , " << "Brand: " << this->brand << " , " << "Color: " << this->color << ", "
		<< "Size:" << this->size << "  " << "Price: "
		<< this->price << "$" << std::endl;
}

void Clothes::display_product() const
{
	std::cout << std::setw(12) << this->type;
	std::cout << std::setw(10) << this->brand;
	std::cout << std::setw(10) << this->color;
	std::cout << std::setw(10) << this->size;
	std::cout << std::setw(10) << this->price  << " $" << std::endl;
}
