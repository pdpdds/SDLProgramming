#include <iostream>
#include <sigc++/sigc++.h>
#include <string>

#ifdef _DEBUG
#pragma comment(lib, "sigc++.lib")
#else
#pragma comment(lib, "libsigc++1.2-vc6.lib")
#endif

class Concatenator
{
public:
    typedef std::string OutType;
    typedef std::string InType;

    Concatenator() {};

    OutType value()
    {
        return m_Result;
    }

    static OutType default_value()
    {
        return "";
    }

    bool marshal(InType str)
    {
        m_Result += str;

        return false;
    }
private:
    std::string m_Result;
};

class Worker
{
public:
	void LongOperation()
    {
		// Do a long operation here
		std::string result = m_SignalFinished.emit();
		std::cout << result << std::endl;
    }

    SigC::Signal0<std::string, Concatenator> m_SignalFinished;
};

class Notifier : public SigC::Object
{
public:
	Notifier(std::string str)
		: m_String(str)
	{}

	std::string LongOperationFinished()
    {
        std::cout << "Worker 1 is finished!" << std::endl;
		return m_String;
	}
	std::string m_String;
};

int main(int argc, char* argv[])
{
    Notifier notifier1("Hello");
    Notifier notifier2("World");
    Worker worker;

    worker.m_SignalFinished.connect(SigC::slot(notifier1, &Notifier::LongOperationFinished));
    worker.m_SignalFinished.connect(SigC::slot(notifier2, &Notifier::LongOperationFinished));

    worker.LongOperation();

	return 0;
}
