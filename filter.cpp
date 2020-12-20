#include "filter.hpp"
#include <iostream>

using std::ostream;
using std::endl;

//Пустой конструктор без параметров
filter::filter() : producer("None"),
                   inputType(Euro),
                   length(2)
{ }

//Конструктор с параметрами
filter::filter(const std::string prod,
               const filter::InputType input,
               const int len):
               producer(prod),
               inputType(input),
               length(len)

{}

//Конструктор копирования
filter::filter(const filter &other):
    producer(other.producer),
    inputType(other.inputType),
    length(other.length)
{ }

//Перегрузка оператора присваивания
filter &filter::operator=(const filter &rhs){
    if(this == &rhs) return *this;
    producer = rhs.producer;
    inputType = rhs.inputType;
    length = rhs.length;
    return *this;
}

//Перегрузка оператора вывода
ostream& operator << (ostream& stream, const filter& filt)
{
    stream << "Производитель: " << filt.producer << '\n';

    string types[5]= {"Euro","Asia","Africa","America","Australia"};
    stream << "Тип входной вилки: " << types[filt.inputType] <<'\n';

    stream << "Длина шнура(м): " << filt.length <<endl;

    return stream;
}

//Реализуем геттеры и сеттеры

void filter::setProducer(const string prod){
    producer = prod;
}
std::string filter::getProducer () const{
    return producer;
}

void filter::setInputType(const InputType input){
    inputType = input;
}
filter::InputType filter::getInputType () const{
    return inputType;
}

void filter::setLenght(const int len){
    length = len;
}
int filter::getLenght () const{
    return length;
}
