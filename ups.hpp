#ifndef UPS_HPP
#define UPS_HPP
#include <string>
#include <filter.hpp>

using std::string;
using std::ostream;

//����� ��������� �������������� �������(���)
class ups : public filter{

public:
    //������������ ������:
    ups();

    ups(const string prod,
        const InputType input,
        const int len,
        const int outPower,
        const int dieTime);

    ups (const ups &other);

    //O����� ������, �������� �������� � ������� � ����� ����� �� ������� (rhs)
    ups& operator = (const ups &rhs);

    //����������� �������� ������
    friend ostream& operator << (ostream&, const ups& ibp);

    //������������� ��������� �������� � ��������
    void setOutPower(const int outPower);
    int getOutPower () const;

    void setDieTime(const int dieTime);
    int getDieTime () const;

private:

    int outputPower; //�������� �������� ���
    int timeBeforeRestart; //����� ������ ��� ������� �� ������������ �����������
};

#endif // UPS_HPP
