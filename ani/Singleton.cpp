#include <iostream>
#include <memory>
using namespace std;


class single
{
	static shared_ptr<single> object;
	single()
	{}
public:
	static shared_ptr<single> getInstance()
	{
		if(object == NULL)
		{
			object.reset(new single);
		}
		return object;
	}

	void Hello()
	{
		cout <<"Hello Threse:" <<endl;
	}


	~single()
	{
		cout<<"Object Destroyed"<<endl;
	}


};

 shared_ptr<single> single::object;

 class derived:public single
 {




 };



 int maine()
 {
	 shared_ptr<single> s = single ::getInstance();
	 shared_ptr<single> v = single ::getInstance();
	 s->Hello();
	 weak_ptr<single> weak = s;

	 cout << "Weak_count " << weak.use_count() << endl;
	 if(auto sp = weak.lock())
	 {
		 cout << "Shared Pointer" << sp.get()<< endl;
	 }
	 if(weak.expired() == true)
		cout << "Weak_count " << weak.use_count();



	 shared_ptr<int> t;
	 t.reset(new int);

	 weak_ptr<int> y = t;


	 t.reset(new int);

	 weak_ptr<int> z = t;


	 if(auto tmp = y.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak1 is expired\n";

    // weak2 points to new data (5)

    if(auto tmp = z.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak2 is expired\n";


	return 0;


 }