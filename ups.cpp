#include "ups.hpp"
#include <iostream>

using std::ostream;
using std::endl;

//Пустой конструктор без параметров
ups::ups() : filter("None",
                    Euro,
                    5),
                    outputPower(0),
                    timeBeforeRestart(0)
{ }

//Конструктор с параметрами
ups::ups(const std::string prod,
         const filter::InputType input,
         const int len,
         const int outPower,
         const int dieTime):
        filter(prod,
               input,
               len),
               outputPower(outPower),
               timeBeforeRestart(dieTime)

{}

//Конструктор копирования
ups::ups(const ups &other):
    filter(other),
    outputPower(other.outputPower),
    timeBeforeRestart(other.timeBeforeRestart)
{ }

//Перегрузка оператора присваивания
ups &ups::operator=(const ups &rhs){
    if(this == &rhs) return *this;
    filter::operator = (rhs);
    outputPower = rhs.outputPower;
    timeBeforeRestart = rhs.timeBeforeRestart;
    return *this;
}

//Перегрузка оператора вывода
ostream& operator << (ostream& stream, const ups& ibp)
{
    stream << "Производитель: " << ibp.getProducer() << '\n';

    string types[5]= {"Euro","Asia","Africa","America","Australia"};
    stream << "Тип входной вилки: " << types[ibp.getInputType()] <<'\n';

    stream << "Длина шнура(м): " << ibp.getLenght() <<'\n';

    stream << "Выходная мощность ИБП(Вт): " << ibp.outputPower <<'\n';

    stream << "Время работы без питания на максимальном потреблениира(мин.): " << ibp.timeBeforeRestart <<endl;

    return stream;
}

//Реализуем геттеры и сеттеры

void ups::setOutPower(const int outPower){
    outputPower = outPower;
}
int ups::getOutPower () const{
    return outputPower;
}

void ups::setDieTime(const int dieTime){
    timeBeforeRestart = dieTime;
}
int ups::getDieTime () const{
    return timeBeforeRestart;
}
