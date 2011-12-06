#ifndef TOTOLIST_H_
#define TOTOLIST_H_

#include "Toto.h"
#define T TotoPtr
#include "LibListAPI_T.h"

#define LIST     List(TotoPtr) *
#define ITERATOR ListIt(TotoPtr) *
typedef LIST     TotoListPtr;
typedef ITERATOR TotoListIterator;

#endif
