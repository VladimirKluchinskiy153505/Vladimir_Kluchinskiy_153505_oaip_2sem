#include <iostream>
using namespace std;
struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression(){};
};

struct Number : public Expression
{
    Number(double value)
        : value(value)
    {}
    double evaluate() const override {
        return value;
    }
    ~Number() {};
private:
    double value;
};

struct BinaryOperation : public Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }

    double evaluate() const override {
        if (op == '+') {
            return left->evaluate() + right->evaluate();
        }
        else if (op == '-') {
            return left->evaluate() - right->evaluate();

        }
        else if (op == '*') {
            return left->evaluate() * right->evaluate();
        }
        else {
            return left->evaluate() / right->evaluate();
        }
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }
private:
    Expression const* left;
    Expression const* right;
    char op;
};
bool check_equals(Expression const* left, Expression const* right)
{
    return (*(int*)left==*(int*)right);
}
bool check_equals2(Expression* left, Expression* right)
{
        return (*reinterpret_cast<int*>(left) == *reinterpret_cast<int*>(right));
    }

int main()
{
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    BinaryOperation obj1(nullptr,0,nullptr);
    Expression* ptr1 = &obj1;
    Number obj2(0);
    Expression* ptr2 = &obj2;
    Number obj3(0);
    Expression* ptr3 = &obj3;
    cout << check_equals(ptr3, ptr2);
	return 0;
}

