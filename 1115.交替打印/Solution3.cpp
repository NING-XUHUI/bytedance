#include <iostream>
#include <thread>
using namespace std;

class FooBar{
private:
    int n;
    int count = 1;
    std::condition_variable v;
    std::mutex Mu;
public:
    FooBar(int n):n(n){}
    void foo(function<void()> printFoo){
        for(int i = 0;i < n;i++){
            std::unique_lock<std::mutex> lk(Mu);
            v.wait(lk,[this](){return count==1;});
            printFoo();
            count++;
            v.notify_one();       
        } 
    }

    void bar(function<void()> printBar){
        for(int i = 0;i < n;i++){
            std::unique_lock<std::mutex> lk(Mu);
            v.wait(lk,[this](){return count==2;});
            printBar();
            count--;
            v.notify_one();       
        } 
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

