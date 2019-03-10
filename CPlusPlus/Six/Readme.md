### 第6章 函数和递归入门

---

6.3 数学库函数

result = sqrt(25.0) = 5.0;//求平方根的函数

ceil(x); //ceil(9.2) = 10.0

exp(x); //指数函数e的x次方

cos(x); //x（弧度）de 三角余弦

fabs(x); // x的绝对值

floor(x); //floor(9.2)为9.0

fmod(x,y); //x/y的浮点数余数

log(x); //x(底数为e)的自然对数

log10(x); //x(底数为10)的对数

pow(x,y); //x的y次幂

sin(x); //x(弧度)的三角正弦

sqrt(x); //x的平方根

tan(x); //x的三角正切

---

#include<cstdlib>

rand()%6  表示的是产生0~5的整型值

（1+rand()%6）:表示1~6

srand()：函数种子

---

enum Status{CONTINUE,WON,LOST}

enum class Status{CONTINUE,WON,LOST}

Status::CONTINUE







