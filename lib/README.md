# Library / DataStructures

This folder contains the source files for the data structures you are building for this assignment. It is HIGHLY recommended that you test as you build each function. The tests are located in the `tests` folder, and are extremely extensive (though not complete/fully exhaustive).

> IMPORTANT  
> DO NOT write all your code at once and try to compile. It will be a nightmare. Instead, write a little at a time, and test as you go. This will make your life much easier.

## .c and .h files?

To use functions across multiple parts of your program, you need to declare them in a header file (`.h`), and define them in a source file (`.c`). The header file is included in the source file, and the source file is compiled into an object file (`.o`). The object files are then linked together to create the executable. It is also common to put defines and structs in the header file, but this is not required. For each of the data structures, you will see one header file, but you may see multiple source files as we break up the code into multiple files for readability. Make sure to look through the code. There is a lot, but you will only be asked to implement a small portion of it. This assignment is about seeking understanding, not writing code.

## Movie

The `movie` struct is defined in `movie.h` and `movie.c`. It contains a few helper functions most notably.

- `new_movie(const char* title, int id)` - creates a new movie struct. Ideally, there is more info, but this works for this experiment.
- `compare_movies(Movie *movie1, Movie *movie2)` - compares two movies based on their title and then id's if they have the same title. This is used for sorting and searching.
- `movie_to_str(Movie *movie)` - returns a string representation of the movie. This is used for printing.

## MovieVector/SortedMovieVector

A vector is a dynamic array. It is a contiguous block of memory that can grow and shrink as needed. The `MovieVector` struct is defined in `vector.h` and `vector.c`. It contains multiple helper functions.

The SortedMovieVector is defined in `vector.h` but implemented in `sorted_vector.c`. It is a vector that is always sorted. This is done by using the `add_to_sorted_vector` function. This function will add the movie to the vector in the correct location.

> **STUDENT TODO**  
> Everything in `vector.c` is implemented, but you will need to implement functions in `sorted_vector.c`. You may want to review binary search from 5001.

## LinkedList/SortedLinkedList

A linked list is a data structure that contains a series of nodes. Each node contains a value and a pointer to the next node. The `LinkedList` struct is defined in `linked_list.h` and `linked_list.c`. It contains multiple helper functions. The SortedLinkedList is defined in `linked_list.h` but implemented in `sorted_list.c`. It is a linked list that is always sorted. This is done by using the `add_to_sorted_list` function. This function will add the movie to the list in the correct location.

Nearly everything in SortedLinkedList is implemented using a linear search. This is because you cannot jump directly to a location easily, and one of the downsides of a linked list. Though it has the upside of not needing contiguous memory.

While a doubly linked list is more common due to a speed boost at removing items from either end, this assignment uses a singly linked list. This is because it is easier to implement. If you are careful, you would be free to modify the code to use a double linked list. Such modified code should pass the `tests/linked_list_tester.c` tests without extra modification of that code.

> **STUDENT TODO**
> You will implement **most** functions for LinkedList. The SortedLinkedList functions are already implemented to provide examples, but they are dependent on the LinkedList functions. This is the bulk of your programming requirement!

## BinarySearchTree

Starting during week two of this assignment, you will be looking at Binary Search Trees. They are a non-sequential way to store data. They are a tree data structure, and each node has two children. The left child is less than the parent, and the right child is greater than the parent. This allows for fast searching, and is a very common data structure. The `BST` struct is defined in `bst.h` and `bst.c`. It contains multiple helper functions. You will notice many of the functions are actually recursive along the nodes. This is because the tree is recursive in nature.

> **STUDENT TODO**
> Most of the functions are implemented, calling helper recursive functions. You will need to implement the recursive helpers. Make sure to look at the code and understand how it works, and return to your TeamActivity that has similar code required to be implemented.

## Reminder

Make sure to refer to TeamActivities and course lecture videos. They will help you understand the code and how to implement it. Also START early. This is a two week assignment, the first week focuses on coding, with the second week adding in BST and focusing on the report. Make sure to give yourself time.
