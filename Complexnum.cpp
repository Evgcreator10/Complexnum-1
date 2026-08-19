#include <iostream>
#include <cmath>

#include <iomanip>

using namespace std;


/* 1. Разработать класс “Cmpx”, реализующий комплексное число, реальная и мнимая часть
которого представлены типом float, и определяются в закрытой части класса.*/
class Cmpx {
private:
    float real;
    float mnim;

    /* 2. Предусмотреть в классе конструктор по умолчанию, конструкторы создания экземпляров
    класса в ортогональной и полярной формах, конструктор копирования.*/
public:
    Cmpx() {
        real = 0;
        mnim = 0;
    }
    Cmpx(float r, float m) {
        real = r;
        mnim = m;
    }

    Cmpx(float rasst, float f) {
        real = rasst * cos(f);
        mnim = rasst * sin(f);
    }


    Cmpx(const Cmpx& obj) {
        real = obj.real;
        mnim = obj.mnim;
    }


    /* 3. Реализовать методы возвращающие вещественные значения ортогональных составляющих,
    модуля вектора, фазы вектора как в радианах, так и в градусах.*/
    float BackReal() {
        return real;
    }
    float BackMnim() {
        return mnim;
    }
    float BackRasst() {
        return sqrt(real * real + mnim * mnim);
    }

    float BackUgol_Rad() {
        return atan2(mnim, real);
    }

    float BackUgol_Deg() {
        return atan2(mnim, real) * (float)180 / 3.14159265;
    }

    /* 4. Реализовать методы строкового представления комплексного числа в ортогональной и
    полярной формах с возможностью указания количество знаков после запятой для
    отображения вещественных составляющих комплексного числа.*/
    void OrtPart(int n) {
        cout << fixed << setprecision(n);


        cout << real << "+" << mnim << "i";
    }

    void PolPart_Rad(int n) {
        cout << fixed << setprecision(n);


        cout << BackRasst() << " * (cos(" << BackUgol_Rad() << ") + i*sin(" << BackUgol_Rad() << "))";
    }

    void PolPart_Deg(int n) {
        cout << fixed << setprecision(n);


        cout << BackRasst() << " * (cos(" << BackUgol_Deg() << ") + i*sin(" << BackUgol_Deg() << "))";
    }

    /* 5. Реализовать основные математические операции над комплексными числами: ‘+’, ‘-‘ , ‘*’ ,
    ’/’ а также поворот вектора на заданный угол.*/
    
};



int main() {



    return 0;
}