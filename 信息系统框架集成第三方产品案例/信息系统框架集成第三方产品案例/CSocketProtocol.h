#include<iostream>


class CSocketProtocol
{
public:
	virtual void cltSocketInit() = 0;
	virtual int cltSocketSend(unsigned char *buf,int buflen) = 0;
	virtual int cltSocketRev(unsigned char *buf,int *buflen) = 0;
	virtual int cltSocketDestory() = 0;
};