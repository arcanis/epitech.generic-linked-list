#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListRequire(T, new)
{
	List(T) * ptr;

	ptr = malloc(sizeof(*ptr));
	assert(ptr != NULL);
	ptr->length = 0;
	ptr->first = NULL;
	ptr->last = NULL;
	return (ptr);
}

ListRequire(T, del)
{
	if (!l)
		return ;
	ListAction(T, clear, l);
	free(l);
}

#endif
