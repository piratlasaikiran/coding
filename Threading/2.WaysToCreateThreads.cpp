#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// 1.Standard way
void fun(int x){
    while(x-- > 0)
        cout << x << endl;
}

// lambda
/*   auto fun = [](int x){
        while(x-- > 0)
            cout << x << endl;
    }
*/

//functr
class Base
{
public:
    void operator()(int x){
        while(x-- >0)
            cout << x << endl;
    }
};

//non static member function
class Base4
{
public:
    void operator4(int x){
        while(x-- >0)
            cout << x << endl;
    }
};

//static member function
class Base5
{
public:
    static void operator5(int x){
        while(x-- >0)
            cout << x << endl;
    }
};


int main(){
    // traditional way
    thread t1(fun, 10);

    // lambda
    thread t2([](int x){
        while(x-- > 0)
            cout << x << endl;}, 10);

    // functr
    thread t3((Base()), 10);

    //non static member function
    Base4 b4;
    thread t4(&Base4::operator4, &b4, 10);

    //static member function
    thread t5(&Base5::operator5, 10);



    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;

    // FUnctor
}