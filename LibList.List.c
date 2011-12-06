#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

List(T)
{
	size_t      length;
	ListIt(T) * first;
	ListIt(T) * last;
};

#include "LibList.List.Global.c"
#include "LibList.List.Iterators.c"
#include "LibList.List.Capacity.c"
#include "LibList.List.Access.c"
#include "LibList.List.Modifiers.c"
#include "LibList.List.Operations.c"
#endif
