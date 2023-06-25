void initialize(stack* s); // initializes an empty stack. 
int push(stack* s, char value); //pushes the char value to the stack 
int isEmpty(stack* s); // Returns 1 if the stack is empty, 0 otherwise. 
char pop(stack* s); // pops and returns character at the top of the stack.
char peek(stack* s); // returns character at the top of the stack.

int isPalindrome(char *str) 
{     
    struct stack s; // Declare a stack  
    initialize(&s); // Initialize the stack 
    int len = strlen(str); // Get the length of the string
    
    for (int i=0; i<len/2; i++)  // Iterate through the first half of the string        
        push(&s, str[i]);     // Push each character onto the stack 
    for (int i=len-len/2; i<len; i++) // Iterate through the second half of the string 
        if (pop(&s) != str[i])  // Compare each character with the corresponding popped character from the stack
            return 0;  // Not a palindrome, return 0
    
    return 1;  // Palindrome, return 1
} 