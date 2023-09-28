#pragma once
#include<iostream>

class primitive
{
public:
    virtual ~primitive() {}
    virtual std::string sendName() = 0;

protected:
    primitive(std::string name_):name(name_){}
    std::string  name;
};

class line : public primitive
{
public:
    line() : primitive("Line") {}

    std::string sendName() override 
    {
    	return this->name;
    }
};

class circle : public primitive
{
public:
    circle() : primitive("Circle") {}

    std::string sendName() override 
    {
    	return this->name;
    }
};

class rect : public primitive
{
public:
    rect() : primitive("Rectangle") {}

    std::string sendName() override 
    {
    	return this->name;
    }
};
