#pragma once
#include <iostream>
#include <vector>
#include <string>


class com
{
public:
	std::string getpostare()
	{
		return postare;
	}
	std::string getautor()
	{
		return autor;
	}
	std::string getcontinut()
	{
		return continut;
	}
	void setpostare(std::string post)
	{
		postare = post;
	}
	void setautor(std::string aut)
	{
		autor = aut;
	}
	void setcontinut(std::string conti)
	{
		continut = conti;
	}

private:
	std::string postare;
	std::string autor;
	std::string continut;
};
