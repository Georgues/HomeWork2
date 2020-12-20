#include "filter.hpp"
#include <iostream>

using std::ostream;
using std::endl;

//������ ����������� ��� ����������
filter::filter() : producer("None"),
                   inputType(Euro),
                   length(2)
{ }

//����������� � �����������
filter::filter(const std::string prod,
               const filter::InputType input,
               const int len):
               producer(prod),
               inputType(input),
               length(len)

{}

//����������� �����������
filter::filter(const filter &other):
    producer(other.producer),
    inputType(other.inputType),
    length(other.length)
{ }

//���������� ��������� ������������
filter &filter::operator=(const filter &rhs){
    if(this == &rhs) return *this;
    producer = rhs.producer;
    inputType = rhs.inputType;
    length = rhs.length;
    return *this;
}

//���������� ��������� ������
ostream& operator << (ostream& stream, const filter& filt)
{
    stream << "�������������: " << filt.producer << '\n';

    string types[5]= {"Euro","Asia","Africa","America","Australia"};
    stream << "��� ������� �����: " << types[filt.inputType] <<'\n';

    stream << "����� �����(�): " << filt.length <<endl;

    return stream;
}

//��������� ������� � �������

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
