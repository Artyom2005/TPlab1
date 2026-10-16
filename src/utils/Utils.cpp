#include "Utils.h"
#include "../Exceptions.h"
#include <iomanip>

using namespace std;

namespace Utils
{
    String trim(const String &str)
    {
        size_t a = 0;
        size_t b = str.size();
        while (a < b && (str[a] == ' ' || str[a] == '\t' || str[a] == '\r' || str[a] == '\n'))
        {
            ++a;
        }
        while (b > a && (str[b - 1] == ' ' || str[b - 1] == '\t' || str[b - 1] == '\r' || str[b - 1] == '\n'))
        {
            --b;
        }

        return str.substr(a, b - a);
    }

    String readNonEmpty(const String &prompt)
    {
        while (true)
        {
            cout << prompt;
            String s;

            if (!getLine(cin, s))
            {
                throw InputException("поток ввода закрыт");
            }

            s = trim(s);
            if (!s.empty())
            {
                return s;
            }
            cout << "Ошибка: строка не должна быть пустой.\n";
        }
    }

    int readInt(const String &prompt, int minV, int maxV)
    {
        while (true)
        {
            cout << prompt;
            int val;
            if (cin >> val && val >= minV && val <= maxV)
            {
                cin.ignore(1000, '\n');
                return val;
            }

            if (cin.eof())
            {
                throw InputException("поток ввода закрыт");
            }

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "введите целое число от " << minV << " до " << maxV << "\n";
        }
    }

    double readPositiveDouble(const String &prompt)
    {
        while (true)
        {
            cout << prompt;
            double val;

            if (cin >> val && val > 0)
            {
                cin.ignore(1000, '\n');
                return val;
            }

            if (cin.eof())
            {
                throw InputException("поток ввода закрыт");
            }

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "введите число больше нуля\n";
        }
    }

    void writeField(ostream &os, const String &str)
    {
        os << str << '\n';
    }

    void writeField(ostream &os, double val)
    {
        os << val << '\n';
    }

    void writeField(ostream &os, int val)
    {
        os << val << '\n';
    }

    String readFileLine(istream &is)
    {
        String str;
        if (!getLine(is, str))
        {
            throw FileException("конец файла");
        }

        if (!str.empty() && str[str.size() - 1] == '\r')
        { // файл на винде заканчивает /r/n
            str = str.substr(0, str.size() - 1);
        }
        return str;
    }

    int readFileInt(istream &is)
    {
        int v;
        if (!(is >> v))
            throw FileException("в файле ожидалось целое число");
        is.ignore(1000, '\n'); // перейти к следующей строке
        return v;
    }

    double readFileDouble(istream &is)
    {
        double v;
        if (!(is >> v))
            throw FileException("в файле ожидалось число");
        is.ignore(1000, '\n');
        return v;
    }
}