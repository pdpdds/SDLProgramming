#include <iostream>
#include <string>
#include <sigc++/sigc++.h>

#ifdef _DEBUG
#pragma comment(lib, "sigc++.lib")
#else
#pragma comment(lib, "libsigc++1.2-vc6.lib")
#endif

void notifierfunction(std::string str)
{
    std::cout << "Worker is finished!" << std::endl;
    std::cout << "The argument is: " << str << std::endl;
}

class Worker
{
public:
    void LongOperation()
    {
        // Do a long operation here
        m_SignalFinished.emit("I'm finished!");
    }

    SigC::Signal1<void, std::string> m_SignalFinished;
};

int main(int argc, char* argv[])
{
    Worker worker;

    worker.m_SignalFinished.connect(SigC::slot(notifierfunction));

    worker.LongOperation();

    return 0;
}