/*
** Vous noterez que ce fichier n'est pas protégé contre la double inclusion.
** Autrement dit, il doit être manipulé avec prudence (par exemple en étant
** inclu dans un autre header, protégé cette fois par une garde).
*/

#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#else

#include "LibList.h"
#include "LibListAPI.h"

List(T);
ListIt(T);

ListRequire(T, new);
ListRequire(T, del);

ListRequire(T, begin);
ListRequire(T, end);

ListRequire(T, empty);
ListRequire(T, size);

ListRequire(T, front);
ListRequire(T, back);

ListRequire(T, push_front);
ListRequire(T, pop_front);
ListRequire(T, push_back);
ListRequire(T, pop_back);
ListRequire(T, clear);
ListRequire(T, swap);
ListRequire(T, erase);

ListRequire(T, remove);
ListRequire(T, remove_if);
ListRequire(T, reverse);

ListItRequire(T, new);
ListItRequire(T, del);
ListItRequire(T, unref);
ListItRequire(T, inc);
ListItRequire(T, del);
ListItRequire(T, eq);
ListItRequire(T, neq);

#endif
