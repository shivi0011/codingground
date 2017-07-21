#include <iostream>

using namespace std;

class pwr
{
  int e;
  double b,val;
  public:
  pwr(double base, int exp);
  double get_pwr(){return val;}
};

/*defining parameterized constructor outside the class so need to tell the compiler about the class it 
belongs to so use :: operator */
pwr::pwr(double base, int exp)
{
    b = base;   //we can access member var (b and e) directly
    e = exp;
    val = 1;
    if(exp==0) return ;
    for(;exp>0;exp--)
        val = val * b;
}

/*With this pointer...both fns are equivalent asw this pointer is implicitly passed to all the member fn*/
/* THIS version of the same fn
pwr::pwr(double base, int exp)
{
    this->b = base;   //we can access member var (b and e) directly
    this->e = exp;
    this->val = 1;
    if(exp==0) return ;
    for(;exp>0;exp--)
        this->val = this->val * this->b;
}
*/

int main()
{
    /*creating 3 obj n passing parameteres to them. At this time these 3 obj will have separate copy*/
    /*of all the member variables of the class*/
   pwr x(4.0,2), y(2.5,1), z(5.7,0);
   
   cout<< x.get_pwr()<<endl;
   cout<< y.get_pwr()<<endl;
   cout<< z.get_pwr()<<endl;
   return 0;
}

/*:::::::::::::Points to remember:::::::::::*/
/*Friend functions are not members of the class, therefore they dont pass THIS pointer.*/
/*Static member function do not have a THIS pointer.*/
