# (Fully) generic linked list

## Description

This code gives an sort-of implementation of the C++ `std::list` using only C features. It allows to have a ready-to-use linked list without using the ugly `void*` hack. It also means that you will not make type errors when assigning elements into the list : their types will be checked at compile-time.

The lists have iterators but, as opposed to C++'s implementation, those iterators are pointer objects. It means that you have to explicitely destroy them when you don't need them anymore.

Please note that this code has been made almost two years ago, I've simply translated the documentation in english after seing [another nice preprocessor-powered engine](https://github.com/orangeduck/CPP_COMPLETE) on the front page of HN. You can still make pull requests if you want to add features, I would be happy to discuss about it.

It uses some GCC preprocessing extensions (processor va_args), so I can't guarantee that it will compile on other compilers.

## API

**Note** There is a limitation on the 'Template parameter' : it has to be a single word. So, if you want to use an enumeration, you will have to typedef it :

    struct foo { int bar; };
    typedef struct foo foo_t;

It's because the preprocessor will mangle the type into the function names, so if there is a space ... well ... hell breaks loose.

### Declare a new list

Open a new header file (`.h`), and put it this code :

    #ifndef HEADER_NAME_H_     // guard
    # define HEADER_NAME_H_    // guard

    # include "TypeName.h"     // File containing type definition
    # define T TypeName        // 'Template parameter' (type name)
    # include "LibListAPI_T.h" // Inclusion of the list members declaration
    # undef T                  // We can now remove the template parameter

    #endif                     // guard

### Define a new list

Open a new source file (`.c`), and put it this code :

    #include "ListHeader.h"   // File containing the declaration of the list
    #define T TypeName        // 'Template parameter' (type name)
    #include "LibListAPI_T.c" // Inclusion of the list members definition (note the .c extension)
    #undef T                  // We can now remove the template parameter

### Use the list

Include in your source files your new header file, then use the following macro to call the functions :

    mixed ListAction(T, action, ...)

    T      : List type
    action : Method name
    ...    : Method parameters

You can check the main file (`LibListAPI.h`) for an exaustive list of the methods available in this library.

### Use iterators

Include in your source files your new header file, then use the following macro to call the iterator functions :

    mixed ListItAction(T, action, ...)

    T      : List type
    action : Method name
    ...    : Method parameters

You can check the main file (`LibListAPI.h`) for an exaustive list of the methods available in this library.

### Example

Please see the [main.c](https://github.com/arcanis/epitech.generic-linked-list/blob/master/demonstration/main.c) file to see a full example of the API usage.
