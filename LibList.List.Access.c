#if !defined(T)
#error "Vous DEVEZ définir la constante T avant d'inclure le module de LibList."
#elif !defined(LIBLIST_GUARD)
#error "Ce fichier doit être inclu par LibList.c. Vous ne devez pas l'inclure vous-même."
#else

ListRequire(T, front)
{
	return (ListItAction(T, unref, l->first));
}

ListRequire(T, back)
{
	return (ListItAction(T, unref, l->last));
}

#endif
