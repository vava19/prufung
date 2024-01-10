you.eat(apple);

--
This makes it clearer who the subject is (you), what behavior is being invoked (eat()), 
and what objects are accessories to that behavior (apple).
Because the properties and behaviors are no longer separate, objects are easier to modularize,
 which makes our programs easier to write and understand,
 and also provides a higher degree of code reusability. 
 These objects also provide a more intuitive way to work 
 with our data by allowing us to define how
  we interact with the objects, and how they interact with other objects.

  -------------------


#include <iostream>
#include <string>

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main()
{
    Person joe{ "Joe", 29 };
    Person kate{ "Kate", 27 };

    joe.kisses(kate);

    return 0;
}
---
oe kisses Kate
Let’s examine how this works. First, we define two Person structs, joe and kate.
 Next, we call joe.kisses(kate). joe is the implicit object here,
  and kate is passed as an explicit argument.

When the kisses() member function executes, the identifier name doesn’t 
use the member selection operator (.), so it refers to the implicit object, 
which is joe. So this resolves to joe.name. person.name uses the member 
selection operator, so it does not refer to the implicit object.
 Since person is a reference for kate, this resolves to kate.name.


----------------------------------

  It is possible to create class types with no data members 
  (e.g. class types that only have member functions). 
  It is also possible to instantiate objects of such a class type:

#include <iostream>

struct Foo
{
    void printHi() { std::cout << "Hi!\n"; }
};

int main()
{
    Foo f{};
    f.printHi(); // requires object to call

    return 0;
}
However, if a class type does not have any data members, 
then using a class type is probably overkill. In such cases, 
consider using a namespace (containing non-member functions) instead. 
This makes it clearer to the reader that no data is being managed 
(and does not require an object to be instantiated to call the functions).


#include <iostream>

namespace Foo
{
    void printHi() { std::cout << "Hi!\n"; }
};

int main()
{
    Foo::printHi(); // no object needed

    return 0;
}

--------------------------

Best practice

If your class type has no data members, prefer using a namespace.

------------------------------


-- Best practice

Classes should generally make member variables private (or protected),
 and member functions public.
Structs should generally avoid using access specifiers 
(all members will default to public).

--------------------


However, as soon as we make any member variables private (to hide our data), our class type is no longer an aggregate (because aggregates cannot have private members). And that means we’re no longer able to use aggregate initialization:

class Foo // Foo is not an aggregate (has private members)
{
    int m_x {};
    int m_y {};
};

int main()
{
    Foo foo { 6, 7 }; // compile error: can not use aggregate initialization

    return 0;
}
-------

Not allowing class types with private members to be initialized via aggregate initialization makes sense for a number of reasons:

Aggregate initialization requires knowing about the implementation of the class (since you have to know what the members are, and what order they were defined in), 
which we’re intentionally trying to avoid when we hide our data members.
If our class had some kind of invariant, we’d be relying on the user to initialize the class in a way that preserves the invariant.
So then how do we initialize a class with private member variables? The error message given by the compiler
 for the prior example provides a clue: “error: no matching constructor for initialization of ‘Foo'""

We must need a matching constructor. But what the heck is that? '


------------------

Constructors vs setters

Constructors are designed to initialize an entire object at the point of instantiation. 
Setters are designed to assign a value to a single member of an existing object.

-------------------


Value initialization vs default initialization for class types
--
Foo foo{}; // value initialization, calls Foo() default constructor
Foo foo2;  // default initialization, calls Foo() default constructor

----
Best practice

Prefer value initialization over default initialization for all class types.


-------

Overloaded constructors

Because constructors are functions, they can be overloaded. That is, we can have multiple constructors so that we can construct objects in different ways:


-------------

This class has no user-declared constructors, so the compiler will generate
 an implicit default constructor for us. That constructor will be used to instantiate foo{}.
The implicit default constructor is equivalent to a constructor that has no parameters,
 no member initializer list, and no statements in the body of the constructor. 
 In other words, for the above Foo class, the compiler generates this:

public:
    Foo() // implicitly generated default constructor
    {
    }

-----------------------

or like this:
-------
 Foo() = default; // generate an implicit default constructor

----------------------------

