#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListRequire(T, push_front)
{
	ListIt(T) * ptr;

	ptr = ListItAction(T, new);
	ptr->data = t;
	ptr->previous = NULL;
	ptr->next = l->first;
	if (l->first)
		l->first->previous = ptr;
	else
		l->last = ptr;
	l->first = ptr;
	++l->length;
}

ListRequire(T, pop_front)
{
	ListIt(T) * ptr;

	if (!l->first)
		return ;
	ptr = l->first;
	l->first = ptr->next;
	if (l->first)
		l->first->previous = NULL;
	else
		l->last = NULL;
	ListItAction(T, del, ptr);
	--l->length;
}

ListRequire(T, push_back)
{
	ListIt(T) * ptr;

	ptr = ListItAction(T, new);
	ptr->data = t;
	ptr->previous = l->last;
	ptr->next = NULL;
	if (l->last)
		l->last->next = ptr;
	else
		l->first = ptr;
	l->last = ptr;
	++l->length;
}

ListRequire(T, pop_back)
{
	ListIt(T) * ptr;

	if (!l->last)
		return ;
	ptr = l->last;
	l->last = ptr->previous;
	if (l->last)
		l->last->next = NULL;
	else
		l->first = NULL;
	ListItAction(T, del, ptr);
	--l->length;
}

ListRequire(T, clear)
{
	ListIt(T) * ptr;
	ListIt(T) * next;

	ptr = l->first;
	while (ptr)
		{
			next = ptr->next;
			ListItAction(T, del, ptr);
			ptr = next;
		}
	l->first = NULL;
	l->last = NULL;
	l->length = 0;
}

ListRequire(T, swap)
{
	List(T) temp;

	temp = *lA;
	*lA = *lB;
	*lB = temp;
}

ListRequire(T, erase)
{
	ListIt(T) * ptr;

	if (liB)
		while (ListItAction(T, neq, liA, liB))
			ListAction(T, erase, l, liA, NULL);
	else
		{
			if (liA->previous)
				liA->previous->next = liA->next;
			else
				l->first = liA->next;
			if (liA->next)
				liA->next->previous = liA->previous;
			else
				l->last = liA->previous;
			ptr = liA->current;
			liA->current = liA->next;
			free(ptr);
			liA->next = liA->next ? liA->next->next : NULL;
			--l->length;
		}
}

#endif
