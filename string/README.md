# string_implementation

<hr>

Strings are objects that represent sequences of characters.
My string is in ams namespace.

---------------------------------------------------------------------
The implemented string functions
---------------------------------------------------------------------
   lenght()   -> function to get lenght of string
   
   size()     -> function to get size of string 
   
   capacity() -> function to get capacity of string
   
   char* data() -> function returns string data
   
   push_back(char) ->function for adding one element to the string
   
   empty() -> function to check if the string is empty
   
   clear() -> clear the string, size = 0; capacity stays the same
   
   pop_back() -> function to remove the last element of the string
   
   append(const char*) -> function to add char* to the end of the string
   
   append(const char*, size_t) -> function to add given part of char* to the end of the string
   
   insert(size_t, const char*) -> insert char* where user wants
   
   insert(size_t, const char*, int) -> insert part of char* wher user wants
   
   erase() -> same as clear()
   
   erase(size_t) -> erase from the given position
   
   erase(size_t, size_t) -> erase from the given position1 to the given position2
   
   resize(size_t, const char) -> resize the string, cut it or make it bigger and initialize with given char symbol
   
   resize(size_t) -> resize the string into smaller one or dont do anything
   
   back()  -> returns the last character of the string
   
   front() ->return the first character of the string
   
   replace(size_t, size_t, char*) -> position is the first given integer, then function replace takes given part(second integer) of the string and     
             replaces it with the third parameter char*
             
   find(char) -> function returns the first appearance of the given symbol
   
   ind(char*) -> function returns the first appearance of the given char*
   
   swap(string&) -> function swaps to strings
   
   substr(size_t, size_t) -> return the string which includes (second parameter) characters from the (first parameter) index;
   
   compare(string&) -> compare two strings
   
   <hr>
