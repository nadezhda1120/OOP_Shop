#pragma once
#include <iostream>
#include <string>

class User
{
private:

	std::string username;
	std::string password;
	std::string email;

public:
	User() : username(""), password(""), email("") {}
	User(const std::string& username, const std::string& password, const std::string& email)
		:username(username), password(password), email(email) {}


	void setUsername(const std::string& new_username);
	void setPassword(const std::string& new_password);
	void setEmail(const std::string& new_email);

	const std::string& getUsername() const;
	const std::string& getPassword() const;
	const std::string& getEmail() const;

	void print() const;
	void display_intro() const;
};
