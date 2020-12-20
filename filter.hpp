#ifndef FILTR_H
#define FILTR_H
#include <string>

using std::string;
using std::ostream;

//����� �������� �������
class filter
{
public:
    //��� ������� �����
    enum InputType{
        Euro,
        Asia,
        Africa,
        America,
        Australia
    };

    //������������ ������:
    filter();

    filter(const string prod,
             const InputType input,
             const int len);

    filter(const filter &other);

    filter& operator = (const filter &nz);

    //����������� �������� ������
    friend ostream& operator << (ostream&, const filter&ups);

    //������������� ������� � �������
    void setProducer(const string prod);
    string getProducer () const;

    void setInputType(const InputType input);
    InputType getInputType () const;

    void setLenght(const int len);
    int getLenght () const;

private:
    string producer; //������������� �������
    InputType inputType; //��� ������� �����
    int length; //����� �����
};
#endif // FILTR_H
