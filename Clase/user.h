#pragma once
#include <iostream>
#include <vector>
#include <string>

class user
{
public:
	user(){};
	user(std::string num, std::string par)
	{
		nume = num;
		parola = par;
	}
	void addpost(post postare)
	{
		postari.push_back(postare);
	}
	void removepost(post postare)
	{
		for (int i = 0; i < postari.size(); i++)
			if (postari[i].gettitlu() == postare.gettitlu()) {
				std::vector<post>::iterator it;
				it = postari.begin() + i;
				postari.erase(it);
				return;
			}
	}
	std::string getnume() {
		return nume;
	}
	std::string getparola()
	{
		return parola;
	}
	std::vector <post> getpostari() {
		return postari;
	}
	void setnume(std::string num)
	{
		nume = num;
	}
	void setparola(std::string par)
	{
		parola = par;
	}


private:
	std::string nume;
	std::string parola;
	std::vector <post> postari;
};


