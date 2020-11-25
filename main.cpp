#include "trapeze.hpp"
#include "vector.hpp"
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;
/*
 * Ежов Н П М8О-204Б-19
 * Разработать шаблоны классов согласно варианту задания.
 * Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат.
 * Классы должны иметь публичные поля.
 * Фигуры являются фигурами вращения, т.е. равносторонними (кроме трапеции и прямоугольника).
 * Для хранения координат фигур необходимо использовать шаблон  std::pair.
 * Создать шаблон динамической коллекцию, согласно варианту задания:
    1.	Коллекция должна быть реализована с помощью умных указателей (std::shared_ptr, std::weak_ptr).
    Опционально использование std::unique_ptr;
    2.	В качестве параметра шаблона коллекция должна принимать тип данных - фигуры;
    Вариант 28: динамический массив, трапеция
 */

int main() {
    int command;
    CustomVector<Trapeze<int>> vec;
    cout << "This program created for demonstrating template collection work.\n" <<
    "Enter 1, if you want to add figure in vector\nEnter 2, to print area of all figures on the screen, " << "\nEnter 3,"
    << " if you want to delete last figure, \nEnter 4, to print all figures \nEnter 5, to display this help text "
    << "once again\nEnter 6, and after that index of the figure which you want to see\nEnter 7, if you  want to exit the program\n";
    while(true){
        cin >> command;
        cout.flush();
        switch(command){
            case 1:{
                Trapeze<int>figure;
                try {
                    cin >> figure;
                    vec.push_back(figure);
                } catch (exception &e) {
                    cout << e.what() << std::endl;
                    break;
                }
                cout << "Figure added successfully\n";
            }
            break;
            case 2:{
                double res = 0;
                int size = vec.size();
                for (int i = 0; i < size; ++i){
                    res += vec[i].area();
                }
            }
            break;
            case 3:{
                try{
                    vec.pop_back();
                }
                catch(exception &e) {
                    cout << e.what() << std::endl;
                    break;
                }
                cout << "Figure deleted successfully\n";
            }
            break;
            case 4:{
                int size = vec.size();
                for (int i = 0; i < size; ++i){
                    cout << vec[i];
                }
            }
            break;
            case 5:{
                cout << "This program created for demonstrating template collection work.\n" <<
                     "Enter 1, if you want to add figure in vector\nEnter 2, to print area of all figures on the screen, " << "\nEnter 3,"
                     << " if you want to delete last figure, \nEnter 4, to print all figures \nEnter 5, to display this help text "
                     << "once again\nEnter 6, and after that index of the figure which you want to see\nEnter 7, if you  want to exit the program\n";
            }
            break;
            case 6:{
                int index;
                cin >> index;
                --index;
                cout << vec[index];
            }
            break;
            case 7:{
                return 0;
            }
            break;
            default:{
                cout << "Error, wrong command number\n";
                continue;
            }
        }
    }
    return 0;
}