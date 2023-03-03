#pragma once
#include <iostream>
#include <vector>
#include <string>

class post
{
public:
    post()
    {
        likes = 0;
        dislikes = 0;
        loves = 0;
    }
    ;
    std::string getautor()
    {
        return autor;
    }
    std::string gettitlu()
    {
        return titlu;
    }
    std::string getcontinut()
    {
        return continut;
    }
    std::string getdata()
    {
        return data;
    }
    int getlikes()
    {
        return likes;
    }
    int getloves()
    {
        return loves;
    }
    int getdislikes()
    {
        return dislikes;
    }

    void setautor(std::string aut)
    {
        autor = aut;
    }
    void settitlu(std::string titl)
    {
        titlu = titl;
    }
    void setcontinut(std::string conti)
    {
        continut = conti;
    }
    void setdata(std::string dat)
    {
        data = dat;
    }
    void setlikes(int nr)
    {
        likes = nr;
    }
    void setloves(int nr)
    {
        loves = nr;
    }
    void setdislikes(int nr)
    {
        dislikes = nr;
    }
private:
    std::string titlu;
    std::string autor;
    std::string continut;
    std::string data;
    int likes;
    int dislikes;
    int loves;
};
