#pragma once
#include <exception>
#include "utils/String.h"

// базовый эксепшен
class ShipException : public std::exception
{
protected:
    String message;

public:
    explicit ShipException(const String &msg) : message(msg) {};
    virtual ~ShipException() noexcept {};
    const char *what() const noexcept override { return message.c_str(); }
};

class ValidationException : public ShipException
{
public:
    explicit ValidationException(const String &msg) : ShipException("недопустимое значение: " + msg) {};
};

class FileException : public ShipException
{
public:
    explicit FileException(const String &msg) : ShipException("ошибка файла: " + msg) {};
};

class InputException : public ShipException
{
public:
    explicit InputException(const String &msg) : ShipException("ошибка ввода: " + msg) {};
};
