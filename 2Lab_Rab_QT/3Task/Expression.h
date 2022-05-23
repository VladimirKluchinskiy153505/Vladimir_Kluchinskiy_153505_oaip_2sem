#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <QString>
class Expression{
public:
    Expression(QString expr,double a,double b,double c,double d,double e):expr(expr),a(a),b(b),c(c),d(d),e(e){};
    Expression(){};
    QString get_expr(){
        return expr;
    }
    QString expr;
    double a,b,c,d,e;
};
#endif // EXPRESSION_H
