#include <iostream>
#include <locale>
using namespace std;

// Структура, представляющая автомобиль
struct Car
{
    char Brand[20];
    char Model[20];
    int Year;
    int Mileage;
};

// Структура, представляющая обувь
struct Shoes
{
    char Brand[20];
    char Model[20];
    int Size;
};

// Функция для ввода информации об автомобиле
Car InputCar()
{
    Car car;
    cout << "Марка: ";
    cin >> car.Brand;
    cout << "Модель: ";
    cin >> car.Model;
    cout << "Год выпуска: ";
    cin >> car.Year;
    cout << "Пробег: ";
    cin >> car.Mileage;
    return car;
}

// Функция для вывода информации об автомобиле
void OutputCar(const Car& car)
{
    cout << "Марка: " << car.Brand << endl;
    cout << "Модель: " << car.Model << endl;
    cout << "Год выпуска: " << car.Year << endl;
    cout << "Пробег: " << car.Mileage << " км" << endl;
    cout << "-------------------------" << endl;
}

// Функция для ввода информации об обуви
Shoes InputShoes()
{
    Shoes shoes;
    cout << "Марка: ";
    cin >> shoes.Brand;
    cout << "Модель: ";
    cin >> shoes.Model;
    cout << "Размер: ";
    cin >> shoes.Size;
    return shoes;
}

// Функция для вывода информации об обуви
void OutputShoes(const Shoes& shoes)
{
    cout << "Марка: " << shoes.Brand << endl;
    cout << "Модель: " << shoes.Model << endl;
    cout << "Размер: " << shoes.Size << endl;
    cout << "-------------------------" << endl;
}

// Функция для удаления всех автомобилей из базы данных
void RemoveAllCars(Car carDatabase[])
{
    for (int i = 0; i < 10; i++)
    {
        carDatabase[i] = Car(); // Очищаем запись об автомобиле
    }
    cout << "Все автомобили удалены." << endl;
}

// Функция для удаления всей обуви из базы данных
void RemoveAllShoes(Shoes shoesDatabase[])
{
    for (int i = 0; i < 10; i++)
    {
        shoesDatabase[i] = Shoes(); // Очищаем запись об обуви
    }
    cout << "Вся обувь удалена." << endl;
}

int main()
{
    setlocale(LC_ALL, "");
    Car carDatabase[10]; // База данных автомобилей
    Shoes shoesDatabase[10]; // База данных обуви
    int choice;

    while (true)
    {
        cout << "Меню:" << endl;
        cout << "1. Добавить автомобиль" << endl;
        cout << "2. Добавить обувь" << endl;
        cout << "3. Удалить автомобиль" << endl;
        cout << "4. Удалить обувь" << endl;
        cout << "5. Удалить все автомобили" << endl;
        cout << "6. Удалить всю обувь" << endl;
        cout << "7. Вывести все автомобили" << endl;
        cout << "8. Вывести всю обувь" << endl;
        cout << "9. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int index;
            cout << "Введите номер автомобиля (0-9): ";
            cin >> index;
            if (index >= 0 && index < 10)
            {
                carDatabase[index] = InputCar();
                cout << "Автомобиль добавлен." << endl;
            }
            else
            {
                cout << "Неверный номер автомобиля. Попробуйте еще раз." << endl;
            }
            break;
        }
        case 2:
        {
            int index;
            cout << "Введите номер обуви (0-9): ";
            cin >> index;
            if (index >= 0 && index < 10)
            {
                shoesDatabase[index] = InputShoes();
                cout << "Обувь добавлена." << endl;
            }
            else
            {
                cout << "Неверный номер обуви. Попробуйте еще раз." << endl;
            }
            break;
        }
        case 3:
        {
            int index;
            cout << "Введите номер автомобиля для удаления (0-9): ";
            cin >> index;
            if (index >= 0 && index < 10)
            {
                carDatabase[index] = Car(); // Очищаем запись об автомобиле
                cout << "Автомобиль удален." << endl;
            }
            else
            {
                cout << "Неверный номер автомобиля. Попробуйте еще раз." << endl;
            }
            break;
        }
        case 4:
        {
            int index;
            cout << "Введите номер обуви для удаления (0-9): ";
            cin >> index;
            if (index >= 0 && index < 10)
            {
                shoesDatabase[index] = Shoes(); // Очищаем запись об обуви
                cout << "Обувь удалена." << endl;
            }
            else
            {
                cout << "Неверный номер обуви. Попробуйте еще раз." << endl;
            }
            break;
        }
        case 5:
            RemoveAllCars(carDatabase);
            break;
        case 6:
            RemoveAllShoes(shoesDatabase);
            break;
        case 7:
            cout << "Список автомобилей:" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (carDatabase[i].Brand[0] != '\0')
                {
                    cout << "Автомобиль " << i << ":" << endl;
                    OutputCar(carDatabase[i]);
                }
            }
            break;
        case 8:
            cout << "Список обуви:" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (shoesDatabase[i].Brand[0] != '\0')
                {
                    cout << "Обувь " << i << ":" << endl;
                    OutputShoes(shoesDatabase[i]);
                }
            }
            break;
        case 9:
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    }

    return 0;
}
