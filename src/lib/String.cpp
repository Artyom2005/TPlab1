#include "String.h"
#include <cstring>
#include <cstdio>

using namespace std;

String::String() : data(new char[1]), len(0)
{
    data[0] = '\0';
}

String::String(const char *s) : data(nullptr), len(0)
{
    if (s == nullptr)
    {
        len = 0;
    }
    else
    {
        len = strlen(s);
    }

    data = new char[len + 1];
    if (len > 0)
    {
        memcpy(data, s, len);
    }

    data[len] = '\0';
};

String::String(const String &obj) : data(new char[obj.len + 1], len(obj.len))
{
    memcpy(data, obj.data, len + 1);
}

String::~String()
{
    delete[] data;
    len = 0;
}

String &String::operator=(const String &obj)
{
    if (this != &obj)
    {
        char *temp = new char[obj.len + 1];
        memcpy(tmp, obj.data, obj.len + 1);
        delete[] data;
        data = tmp;
        len = obj.len;
    }

    return *this;
}

String &String::operator+=(const String &obj)
{
    char *temp = new char[len + obj.len + 1];
    memcpy(temp, data, len);
    memcpy(temp + len, obj.data, obj.len + 1);

    delete[] data;
    data = temp;
    len += obj.len;
    return *this;
}

size_t String::size() const
{
    return len;
}

bool String::empty() const
{
    return len == 0;
}

const char *String::c_str() const
{
    return data;
}

char &String::operator[](size_t i)
{
    return data[i];
}

char String::operator[](size_t i) const
{
    return data[i];
}

String String::substr(size_t pos, size_t n) const
{
    if (pos > len)
        pos = len;
    if (n > len - pos)
        n = len - pos;

    String str;
    delete[] str.data;
    str.data = new char[n + 1];

    if (n > 0)
    {
        memcpy(str.data, data + pos, n);
    }

    str.data[n] = '\0';
    str.len = n;
    return str;
}

bool String::operator==(const String &obj) const
{
    return len == obj.len && memcmp(data, obj.data, len) == 0;
}

bool String::operator!=(const String &obj) const
{
    return !(*this == obj);
}

String operator+(const String &a, const String &b)
{
    String str(a);
    str += b;
    return str;
}

ostream &operator<<(ostream &os, const String &str)
{
    os << str.data;
    return os;
}

String intToString(int number)
{
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", number);
    return String(buffer);
}

bool getLine(istream &is, String &out)
{
    String result;
    bool any = false;
    char c;
    while (is.get(c))
    {
        any = true;
        if (c == '\n')
            break;
        char t[2] = {c, '\0'};
        result += String(t);
    }
    if (!any)
        return false;
    out = res;
    return true;
}
