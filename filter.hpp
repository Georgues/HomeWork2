#ifndef FILTR_H
#define FILTR_H
#include <string>

using std::string;
using std::ostream;

//Класс сетевого фильтра
class filter
{
public:
    //Тип входной вилки
    enum InputType{
        Euro,
        Asia,
        Africa,
        America,
        Australia
    };

    //Конструкторы класса:
    filter();

    filter(const string prod,
             const InputType input,
             const int len);

    filter(const filter &other);

    filter& operator = (const filter &nz);

    //Перегружаем оператор вывода
    friend ostream& operator << (ostream&, const filter&ups);

    //Устанавливаем сеттеры и геттеры
    void setProducer(const string prod);
    string getProducer () const;

    void setInputType(const InputType input);
    InputType getInputType () const;

    void setLenght(const int len);
    int getLenght () const;

private:
    string producer; //Производитель фильтра
    InputType inputType; //Тип входной вилки
    int length; //Длина шнура
};
#endif // FILTR_H
