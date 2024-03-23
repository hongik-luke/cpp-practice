#ifndef cal_h
#define cal_h

class Calculator{
    int num1,num2;
    string ob;
public:
    void setvalue(int a, int b);
    void setob(string ob);
    int Calculate();
};

#endif