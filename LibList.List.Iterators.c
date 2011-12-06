#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d\'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListRequire(T, begin)
{
	if (!(l->first))
		return (ListAction(T, end, l));
	return (ListItAction(T, copy, l->first));
}

ListRequire(T, end)
{
	ListIt(T) * ptr;

	ptr = ListItAction(T, new);
	ptr->previous = l->last;
	ptr->current = NULL;
	ptr->next = NULL;
	return (ptr);
}

#endif
