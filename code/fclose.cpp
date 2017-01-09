// exception example
#include <exception>  // std::exception
#include <iostream>   // std::cout

using namespace std;

class dummyFStream {
   public:
    dummyFStream(string name) : name(name) {
        cout << name << ".in" << endl;
        open();
    }
    ~dummyFStream() {
        cout << name << ".out" << endl;
        if (is_open) close();
    }
    void close() {
        is_open = false;
        cout << name << ".close()" << endl;
    }
    void open() {
        is_open = true;
        cout << name << ".open()" << endl;
    }

   private:
    bool is_open;
    string name;
};

int main() {
    dummyFStream fin("L0");

    try {
        dummyFStream fin("L1");
        throw 20;
    } catch (int e) {
        cout << "\t\texception caught No. " << e << '\n';
        cout << "return.." << endl;
        return 1;
        //	cou << "exit.." << endl; exit(1);
    }
    return 1;
}
