
Pass by Value - 
The call/pass by value method of passing arguments to a function copies the actual value of an argument into the formal parameter of the function. 
In this case, changes made to the parameter inside the function have no effect on the argument.
By default, C++ uses call by value to pass arguments. In general, this means that code within a function cannot alter the arguments used to call the function.

Pass by Reference - 
The call/pass by reference method of passing arguments to a function copies the reference of an argument into the formal parameter. 
Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the parameter affect the passed argument.
To pass the value by reference, argument reference is passed to the functions just like any other value.