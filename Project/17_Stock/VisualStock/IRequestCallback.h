#ifndef __IREQUEST_CALLBACK_H__
#define __IREQUEST_CALLBACK_H__

class IRequestCallback
{
public:
	virtual void OnResult(char* szMessage) = 0;
};

#endif