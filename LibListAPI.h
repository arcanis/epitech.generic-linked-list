#ifndef LIBLISTAPI_H_
#define LIBLISTAPI_H_

/*
** __ Note à qui lira ceci __
**
** Il aurait été possible de pousser plus loin le vice, et de simuler
** le concept d'héritage (voire d'interface) en utilisant la puissance
** du préprocesseur à son maximum.
**
** Cependant, n'étant ni masochiste ni particulièrement stakhanoviste,
** je ne m'étends ici pas sur cette possibilité. Simuler les templates
** (à un niveau pourtant simple) est déjà assez compliqué ainsi.
**
** Et puis ça ferait plein de dépendances ! ... Ok. J'ai rien dit.
**
**                                                          -- Arcanis
**                                                                2011
*/

#include "LibList.h"

/*
** Fonctions devant être implémentées pour la gestion des listes.
** Elles sont en partie basées sur l'implémentation C++ du std::list,
** quoiqu'à un niveau évidemment beaucoup plus modeste.
*/

#define LIST_PROTOTYPE_new(T, name)        List(T) *   name(void)
#define LIST_PROTOTYPE_del(T, name)        void        name(List(T) * l)

// Iterateurs
#define LIST_PROTOTYPE_begin(T, name)      ListIt(T) * name(List(T) * l)
#define LIST_PROTOTYPE_end(T, name)        ListIt(T) * name(List(T) * l)

// Capacité
#define LIST_PROTOTYPE_empty(T, name)      char        name(List(T) * l)
#define LIST_PROTOTYPE_size(T, name)       size_t      name(List(T) * l)

// Accès aux éléments
#define LIST_PROTOTYPE_front(T, name)      T           name(List(T) * l)
#define LIST_PROTOTYPE_back(T, name)       T           name(List(T) * l)

// Modificateurs
#define LIST_PROTOTYPE_push_front(T, name) void        name(List(T) * l, T t)
#define LIST_PROTOTYPE_pop_front(T, name)  void        name(List(T) * l)
#define LIST_PROTOTYPE_push_back(T, name)  void        name(List(T) * l, T t)
#define LIST_PROTOTYPE_pop_back(T, name)   void        name(List(T) * l)
#define LIST_PROTOTYPE_clear(T, name)      void        name(List(T) * l)
#define LIST_PROTOTYPE_swap(T, name)       void        name(List(T) * lA, List(T) * lB)
#define LIST_PROTOTYPE_erase(T, name)      void        name(List(T) * l, ListIt(T) * liA, ListIt(T) * liB)

// Opérations
#define LIST_PROTOTYPE_reverse(T, name)    void        name(List(T) * l)
#define LIST_PROTOTYPE_remove(T, name)     void        name(List(T) * l, T d)
#define LIST_PROTOTYPE_remove_if(T, name)  void        name(List(T) * l, char (*p)(T))

/*
** Fonctions opérants sur des itérateurs.
** Encore une fois, la documentation C++ peut permettre de mieux comprendre
** leur fonctionnement interne.
**
** Comme particularité, on notera que les méthodes `inc' et `dec' prennent en
** paramètre un pointeur sur un itérateur, et non un itérateur proprement dit.
** L'alternative était de retourner un nouvel itérateur, mais je trouve que la
** sémantique de l'opérateur ++ et -- devrait être conservée.
*/

#define LISTIT_PROTOTYPE_new(T, name)   ListIt(T) * name(void)
#define LISTIT_PROTOTYPE_copy(T, name)  ListIt(T) * name(ListIt(T) * li)
#define LISTIT_PROTOTYPE_del(T, name)   void        name(ListIt(T) * li)
#define LISTIT_PROTOTYPE_unref(T, name) T           name(ListIt(T) * li)
#define LISTIT_PROTOTYPE_inc(T, name)   void        name(ListIt(T) * li)
#define LISTIT_PROTOTYPE_dec(T, name)   void        name(ListIt(T) * li)
#define LISTIT_PROTOTYPE_eq(T, name)    char        name(ListIt(T) * liA, ListIt(T) * liB)
#define LISTIT_PROTOTYPE_neq(T, name)   char        name(ListIt(T) * liA, ListIt(T) * liB)

/*
** Deux niveaux d'indirection sont requis pour que la bonne macro soit
** appelée, dans le cas du prototyping. Une fois pour récupérer le nom
** de la macro de l'action, et une fois pour l'appeler.
**
** Vous aurez remarqué que le mangling foirera si, par malheur, votre
** type contient des espaces. Donc ne faites pas de const char *, ni
** de struct toto, ou au minimum typedef'ez-les.
*/

// Objet liste
#define LIST_PROTOTYPE_3(T, name, macro)    macro(T, name)
#define LIST_PROTOTYPE_2(T, name, ident)    LIST_PROTOTYPE_3(T, name, ident)
#define LIST_PROTOTYPE_1(T, name, action)   LIST_PROTOTYPE_2(T, name, LIST_PROTOTYPE_##action)

#define LIST_MANGLING(T, action)            list_##T##_##action

// Itérateurs
#define LISTIT_PROTOTYPE_3(T, name, macro)  macro(T, name)
#define LISTIT_PROTOTYPE_2(T, name, ident)  LISTIT_PROTOTYPE_3(T, name, ident)
#define LISTIT_PROTOTYPE_1(T, name, action) LISTIT_PROTOTYPE_2(T, name, LISTIT_PROTOTYPE_##action)

#define LISTIT_MANGLING(T, action)          listIt_##T##_##action

/*
** Macros employées par les fichiers des applications.
** Require charge un prototype pour un type donné, tandis qu'Action exécute
** la fonction associée.
** Ces deux fonctions se contentent en réalité de faire un mangling du nom
** des fonctions basiques, en y intégrant le nom du type (T).
**
** C'est au final extrèmement verbueux, et j'en suis désolé, mais il s'agit de la
** seule façon que j'ai trouvé de permettre de faire ceci, excepté faire un define
** avant l'include.
**
** Cette dernière option aurait eu deux effets négatifs : il y aurait eu beaucoup
** moins de macros (ç'aurait été dommage !), et le fichier n'aurait pas pu être
** protégé contre la double inclusion (afin de permettre l'utilisation de plusieurs
** types de listes simultanément).
*/

#define ListRequire(T, action)       LIST_PROTOTYPE_1(T, LIST_MANGLING(T, action), action)
#define ListAction(T, action, ...)   LIST_MANGLING(T, action)(__VA_ARGS__)

#define ListItRequire(T, action)     LISTIT_PROTOTYPE_1(T, LISTIT_MANGLING(T, action), action)
#define ListItAction(T, action, ...) LISTIT_MANGLING(T, action)(__VA_ARGS__)

#endif
