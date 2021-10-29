#include "linkedList.h"                        // Header for linkedList data structure

void scanfPlusPlus(int * elementAddress) {
    scanf("%d",elementAddress);                // Take integer from standard input
    while ((getchar()) != '\n');               // Flush the standard input buffer
 }

 void printfPlusPlus(char * printMessage) {
    printf(printMessage);                      // Print Message to  standard output
    printf("\n");                              // Change to new line
 }

 void showIdentity() {
    /* Print info about itself */
    printfPlusPlus("Hey there, I am an instance of linkedList data strcuture.");
    printfPlusPlus("Happy Usage !!");
 }

 void createLinkedList() {
    int tryCount = 0;                       // count to hold number of retries by the user
    int numNodes = 0;                       // how many nodes user want ?
    int dataSet[10] = {};                   // hold values that user will give after entering number of nodes
    
    do {
       /* If max retries limit reached , print info about it and return */
       if(tryCount == MAX_RETRIES) {                    
          printfPlusPlus("Sorry bro, Hard Luck !!"); 
          return;
       }
       
       tryCount++;                                                // Take hold of try count
       printf("%d :: How many nodes you want : ",tryCount);       // Ask input from user --> number of nodes
       scanfPlusPlus(&numNodes);                                 
    } 
    /* Number of nodes should be in between 1 to 10 in starting there afterwards they can extend it or shrink
     * according to their convinience , that's what the use case of linked list */
    while (numNodes <= 0 || numNodes > 10);                    
    
    /* Take data elements from standard input and store it into one buffer */
    printfPlusPlus(":: Enter node data values one by one , consider space as termination ::");
    for(int i=0; i<numNodes; i++) {
       scanf("%d",&dataSet[i]);
    }

    /* Create first node and give it's refrence to head pointer */
    head = (Node *)malloc(sizeof(Node));          // head --> Fisrt node
    head -> data = dataSet[0];                    // Fill the data element
    head -> ptrToNextNode = NULL;                 // Make link field as NULL

    /* It hold the refrence of previous node , that's how we are able to make links between previous node
     * and current node , PS : Dont't forgot to update the refrence of previous node to current node after
     * the link is established */
    Node *  prevNodePtr = head;       

    for(int i=1; i<numNodes; i++) {

       /* Create a new node and give its refrence to link field of previous node */
       prevNodePtr -> ptrToNextNode = (Node *)malloc(sizeof(Node));      // Give refrence to previous node  
       prevNodePtr = prevNodePtr -> ptrToNextNode;                       // Make it previous node
 
       prevNodePtr -> data = dataSet[i];                                 // Fill the data element 
       prevNodePtr -> ptrToNextNode = NULL;                              // Make link field as NULL 
    }
 }

 /* Function to print the linked list , only data part 
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void printLinkedList(Node * ptrToFirstNode) {
    printf("Linked List ----> [ ");

    /* Move through out the linked list, until you not met NULL in the node link field */
    while(ptrToFirstNode != NULL) {                                       
       printf("%d ",ptrToFirstNode -> data);                 // print the data of node pointed by the pointer
       ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;     // point to next node in the linked list using node link field
    }
    printf("]\n");
 }

 /* Function to reverse the linked list
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void reverseLinkedList(Node * ptrToFirstNode) {

    Node * prevNode = NULL;                                // pointer to previous node
    Node * currentNode = ptrToFirstNode;                   // pointer to current node
    Node * nextNode = currentNode -> ptrToNextNode;        // pointer to next node 

    while(currentNode != NULL) {
       currentNode -> ptrToNextNode = prevNode;            // link reversal
       
       /* shift all pointers one step ahead */
       prevNode = currentNode;                             
       currentNode = nextNode;

       /* keep this in if case , otherwise at the last step you will get segmentation fault 
        * because at the last it points to NULL and you are trying to access the link field
        * of NULL (PS : You can't) 
        */
       if(nextNode != NULL) {                               
          nextNode = nextNode -> ptrToNextNode;
       }
    }

    /* now all link are reversed but our main head is still there , so change it last node */
    head = prevNode;                                  
 }
 
 /* Function to get the length of linked list (number of nodes)
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 int getLinkedListLength(Node * ptrToFirstNode) {
    int linkedListLength = 0;

    /* traverse through out of linked and keep increment one counter , that sit */
    while(ptrToFirstNode != NULL) {
       ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;
       linkedListLength++;
    }

    return linkedListLength;                       // return length
 }

 /* Function to search an element in the linked list (first occurance) 
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 int searchDataInLinkedList(Node * ptrToFirstNode , int target) {
   /* counter to mantain index of linked list , in case target is found return it */
   int targetIndex = 0;         

   /* traverse througout the whole linked list while mantaining one index and keep
    * checking for the target , If it finds retrun the index otherwise retrun -1 
    */
   while(ptrToFirstNode != NULL) {
      if(ptrToFirstNode -> data == target) {
         return targetIndex;
      }
      targetIndex++;
      ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;
   }

   /* target not found , return -1 */
   return -1;
 }

 /* Function to add a node to linked list at the beginning
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void insertAtBegin(Node * ptrToFirstNode) {
    int nodeData = 0;            // hold data to be added to the new node
   
    /* ask user about data and store it into one buffer */
    printf("I'm inside insertAtBgein, Please enter element you want to add : ");
    scanfPlusPlus(&nodeData);

    /* create a new node and make the link part of it to refer to first node */
    Node * newNodePtr = (Node *)malloc(sizeof(Node));      

    newNodePtr -> data = nodeData;                         // fill the data field 
    newNodePtr -> ptrToNextNode = ptrToFirstNode;          // give refrence of first node to its link field

    head = newNodePtr;                                     // make new node as first node
 }

 /* Function to add a node to linked list at somewhere in the middle
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void insertAtMiddle(Node * ptrToFirstNode) {
    int reach = 0;               // counter to go to desired location
    int tryCount = 0;            // hold number of retries by the user
    int nodeData = 0;            // hold data to be added to the new node
    int nodeIndex = -1;          // hold index , where we have to add the new node
   
    /* ask user about where to add the node in the middle and store it into buffer */
    printfPlusPlus("I'm inside insertAtMiddle, Please tell me where you want to add the node in the middle ? ");
    printf("Length of Linked List is : %d\n",getLinkedListLength(ptrToFirstNode));
    do {
       /* If max retries limit reached , print info about it and return */
       if(tryCount == MAX_RETRIES) {                    
          printfPlusPlus("Sorry bro, Hard Luck !!");       
          return;                                          
       }

       tryCount++;                                 // Increment to get update of failed attemp by the user
       printf("%d :: Enter the index : ",tryCount);
       scanfPlusPlus(&nodeIndex);
    }
    /* validate the index */
    while(nodeIndex <= 0 || nodeIndex >= getLinkedListLength(ptrToFirstNode)-1);
    
    /* ask user about data and store it into buffer */
    printf("Please enter element you want to add : ");
    scanfPlusPlus(&nodeData);
    
    /* reach just before the desire index */
    while(reach != nodeIndex - 1) {
       ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;
       reach++;
    }

    /* create a new node and give the refrence of this node to that node where you are now */
    Node * newNodePtr = (Node *)malloc(sizeof(Node));
    newNodePtr -> data = nodeData;                           // fill the data field 

    /* give refrence of next node to new node */
    newNodePtr -> ptrToNextNode = ptrToFirstNode -> ptrToNextNode;      

    /* give refrence of new node to current node */
    ptrToFirstNode -> ptrToNextNode = newNodePtr;               
 }
 
 /* Function to add a node to linked list at the end
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void insertAtEnd(Node * ptrToFirstNode) {
    int nodeData = 0;            // hold data to be added to the new node

    /* ask user about data and store it into one buffer */
    printf("I'm inside insertAtEnd, Please enter element you want to add : ");
    scanfPlusPlus(&nodeData);
    
    /* traverse throught the whole linked list until you not meet last node */
    while((ptrToFirstNode -> ptrToNextNode) != NULL) {
       ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;
    }

    /* create a new node give the refrence of this node to link field of last node */
    Node * newNodePtr = (Node *)malloc(sizeof(Node));
    newNodePtr -> data = nodeData;                           // fill the data field 
    newNodePtr -> ptrToNextNode = NULL;                      // make this node refer to NULL

    /* now we are at the last node , just make it refer to new node instead to NULL */
    ptrToFirstNode -> ptrToNextNode = newNodePtr;
 }

 /* Function to add a node to linked list at some specific location
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void addNode(Node * ptrToFirstNode) {
    int tryCount = 0;                         // hold number of retries by the user
    int userChoice = -1;                      // where you want to add the node ?

    printfPlusPlus("Tell me where you want to add the node ? ");
    do {
      /* If max retries limit reached , print info about it and return */
       if(tryCount == MAX_RETRIES) {                    
          printfPlusPlus("Sorry bro, Hard Luck !!");       
          return;                                          
       }

       tryCount++;                                 // Increment to get update of failed attemp by the user
       /* print info about what user can do */
       printf("%d :: 1 ->  Beginning or 2 -> Somewhere in the middle or 3 -> End : ",tryCount);  
       scanfPlusPlus(&userChoice);        // take user choice 
    } 
    /* choice must be acceptable, otherwise don't go ahead */
    while(userChoice < 1 || userChoice > 3);

    /* switch choice , just call the right fun() and break */
    switch(userChoice) {
       case 1:
            insertAtBegin(ptrToFirstNode);              // fun() to add node at beginning
            break;
       case 2:
            /* fun() to add the node at somewhere in the middle , user will tell by somehow */
            insertAtMiddle(ptrToFirstNode);             
            break;
       case 3:
            insertAtEnd(ptrToFirstNode);                // fun() to add node at end
            break;
       default:
            printfPlusPlus("Unexpected thing happen !!");
            break;
    }
 }
 
 /* Function to remove a node from linked list by index
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void removeNodeAtIndex(Node * ptrToFirstNode) {
    int reach = 0;                       // counter to go to desired location
    int tryCount  = 0;                   // counter to check for retries by the user
    int nodeIndex = -1;                  // store index which is to be deleted 

    /* ask user about from where we have to remove the node */
    printfPlusPlus("I'm inside removeNodeAtIndex, Please tell from where you want to remove the node ? ");
    printf("Length of Linked List is : %d\n",getLinkedListLength(ptrToFirstNode));
    do {
       /* If max retries limit reached , print info about it and return */
       if(tryCount == MAX_RETRIES) {                    
          printfPlusPlus("Sorry bro, Hard Luck !!");       
          return;                                          
       }

       tryCount++;                                 // Increment to get update of failed attemp by the user
       printf("%d :: Enter the index : ",tryCount);
       scanfPlusPlus(&nodeIndex);
    }
    /* validate the index */
    while(nodeIndex < 0 || nodeIndex > getLinkedListLength(ptrToFirstNode)-1);

    /* reach towards the desired index */
    while(reach != nodeIndex - 1) {
       ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;
       reach++;
    }
    
    /* Point to previous and next node from which node we have to remove */
    Node * ptrToPrevNode = ptrToFirstNode;
    Node * ptrToNextNode = (ptrToFirstNode -> ptrToNextNode) -> ptrToNextNode;
    
    /* just you have the give the refrence of next node to previous node 
     * PS : Don't forget to de allocate the memory deleted node 
     */

    free(ptrToPrevNode -> ptrToNextNode);               // free that node which link is cutted from linked list
    ptrToPrevNode -> ptrToNextNode = ptrToNextNode;     // point to next node in the linked list
 }
 
 /* Function to remove a node from linked list by data
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void removeNodewithData(Node * ptrToFirstNode) {
    int reach  = 0;                        // counter to go to desired location 
    int nodeData  = 0;                     // data user want to remove from list
    int nodeIndex = 0;                     // if data is there in the list , it will hold the index of it

    /* ask user about from where we have to remove the node */
    printf("I'm inside removeNodeWithData, Enter element you want to remove from list : ");
    scanfPlusPlus(&nodeData);

    nodeIndex = searchDataInLinkedList(ptrToFirstNode,nodeData);
    if(nodeIndex == -1) {
       printfPlusPlus("Element : %d is not there in the list , what bro ?");
    }
    else {
       /* now element is there in the list and you already got the index of it 
        * same thing you copy what we have previously did in removeNodeAtIndex*/
       
       /* reach towards the desired index */
       while(reach != nodeIndex - 1) {
          ptrToFirstNode = ptrToFirstNode -> ptrToNextNode;
          reach++;
       }
         
       /* Point to previous and next node from which node we have to remove */
       Node * ptrToPrevNode = ptrToFirstNode;
       Node * ptrToNextNode = (ptrToFirstNode -> ptrToNextNode) -> ptrToNextNode;
      
       /* just you have the give the refrence of next node to previous node 
       * PS : Don't forget to de allocate the memory deleted node 
       */
      free(ptrToPrevNode -> ptrToNextNode);               // free that node which link is cutted from linked list
      ptrToPrevNode -> ptrToNextNode = ptrToNextNode;     // point to next node in the linked list
    } 
 }

 /* Function to remove a node from linked list either by index or by data
  * @details : It will take only head of linked list as an argument (Call by value only)
  */
 void removeNode(Node * ptrToFirstNode) {
    int choice   = 0;                 // get the user choice , we will validate 
    int tryCount = 0;                 // hold number of retries taken by the user
    
    printfPlusPlus("Tell me either node data or node index you want to remove ?");
    do {
       /* If max retries limit reached , print info about it and return */
       if(tryCount == MAX_RETRIES) {                    
          printfPlusPlus("Sorry bro, Hard Luck !!");       
          return;                                          
       }

       tryCount++;                                 // Increment to get update of failed attemp by the user
       /* print info about what user can do */
       printf("%d :: 1 -> node index or 2 -> node data : ",tryCount);
       scanfPlusPlus(&choice);                     // take user choice and store it somewhere
    }
    /* validate the user input */
    while(choice < 1 || choice > 2);
    
    /* switch choice , just call the right fun() and break */
    switch(choice) {
       case 1:
            removeNodeAtIndex(ptrToFirstNode);               // fun() to remove node by index 
            break;
       case 2:
            /* this fun() will remove first occurance of node having user given data otherwise
             * we will let the user know that the data they are looking for is not there in the
             * linked list */
            removeNodewithData(ptrToFirstNode);              
            break;
       default:
            printfPlusPlus("Unexpected thing happens !!");
            break;
    }
 }