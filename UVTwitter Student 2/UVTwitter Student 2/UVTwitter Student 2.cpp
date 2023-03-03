#include <iostream>
#include <fstream>

#include "../../Clase/post.h"
#include "../../Clase/com.h"
#include "../../Clase/user.h"

#include "../../Auth.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdio.h>
#include<algorithm>
#define setCol(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
using std::vector;
using std::string;

int ctxt1,ctxt2;

int logic(int value, int comanda, int lim)
{
    // logica din meniuri, stiu ca n-aveam nevoie,
    // am facut-o la inceput, refuz principial s-o sterg
    if (comanda == 115)
        value++;
    if (comanda == 119)
        value--;
    if (value == 0)
        value = lim;
    if (value == lim + 1)
        value = 1;
    return value;
}
int menu(vector <string> menu, bool withlogic = 1, vector <string> before = {}, vector <string> after = {})
{
    int currentLine = 1;
    while (true)
    {
        setCol(ctxt1);
        int ind=0;
        for (auto i = before.begin(); i != before.end(); i++)
        {
            if ((*i).length()==3)
            {
                char x1,x2,x3; //daca elementul este de format +XY, unde XY este un numar in hexadecimal, vom schimba culoarea textului la XY in loc sa afisam
                x1=(*i)[0];
                x2=(*i)[1];
                x3=(*i)[2];
                if(x1=='+'&&(x2>='0'&&x2<='9')||(x2>='a'&&x2<='f')&&(x3>='0'&&x3<='9')||(x3>='a'&&x3<='f'))
                {
                    int cul;
                    if(x2>='0'&&x2<='9')
                    {
                        cul=x2-'0';
                    }
                    else
                    {
                        cul=x2-'a'+10;
                    }
                    cul=cul*16;
                    if(x3>='0'&&x3<='9')
                    {
                        cul+=x3-'0';
                    }
                    else
                    {
                        cul+=x3-'a'+10;
                    }
                    setCol(cul);
                }
                else
                {
                    if(i != before.end()) //daca elementul trecut era de schimbare de culoare, atunci nu se va afisa un rand nou
                    {
                        if((*(i+1)).length()==3)
                        {
                            char x1,x2,x3;
                            x1=(*(i+1))[0];
                            x2=(*(i+1))[1];
                            x3=(*(i+1))[2];
                            if(x1=='+'&&(x2>='0'&&x2<='9')||(x2>='a'&&x2<='f')&&(x3>='0'&&x3<='9')||(x3>='a'&&x3<='f'))
                            {
                                std::cout << *i;
                            }
                            else
                                std::cout << *i << std::endl;
                        }
                        else
                            std::cout << *i << std::endl;
                    }
                    else
                        std::cout << *i << std::endl;

                }
            }
            else
            {
                if(i != before.end()) //daca elementul trecut era de schimbare de culoare, atunci nu se va afisa un rand nou
                {
                    if((*(i+1)).length()==3)
                    {
                        char x1,x2,x3;
                        x1=(*(i+1))[0];
                        x2=(*(i+1))[1];
                        x3=(*(i+1))[2];
                        if(x1=='+'&&(x2>='0'&&x2<='9')||(x2>='a'&&x2<='f')&&(x3>='0'&&x3<='9')||(x3>='a'&&x3<='f'))
                        {
                            std::cout << *i;
                        }
                        else
                            std::cout << *i << std::endl;
                    }
                    else
                        std::cout << *i << std::endl;
                }
                else
                    std::cout << *i << std::endl;

            }
        }
        for (int i = 0; i != menu.size(); i++)
        {
            if (withlogic && (i == currentLine - 1))
                setCol(ctxt2);
            else
                setCol(ctxt1);
            std::cout << menu[i];
            setCol(ctxt1);
            std::cout << std::endl;
        }

        for (auto i = after.begin(); i != after.end(); i++)
        {
            if ((*i).length()==3)
            {
                char x1,x2,x3; //daca elementul este de format +XY, unde XY este un numar in hexadecimal, vom schimba culoarea textului la XY in loc sa afisam
                x1=(*i)[0];
                x2=(*i)[1];
                x3=(*i)[2];
                if(x1=='+'&&(x2>='0'&&x2<='9')||(x2>='a'&&x2<='f')&&(x3>='0'&&x3<='9')||(x3>='a'&&x3<='f'))
                {
                    int cul;
                    if(x2>='0'&&x2<='9')
                    {
                        cul=x2-'0';
                    }
                    else
                    {
                        cul=x2-'a'+10;
                    }
                    cul=cul*16;
                    if(x3>='0'&&x3<='9')
                    {
                        cul+=x3-'0';
                    }
                    else
                    {
                        cul+=x3-'a'+10;
                    }
                    setCol(cul);
                }
                else
                {
                    if(i != after.end()) //daca elementul urmator e de schimbare de culoare, atunci nu se va afisa un rand nou
                    {
                        if((*(i+1)).length()==3)
                        {
                            char x1,x2,x3;
                            x1=(*(i+1))[0];
                            x2=(*(i+1))[1];
                            x3=(*(i+1))[2];
                            if(x1=='+'&&(x2>='0'&&x2<='9')||(x2>='a'&&x2<='f')&&(x3>='0'&&x3<='9')||(x3>='a'&&x3<='f'))
                            {
                                std::cout << *i;
                            }
                            else
                                std::cout << *i << std::endl;
                        }
                        else
                            std::cout << *i << std::endl;
                    }
                    else
                        std::cout << *i << std::endl;

                }
            }
            else
            {
                if(i != after.end()) //daca elementul urmator e de schimbare de culoare, atunci nu se va afisa un rand nou
                {
                    if((*(i+1)).length()==3)
                    {
                        char x1,x2,x3;
                        x1=(*(i+1))[0];
                        x2=(*(i+1))[1];
                        x3=(*(i+1))[2];
                        if(x1=='+'&&(x2>='0'&&x2<='9')||(x2>='a'&&x2<='f')&&(x3>='0'&&x3<='9')||(x3>='a'&&x3<='f'))
                        {
                            std::cout << *i;
                        }
                        else
                            std::cout << *i << std::endl;
                    }
                    else
                        std::cout << *i << std::endl;
                }
                else
                    std::cout << *i << std::endl;

            }
        }
        if (withlogic)
        {
            char comanda = _getch();
            system("cls");
            currentLine = logic(currentLine, comanda, menu.size());
            if (comanda == 13)
                return currentLine;
            // pentru enter
            if (comanda == 27)
                return -2;
            // pentru escape
        }
        else
        {
            printf("\n\n");
            system("pause");
            system("cls");
            return 0;
            // doar afisare
        }

    }
}


