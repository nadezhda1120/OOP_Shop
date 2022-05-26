#include "user.h"

void User::setUsername(const std::string& new_username)
{
	this->username = new_username;
}
void User::setPassword(const std::string& new_password)
{
	this->password = new_password;
}
void User::setEmail(const std::string& new_email)
{
	this->email = new_email;
}

const std::string& User::getUsername() const
{
	return this->username;
}

const std::string& User::getPassword() const
{
	return this->password;
}

const std::string& User::getEmail() const
{
	return this->email;
}

void User::print() const
{
	std::cout << "Enter username: " << this->username << std::endl;
	std::cout << "Enter password: " << this->password << std::endl;
	std::cout << "Enter your e_mail: " << this->email << std::endl;
}

void User::display_intro() const
{
	std::cout << "Welcome to our Online Shop " << this->username << std::endl;
}