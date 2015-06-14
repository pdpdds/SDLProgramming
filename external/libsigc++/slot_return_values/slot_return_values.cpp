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
        int result = m_SignalFinished.emit();
        std::cout << result << std::endl;
    }

    SigC::Signal0<int> m_SignalFinished;
};

class Notifier : public SigC::Object
{
public:
    int LongOperationFinished()
    {
        std::cout << "Worker is finished!" << std::endl;
        return 5;
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

