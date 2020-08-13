#include <iostream>
#include <thread>
using namespace std;

class FooBar{
private:
    int n;
    atomic<bool> fooed=false;

public:
    FooBar(int n){
        this->n=n;
    }

    void foo(function<void()> printFoo){
        for(int i = 0;i<n;i++){
            while(fooed.load())this_thread::yield();
                printFoo();
            fooed.store(true);
        }
    }

    void bar(function<void()> printBar){
        for(int i = 0;i<n;i++){
            while(!fooed.load())this_thread::yield();
                printBar();
            fooed.store(false);
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

