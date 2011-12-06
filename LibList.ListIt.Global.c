#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListItRequire(T, new)
{
	ListIt(T) * ptr;

	ptr = malloc(sizeof(*ptr));
	assert(ptr != NULL);
	ptr->previous = NULL;
	ptr->current = ptr;
	ptr->next = NULL;
	return (ptr);
}

ListItRequire(T, copy)
{
	ListIt(T) * ptr;

	ptr = malloc(sizeof(*ptr));
	assert(ptr != NULL);
	*ptr = *li;
	return (ptr);
}

ListItRequire(T, del)
{
	free(li);
}

ListItRequire(T, unref)
{
	return (li->current->data);
}

ListItRequire(T, inc)
{
	li->previous = li->current;
	li->current = li->next;
	li->next = li->next ? li->next->next : NULL;
}

ListItRequire(T, dec)
{
	li->next = li->current;
	li->current = li->previous;
	li->previous = li->previous->previous;
}

ListItRequire(T, eq)
{
	return (liA->current == liB->current);
}

ListItRequire(T, neq)
{
	return (liA->current != liB->current);
}

#endif
