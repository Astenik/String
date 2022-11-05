#include <iostream>

#include "String.h"

int main()
{
    String ob;
    ob.add_symbol('a');
    ob.add_symbol('s');
    ob.add_symbol('t');
    print(ob);
    
    String ob1(ob);
    ob1.add_symbol('e');
    ob1.add_symbol('n');
    print(ob1);
    
    String ob2;
    ob2.add_symbol('i');
    ob2.add_symbol('k');
    print(ob2);
    
    std::cout << ob.find_char('a') << ob.find_char('s') << ob.find_char('t') << std::endl;
    std::cout << ob2.find_substr(ob) << std::endl; // !!!!!!!
    
    String ob3;
    ob3 = ob1 + ob2; 
    print(ob3);
    
    return 0;
}
