#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListRequire(T, reverse)
{
	ListIt(T) * ptr;
	ListIt(T) * old;
	ListIt(T) * next;

	old = NULL;
	ptr = l->first;
	while (ptr)
		{
			if (old)
				old->previous = ptr;
			next = ptr->next;
			ptr->next = old;
			old = ptr;
			ptr = next;
		}
	old = l->first;
	l->first = l->last;
	l->last = old;
	if (l->first)
		l->first->previous = NULL;
	if (l->last)
		l->last->next = NULL;
}

ListRequire(T, remove)
{
	T           temp;
	ListIt(T) * it;
	ListIt(T) * end;

	it = ListAction(T, begin, l);
	end = ListAction(T, end, l);
	while (ListItAction(T, neq, it, end))
		{
			temp = ListItAction(T, unref, it);
			if (!memcmp(&temp, &d, sizeof(T)))
				ListAction(T, erase, l, it, NULL);
			else
				ListItAction(T, inc, it);
		}
	ListItAction(T, del, it);
	ListItAction(T, del, end);
}

ListRequire(T, remove_if)
{
	ListIt(T) * it;
	ListIt(T) * end;

	it = ListAction(T, begin, l);
	end = ListAction(T, end, l);
	while (ListItAction(T, neq, it, end))
		if (p(ListItAction(T, unref, it)))
			ListAction(T, erase, l, it, NULL);
		else
			ListItAction(T, inc, it);
	ListItAction(T, del, it);
	ListItAction(T, del, end);
}

#endif
