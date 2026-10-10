#pragma once
#include <iostream>
#include <cstddef>

class String
{
private:
    char *data;
    size_t len;

public:
    String();
    String(const String &obj);
    String(const char *s);
    ~String();

    String &operator=(const String &obj);
    String &operator+=(const String &obj);
    size_t size() const;
    bool empty() const;
    const char *c_str() const;
    char &operator[](size_t i);
    char operator[](size_t i) const;
    String substr(size_t poz, size_t i) const;
    bool operator==(const String &object) const;
    bool operator!=(const String &obj) const;

    friend String operator+(const String &a, const String &b);
    friend std::ostream &operator<<(std::ostream &os, const String &s);
};

String intToString(int number);
bool getLine(std::istream &is, String &out);