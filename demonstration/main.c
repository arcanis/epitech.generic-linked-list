/*
** Note : Oui, ça leak.
** Allez tous mourir.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Toto.h"
#include "TotoList.h"

void print(TotoPtr toto)
{
    printf("Toto : a[%d]\n", toto->a);
}

void dump(TotoListPtr list)
{
    TotoListIterator it;
    TotoListIterator end;

    printf("\n");
    printf("Size : %d\n", ListAction(TotoPtr, size, list));
    it = ListAction(TotoPtr, begin, list);
    end = ListAction(TotoPtr, end, list);
    while (ListItAction(TotoPtr, neq, it, end))
    {
        print(ListItAction(TotoPtr, unref, it));
        ListItAction(TotoPtr, inc, it);
    }
    ListItAction(TotoPtr, del, it);
    ListItAction(TotoPtr, del, end);
}

void populate(TotoListPtr list, long count, long val)
{
    TotoPtr toto;
    int     x = 0;

    printf("\n");
    printf("Populate test with %ld elements, starting at %ld\n", count, val);
    while (x++ < count)
    {
        toto = malloc(sizeof(*toto));
        toto->a = val++;
        ListAction(TotoPtr, push_back, list, toto);
    }
}

int main(int argc, char * argv[])
{
    long             count, init;
    TotoListPtr      list = ListAction(TotoPtr, new);
    TotoListIterator it1, it2;

    if (argc < 2)
        return fprintf(stderr, "Usage: %s count value\n", argv[0]), EXIT_FAILURE;

    count = strtol(argv[1], NULL, 0);
    init = strtol(argv[2], NULL, 0);
    if (count <= 2)
        return fprintf(stderr, "Count value must be greater than 2.\n"), EXIT_FAILURE;

    printf("C TEMPLATED-LIKE LINKED LIST\n");

    // Remplissage de la liste
    populate(list, count, init);
    dump(list);

    // Renversement des valeurs de la liste
    ListAction(TotoPtr, reverse, list);
    dump(list);

    // On supprime tout, sauf le deuxième élément
    it1 = ListAction(TotoPtr, begin, list);
    it2 = ListAction(TotoPtr, end, list);
    ListAction(TotoPtr, erase, list, it1, NULL);
    ListItAction(TotoPtr, inc, it1);
    ListAction(TotoPtr, erase, list, it1, it2);
    ListItAction(TotoPtr, del, it1);
    ListItAction(TotoPtr, del, it2);
    dump(list);

    // Vidage total de la liste
    ListAction(TotoPtr, clear, list);
    dump(list);

    // Rajout de quelques données
    populate(list, 15, 1);
    dump(list);

    // Suppression de tout les nombres entre 4 et 13 compris
    char predicate(TotoPtr t) { return t->a >= 4 && t->a <= 13; }
    ListAction(TotoPtr, remove_if, list, &predicate);
    dump(list);

    return (EXIT_SUCCESS);
}
