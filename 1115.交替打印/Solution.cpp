#include <iostream>
#include <thread>
using namespace std;

class FooBar{
private:
    int n;
    std::mutex m1;
    std::mutex m2;
public:
    FooBar(int n):n(n){
        m2.lock();
    }

    void foo(function<void()> printFoo){
        for(int i = 0;i < n;i++){
            m1.lock();
            printFoo();
            m2.unlock();
        }
    }
    void bar(function<void()> printBar){
        for(int i = 0;i < n;i++){
            m2.lock();
            printBar();
            m1.unlock();
        }
    } 
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

