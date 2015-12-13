Command Line Parameters
#######################

We all see that first line in the ``main`` function. We have memorized it and
typed it in dozens of times. But what does it all mean?

Let's take "Hello, World" apart, and see how it really works:

..  literalinclude::    ../src/main.cpp
    :caption:  main.cpp (line 1)
    :lines: 1

Standard Input/Output
*********************

This line tells the system to give us access to the standard C++ console
input/output system. We have access to ``cout`` and ``cin`` so our program can
communicate with us humans!

..  literalinclude::    ../src/main.cpp
    :caption: main.cpp (line 2)
    :lines: 2

Namespaces
**********

The standard I/O library routines are wrapped up in something C++ calls a
``namespace``. This is just a wrapper around code you write that makes it
possible for you to come up with variable and function names that might be the
same as those created by other programmers working on the same project. When
the compiler sees the same name twice in any program, it gets confused, so each
programmer can add a unique name in front at their particular version. 

For instance, I might decide to protect all of my program names by wrapping them
up in a wrapper protected by my first name (probably not a good choice in a
real project, it should be more descriptive, telling folks what this code is
all about):

..  literalinclude::    ../src/main.cpp
    :caption: main.cpp (lines 5-12 )
    :linenos:
    :lines: 5-12

Here, my protected name is "message", which is a function that takes the
command line parameters in and creates a C++ ``string`` with the program name.

You might be wondering about that messy ``msg`` assignment line. Formally, the
``argv`` variable handed to the program by the operating system is a "array of
pointers to C-Strings". These C-Strings are not the same kind of critters as
real C++ ``strings``. A C-String is just an array of characters sitting in
memory with a trailing byte containing all zero bits. Real C++ strings are
managed using a complex system that lets them grow to huge sizes if needed.
Because they are so different, we need to convert the C-String into a C++
string before we can add that thing to the message. The ``(string)`` notation
is called a C++ "cast", meaning convert one data type into another one. This
asks C++ to find a suitable method to do this trick, and there are many of
theses converters around. 

Using Protected Names
*********************

When you wrap up names in a ``namespace`` wrapper, you need to specify the
``namespace`` name when you refer to those names using the "Roie::message"
notation. All of the names in the ``iostream`` package are protected using the
``namespace`` name of ``std``. So, it we want to use ``cout``, normally, we need to
write ``std::cout``. Doing this a lot is a pain, so you can "unwrap" all those
names by adding the this line:

..  literalinclude::    ../src/main.cpp
    :caption: main.cpp (line 3)
    :lines: 3

Once that line has been seen by the compiler, it will look into that
``namespace`` to find a name that is missing the ``namefix`` prefix.  I have
not unwrapped my personal ``namespace``, so I still need to use the ``namespace``
notation.

Here is the complete program:

..  literalinclude::    ../src/main.cpp
    :caption: main.cpp (complete)

Does this make more sense now?

..  vim:filetype=rst spell:
