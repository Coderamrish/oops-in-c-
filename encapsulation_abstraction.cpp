/*

1: What is the const keyword in Classes, Create a Customer class and Use Const in it.
2: What is the difference between Encapsulation and Abstraction

In object-oriented programming (OOP), the  keyword is primarily used to define read-only entities whose values or states cannot be modified after initialization. [1, 2]  
1. The  Keyword in Classes 
In the context of classes,  serves two main purposes: 

• Constant Data Members: These are variables within a class that must be initialized when created and cannot be changed throughout the object's lifetime. 
• Constant Member Functions (Methods): These are functions that promise not to modify any data members of the class. They are essentially "read-only" methods. [3, 4, 5, 6, 7]  

Example: Customer Class (C++) Below is a standard implementation of a  class using the  keyword for both a data member and a method. [8]  
2. Encapsulation vs. Abstraction 
While both concepts involve hiding information, they operate at different levels of the development process. [9, 10]  

| Feature [9, 10, 11, 12, 13, 14, 15, 16] | Encapsulation | Abstraction  |
| --- | --- | --- |
| Focus | How it is done (Implementation). | What it does (Interface).  |
| Purpose | To protect data integrity by grouping it with methods and restricting direct access. | To reduce complexity by hiding unnecessary details from the user.  |
| Level | Implementation level: Hiding data inside a class using  or  modifiers. | Design level: Showing only essential features through abstract classes or interfaces.  |
| Analogy | A medical capsule: You see the outer shell, but the complex mix of medicine inside is hidden and protected. | A TV remote: You only see the buttons (Volume, Power) but don't need to know how the internal circuitry works to use them.  |

Summary: Abstraction is about hiding unnecessary details to simplify the interface, whereas Encapsulation is about hiding data to ensure safety and security. [16, 17]  

*/
