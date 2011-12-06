#ifndef LIBLIST_H_
#define LIBLIST_H_

/*
** Ces deux macros permettent de maintenir un typage correct
** (donc de s'abstraire du void * classique), tout en laissant
** au moteur de génération de code un plein accès aux données
** membres.
**
** Vous noterez que la définition de ces structures n'est pas
** dans ce fichier : les applications n'ont pas besoin de les
** connaitre, car ils ne manipuleront que des pointeurs sur
** elles. Cette technique est censée avoir un nom, mais celui
** que j'avais en tête ne trouve aucun résultat sur Google. Je
** pense que je vais vous laisser le soin de chercher. :)
*/

#define ListIndirection(T)   struct List##T
#define ListItIndirection(T) struct List##T##It

#define List(T)              ListIndirection(T)
#define ListIt(T)            ListItIndirection(T)

#endif
