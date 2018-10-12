#include "OriginalClass.h"

OriginalClass::OriginalClass(NewerClass b)
{
	myVal = b.bsMyVal;
}
OriginalClass::OriginalClass() { }
OriginalClass::~OriginalClass() { }