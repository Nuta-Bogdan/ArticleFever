#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#define setCol(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)

#include "Clase/user.h"
#include "Clase/post.h"
#include "Clase/com.h"

using std::vector;
using std::string;
void signup()
{
	string nume;
	string parola;
    setCol(0x0e);
	std::cout << "Username: ";
    setCol(0x0b);
	std::cin >> nume;
    setCol(0x0e);
	std::cout << "Parola: ";
    setCol(0x0b);
	std::cin >> parola;

	string curent;
	std::ifstream fin("../../user.txt");

	while (std::getline(fin, curent))
	{
		string a;
		string b;
		int i = 0;
		int ok = 0;
		for (i = 0; i < curent.size(); i++) {
			if (curent[i] == ',')
			{
				ok = 1;
				continue;
			}
			if (ok == 0)
				a += curent[i];
			if (ok == 1)
				b += curent[i];
		}
		if (a == nume)
		{
            setCol(0x0c);
            std::cout << "Utilizatorul exista deja in baza de date" << std::endl;
            setCol(0x0e);
            system("pause");
            system("cls");
			return;
		}

	}
	fin.close();


	std::ofstream outfile;

	outfile.open("../../user.txt", std::ios_base::app);
	outfile << nume << "," << parola << '\n';
	outfile.close();
}
user login()
{
    setCol(0x0e);
	string nume;
	string parola;
	std::cout << "Username: ";
    setCol(0x0b);
	std::cin >> nume;
    setCol(0x0e);
	std::cout << "Parola: ";
    setCol(0x0b);
	std::cin >> parola;
	string curent;
	std::ifstream fin("../../user.txt");
	while (std::getline(fin, curent))
	{
		string a;
		string b;
		int i = 0;
		int ok = 0;
		for (i = 0; i < curent.size(); i++) {
			if (curent[i] == ',')
			{
				ok = 1;
				continue;
			}
			if (ok == 0)
				a += curent[i];
			if (ok == 1)
				b += curent[i];
		}
		if (a == nume && b == parola)
		{
			user cur;
			cur.setnume(a);
			cur.setparola(b);
			string posa;
			std::ifstream fin("../../post.txt");
			while (std::getline(fin, posa)&&(posa!=""))
			{
				int j;
				vector <string> com;
				string curr;
				for (j = 0; j < posa.length(); j++)
				{
					if (posa[j] == ',') {
						com.push_back(curr);
						curr.clear();
					}
					else
					{
						curr += posa[j];
					}
				}
				com.push_back(curr);
				if (com[0] == a)
				{
					post ana;
					ana.setautor(com[0]);
					ana.settitlu(com[1]);
					ana.setcontinut(com[2]);
					ana.setdata(com[3]);
					ana.setlikes(stoi(com[4]));
					ana.setdislikes(stoi(com[5]));
					ana.setloves(stoi(com[6]));
					cur.addpost(ana);
				}

			}
			return cur;
		}

	}
	user an;
	an.setnume("");
	return an;

}
