#include"CSocketProtocol.h"


class CSckFactoryImp1 : public CSocketProtocol
{
public:
	void cltSocketInit();
	int cltSocketSend(unsigned char *buf, int buflen);
	int cltSocketRev(unsigned char *buf, int *buflen);
	int cltSocketDestory();
private:
	unsigned char *p;
	int len;
};