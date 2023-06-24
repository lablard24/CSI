
typedef struct node { 
    int data; 
    struct node* next; 
} node;

void insertAfterN(node* head, int M, int N) 
{  
    // Check if the head is NULL (empty list)
    if (head == NULL) {
        return; // Base case: reached the end of the list
    }  

    // Check if the head's data matches the target value N
    if (head->data == N) 
    {         
        // Create a new node
        node* tmp = malloc(sizeof(node));         
        tmp->data = M; 
        // Update the links to insert the new node        
        tmp->next = head->next;         
        head->next = tmp;  
        // Update the head pointer to the newly inserted node      
        head = tmp;     
    }   
        // Recursively call the function for the next node
        insertAfterN(head->next, M, N);    
} 