#include "ups.hpp"
#include <iostream>

using std::ostream;
using std::endl;

//������ ����������� ��� ����������
ups::ups() : filter("None",
                    Euro,
                    5),
                    outputPower(0),
                    timeBeforeRestart(0)
{ }

//����������� � �����������
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

//����������� �����������
ups::ups(const ups &other):
    filter(other),
    outputPower(other.outputPower),
    timeBeforeRestart(other.timeBeforeRestart)
{ }

//���������� ��������� ������������
ups &ups::operator=(const ups &rhs){
    if(this == &rhs) return *this;
    filter::operator = (rhs);
    outputPower = rhs.outputPower;
    timeBeforeRestart = rhs.timeBeforeRestart;
    return *this;
}

//���������� ��������� ������
ostream& operator << (ostream& stream, const ups& ibp)
{
    stream << "�������������: " << ibp.getProducer() << '\n';

    string types[5]= {"Euro","Asia","Africa","America","Australia"};
    stream << "��� ������� �����: " << types[ibp.getInputType()] <<'\n';

    stream << "����� �����(�): " << ibp.getLenght() <<'\n';

    stream << "�������� �������� ���(��): " << ibp.outputPower <<'\n';

    stream << "����� ������ ��� ������� �� ������������ �������������(���.): " << ibp.timeBeforeRestart <<endl;

    return stream;
}

//��������� ������� � �������

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
