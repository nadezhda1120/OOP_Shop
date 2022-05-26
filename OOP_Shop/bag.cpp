#include "bag.h"


void Bag::print() const
{
	std::cout << "Type: " << this->type << " , " << "Brand: " << this->brand << " , " << "Color: "
		<< this->color << ", " << "Price: " << this->price << " $" << std::endl;
}

void Bag::display_product() const
{
	std::cout << std::setw(10) << this->type;
	std::cout << std::setw(10) << this->brand;
	std::cout << std::setw(10) << this->color;
	std::cout << std::setw(10) << this->price << " $" << std::endl;
}


