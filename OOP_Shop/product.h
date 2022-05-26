#pragma once
#include <iostream>
#include <cstring>
#include<string>
#include <iomanip>
#pragma warning(disable : 4996)

class Product
{
protected:
	std::string type;
	std::string brand;
	float  price;
	std::string color;

public:
	Product() : type(""), brand(""), price(0), color("") {}
	Product(const std::string& type, const std::string& brand, const std::string color, const float& price )
		: type(type), brand(brand), price(price), color(color) {}

	void setType(const std::string& _type);
	void setBrand(const std::string& _brand);
	void setPrice(const  float& _price);
	void setColor(const std::string& _color);

	std::string getType();
	std::string getBrand() const;
	float getPrice() const;
	const std::string getColor() const;

	//Pure virtual function
	virtual void print() const = 0;
	virtual void display_product() const = 0;

};