int main()
{
    user utilizator;
    vector <string> menulogare = { "Log in","Sign Up" }; //logare utilizator
    while (true)
    {
        int optiune;
        ctxt1=0x0e;
        ctxt2=0xe0;
        optiune = menu(menulogare);
        ctxt1=0x07;
        ctxt2=0x70;
        system("cls");
        if (optiune == 1)
        {
            utilizator = login();
            if (utilizator.getnume() == "")
            {
                setCol(0x0c);
                std::cout << "Utilizatorul nu este in baza de date" << std::endl;
                setCol(0x0e);
                system("pause");
                system("cls");
            }
            else
                break;
        }
        if (optiune == 2)
        {
            signup();
            system("cls");
        }
    }
    system("cls");
    vector <post> postari;
    string posa;
    std::ifstream fin("../../post.txt");  //incarcare toate posturile in memorie
    while (std::getline(fin, posa))
    {
        int j;
        vector <string> com;
        string curr;
        for (j = 0; j < posa.length(); j++)
        {
            if (posa[j] == '*')
            {
                com.push_back(curr);
                curr.clear();
            }
            else
            {
                curr += posa[j];
            }
        }
        com.push_back(curr);
        post ana;
        ana.setautor(com[0]);
        ana.settitlu(com[1]);
        ana.setcontinut(com[2]);
        ana.setdata(com[3]);
        ana.setlikes(stoi(com[4]));
        ana.setdislikes(stoi(com[5]));
        ana.setloves(stoi(com[6]));
        postari.push_back(ana);
    }

    while (true) //afisare toate postarile
    {
        ctxt1=0x0b;
        ctxt2=0xb0;
        vector <string> top = { "+0e","Postari: "," "," " };
        vector <string> postmenu;
        for (int i = 0; i < postari.size(); i++)
            postmenu.push_back(postari[i].gettitlu());
        postmenu.push_back("Sign Out");
        int val = menu(postmenu, 1, top);
        if (val == postmenu.size() )
        {
            system("cls");
            break;
        }
        val--;
        while (true)  //pagina postare
        {
            vector <string> detalii;
            post curent;
            curent = postari[val];

            detalii.push_back("+0f");
            detalii.push_back(curent.getdata());
            detalii.push_back("");
            detalii.push_back("+0e");
            detalii.push_back("    "+curent.gettitlu());
            detalii.push_back("");
            detalii.push_back("+0f");
            detalii.push_back("            Autor: ");
            detalii.push_back("+0e");
            detalii.push_back(curent.getautor());
            detalii.push_back("");
            detalii.push_back("+0b");
            detalii.push_back("    "+curent.getcontinut());
            detalii.push_back("");

            detalii.push_back("+0c");
            detalii.push_back("        Likes: ");
            detalii.push_back("+0e");
            detalii.push_back(std::to_string(curent.getlikes()));
            detalii.push_back("+0f");
            detalii.push_back(" | ");
            detalii.push_back("+0d");
            detalii.push_back("Loves: ");
            detalii.push_back("+0e");
            detalii.push_back(std::to_string(curent.getloves()));
            detalii.push_back("+0f");
            detalii.push_back(" | ");
            detalii.push_back("+09");
            detalii.push_back("Dislikes: ");
            detalii.push_back("+0e");
            detalii.push_back(std::to_string(curent.getdislikes()));
            vector <string> actiuni = { "Like","Love","Dislike","Comentarii","Exit" };

            ctxt1=0x0e;
            ctxt2=0xe0;
            int vali = menu(actiuni, 1, detalii);
            if (vali==1)
            {
                postari[val].setlikes(postari[val].getlikes() + 1);
                continue;
            } //adauga like
            if (vali==2)
            {
                postari[val].setloves(postari[val].getloves() + 1);
                continue;
            } //adauga love
            if (vali==3)
            {
                postari[val].setdislikes(postari[val].getdislikes() + 1);
                continue;
            } //adauga dislike
            if (vali==4)
            {
                while (true) //afisare comentarii
                {
                    vector <com> comentarii;
                    string posa;
                    std::ifstream fin("../../com.txt");
                    while (std::getline(fin, posa))
                    {
                        int j;
                        vector <string> come;
                        string curr;
                        for (j = 0; j < posa.length(); j++)
                        {
                            if (posa[j] == '*')
                            {
                                come.push_back(curr);
                                curr.clear();
                            }
                            else
                            {
                                curr += posa[j];
                            }
                        }
                        come.push_back(curr);
                        com ana;
                        ana.setpostare(come[0]);
                        ana.setautor(come[1]);
                        ana.setcontinut(come[2]);
                        comentarii.push_back(ana);
                    }
                    vector <com> comentariiPostare;
                    for (int i = 0; i < comentarii.size(); i++)
                    {
                        if (comentarii[i].getpostare() == curent.gettitlu())
                            comentariiPostare.push_back(comentarii[i]);
                    }
                    vector <string> before = { "+0f","Comentarii: ",{},{} };
                    for (int i = 0; i < comentariiPostare.size(); i++)
                    {
                        string tempor = "  " + comentariiPostare[i].getautor();
                        before.push_back("+0b");
                        before.push_back(tempor);
                        before.push_back("");
                        before.push_back("+0e");
                        before.push_back(comentariiPostare[i].getcontinut());
                        before.push_back("");
                        before.push_back("");

                    }
                    vector <string> content = { "Adauga un comentariu nou","Exit" };
                    int value = menu(content, 1, before);
                    if (value == 1) //comentariu nou
                    {
                        system("cls");
                        setCol(0x0f);
                        std::cout << "Comentariu: " << std::endl;
                        setCol(0x0e);
                        string content;
                        std::getline(std::cin,content);
                        content.erase(remove(content.begin(), content.end(), '*'), content.end());
                        if(content.length()>0)
                        {
                            std::ofstream outfile;
                            outfile.open("../../com.txt", std::ios_base::app);
                            outfile << '\n' << curent.gettitlu() << "*" << utilizator.getnume() << "*" << content;
                            outfile.close();
                            com temporary;
                            temporary.setautor(utilizator.getnume());
                            temporary.setcontinut(content);
                            temporary.setpostare(curent.gettitlu());
                        }
                        system("cls");
                        continue;

                    }
                    if (value == 2)  //exit menu
                    {
                        system("cls");
                        break;
                    }

                }

            }
            if (vali==5)
            {
                system("cls");
                break;
            } //exit menu
            {

            }
        }

    }

    std::ofstream fout("../../post.txt"); //updatare date posturi
    for (int k = 0; k < postari.size(); k++)
    {
        fout << postari[k].getautor() << "*";
        fout << postari[k].gettitlu() << "*";
        fout << postari[k].getcontinut() << "*";
        fout << postari[k].getdata() << "*";
        fout << postari[k].getlikes() << "*";
        fout << postari[k].getdislikes() << "*";
        fout << postari[k].getloves() << std::endl;
    }



}


