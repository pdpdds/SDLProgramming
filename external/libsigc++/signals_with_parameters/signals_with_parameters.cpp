#include <iostream>
#include <string>
#include <sigc++/sigc++.h>

#ifdef _DEBUG
#pragma comment(lib, "sigc++.lib")
#else
#pragma comment(lib, "libsigc++1.2-vc6.lib")
#endif

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

class Notifier : public SigC::Object
{
public:
    void LongOperationFinished(std::string str)
    {
        std::cout << "Worker is finished!" << std::endl;
        std::cout << "The argument is: " << str << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Notifier notifier;
    Worker worker;

    worker.m_SignalFinished.connect(SigC::slot(notifier, &Notifier::LongOperationFinished));

    worker.LongOperation();

    return 0;
}
