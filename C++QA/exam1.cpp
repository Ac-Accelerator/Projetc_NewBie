#include <iostream>
using namespace std;
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7
class CPU
{

public:
    int rank, frequency, vo;
    CPU(int, int, int);
    CPU();
    ~CPU();
    void showinfo();
    CPU(const CPU &obj);
};
CPU::CPU(int r, int f, int v)
{
    rank = r;
    frequency = f;
    vo = v;
    cout << "create a CPU!" << endl;
}
CPU::CPU()
{
    rank = 1;
    frequency = 2;
    vo = 100;
    cout << "create a CPU!" << endl;
}

CPU::~CPU()
{
    cout << "destruct a CPU!" << endl;
}

void CPU::showinfo()
{
    cout << "rank:" << rank << endl;
    cout << "frequency:" << frequency << endl;
    cout << "voltage:" << vo << endl;
}
CPU::CPU(const CPU &obj)
{
    cout << "copy create a CPU!" << endl;
    rank = obj.rank;
    frequency = obj.frequency;
    vo = obj.vo;
}
class RAM
{
private:
    /* data */
public:
    RAM(/* args */);
    ~RAM();
};

RAM::RAM(/* args */)
{
}

RAM::~RAM()
{
}
class CD
{
private:
    /* data */
public:
    CD(/* args */);
    ~CD();
};

CD::CD(/* args */)
{
}

CD::~CD()
{
}

class COMPUTER
{
private:
    CPU cpu;
    RAM ram;
    CD cd;

public:
    COMPUTER(int rank, int f, int v, int r, int s);
    COMPUTER(/* args */);
    ~COMPUTER();
    void run();
    void stop();
    void showinfo();
};

COMPUTER::COMPUTER(/* args */)
{
}
COMPUTER::COMPUTER(int ra, int f, int v, int r, int s)
{
    cpu.rank = ra;
    cpu.frequency = f;
    cpu.vo = v;

}
COMPUTER::~COMPUTER()
{
}
int main()
{
    COMPUTER cpt1(6, 4.0, 200, 60, 32); //测试带参数构造
    cout << "cpt1's parameter:" << endl;
    cpt1.showinfo();
    cout << "------------------------------" << endl;
    COMPUTER cpt2; //测试不带参数构造
    cout << "cpt2's parameter:" << endl;
    cpt2.showinfo();
    cout << "------------------------------" << endl;
    COMPUTER cpt3(cpt1); //测试复制构造
    cout << "cpt3's parameter:" << endl;
    cpt3.showinfo();
    cout << "------------------------------" << endl;
}