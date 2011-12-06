#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListIt(T)
{
	T           data;
	ListIt(T) * previous;
	ListIt(T) * current;
	ListIt(T) * next;
};

#include "LibList.ListIt.Global.c"
#endif
