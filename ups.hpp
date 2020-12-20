#ifndef UPS_HPP
#define UPS_HPP
#include <string>
#include <filter.hpp>

using std::string;
using std::ostream;

//Класс источника бесперебойного питания(ИБП)
class ups : public filter{

public:
    //Конструкторы класса:
    ups();

    ups(const string prod,
        const InputType input,
        const int len,
        const int outPower,
        const int dieTime);

    ups (const ups &other);

    //Oбъект класса, значение которого я копирую в новый класс из старого (rhs)
    ups& operator = (const ups &rhs);

    //Перегружаем оператор вывода
    friend ostream& operator << (ostream&, const ups& ibp);

    //Устанавливаем прототипы сеттеров и геттеров
    void setOutPower(const int outPower);
    int getOutPower () const;

    void setDieTime(const int dieTime);
    int getDieTime () const;

private:

    int outputPower; //Выходная мощность ИБП
    int timeBeforeRestart; //Время работы без питания на максимальном потреблении
};

#endif // UPS_HPP
