#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#else
#define LIBLIST_GUARD
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "LibList.h"
#include "LibListAPI.h"
#include "LibListAPI_T.h"
#include "LibList.ListIt.c"
#include "LibList.List.c"
#undef T
#undef LIBLIST_GUARD
#endif
