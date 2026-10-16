#include <iostream>
#include "Keeper.h"
#include "Ship.h"
#include "utils/Utils.h"
#include "Exceptions.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printMenu()
{
    cout << "\n         корабли.меню.           \n"
         << "1. Добавить объект\n"
         << "2. Удалить объект\n"
         << "3. Показать весь список объектов\n"
         << "4. Найти объект\n"
         << "5. Изменить объект\n"
         << "6. Сохранить список объектов в файл\n"
         << "7. Загрузить объекты из файла\n"
         << "8. "
         << "0. Выход";
}

void addObject(Keeper &keeper)
{
    cout << "выберите тип: \n"
         << "1. подводная лодка\n"
         << "2. парусник \n"
         << "3. катер\n";
    int type = Utils::readInt("выберите: ", 1, 3);
    Ship *pointer = Keeper::createByType(type);
    try
    {
        cin >> *pointer; //
        keeper.add(pointer);
    }
    catch (...)
    {
        delete pointer;
        throw;
    }
    cout << "добавили объект.";
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    Keeper keeper;
    while (true)
    {
        try
        {
            printMenu();
            int choice = Utils::readInt("выбор: ", 0, 8);
            if (choice == 0)
            {
                break;
            }

            switch (choice)
            {
            case 1:
            {
                addObject(keeper);
                break;
            }
            case 2:
            {
                cout << "объект удалён.";
                break;
            }
            case 3:
            {
                cout << keeper;
                break;
            }
            case 4:
            {
            }
            case 5:
            {
            }
            case 6:
            {
                String nameFile = Utils::readNonEmpty("имя файла для сохранения: ");
                keeper.saveToFile(nameFile);
                cout << "сохранили.\n";
                break;
            }
            case 7:
            {
                String nameFile = Utils::readNonEmpty("имя файла для загрузки: ");
                keeper.loadFromFile(nameFile);
                cout << "загрузили.\n";
                break;
            }
            }
        }
        catch (const InputException &e)
        {
            cout << "\n"
                 << e.what() << "\n";
        }
        catch (const ShipException &e)
        {
            cout << "\n"
                 << e.what() << "\n";
        }
        catch (const FileException &e)
        {
            cout << "\n"
                 << e.what() << "\n";
        }
    }
}
