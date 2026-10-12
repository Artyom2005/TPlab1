#pragma once
#include "String.h"
#include <iostream>

// Вспомогательные функции ввода с клавиатуры и чтения/записи полей в файл.
namespace Utils
{
    String trim(const String &str);

    // Ввод с клавиатуры
    String readNonEmpty(const String &prompt);
    int readInt(const String &prompt, int minV, int maxV);
    double readPositiveDouble(const String &prompt);

    // Запись полей в файл
    void writeField(std::ostream &os, const String &v);
    void writeField(std::ostream &os, double v);
    void writeField(std::ostream &os, int v);

    // Чтение полей из файла
    String readFileLine(std::istream &is);
    int readFileInt(std::istream &is);
    double readFileDouble(std::istream &is);
}
