#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleNode* Digit;
typedef Digit Int; //creat a new name for the Digit Called Int.
typedef struct SingleNode* SingleNode;
typedef SingleNode List; //creat a new name for the SingleNode Called List.

//Defines a struct called DoubleNode which has three fileds.
struct DoubleNode{
    int Element;
    Digit Next; //Points to the next DoubleNode.
    Digit Prev; //Points to the Previous DoubleNode
};

//Defines a struct called DoubleNode which has four fileds.
struct SingleNode {
    Int Integer;
    int index ; //index is an integer value that represents the index of the node
    int sign ; //sign is an integer value that represents the sign of the node
    SingleNode Next;
};
//Arithmatic and Read from File Functions.
Int Add(Int x ,Int y,int signX , int signY); //Adds two numbers and return the result
Int Subtract(Int x ,Int y,int signX , int signY); //subtracts two numbers and return the result
Int Multiply(Int x ,Int y,int signX , int signY); //Multiplies two numbers and return the result
Int Divide(Int x , Int y, Int r, int signX , int signY); //Divides two numbers and return the result
void ReadNumbers (List ListOfNumber); //Function to Read Numbers From File

//Function for double linked list
Int CreateInt (); // Function to create a new Integer
void InsertDigitAtEnd (int x ,Int num); // Function to insert a digit at the end
void InsertDigitAtBeginning (int x, Int num); // Function to insert a digit at the beginning
Digit FindLastNode (Int num); // Function to find the last Digit node
void PrintFromEnd (Int num, int sign); // Function to print the digits from the end
void PrintFromEndAtFile (Int num, int sign); // Function to print the digits  from the end to a file
int CompareValue (Int x , Int y);  //Function to compare the value of two numbers in the doubly linked list
void MakeCopy(Int res,Int num); // Function to make a copy of an Integer
void RemoveDigit (Digit temp ,Int num); // Function to remove a specific Digit node from the Integer

//Function for single linked list
List CreateList (); // Function to create an empty list
SingleNode InsertIntAtEnd (Int num , List list); // Function to insert an integer at the end of the list
void PrintAllNumbers (List list); // Function to print all numbers in the list
SingleNode FindInt (int index , List list);  // Function to find the integer at the specified index in the list

int main(){
    List ListOfNumber = CreateList(); // Create a new list to store numbers
    ReadNumbers (ListOfNumber); // Read numbers and insert them into the list
    int op = -1 ,num1,num2;
    SingleNode temp1 , temp2 ;1
    Int res ;

    // Loop to create the menu
    while (op!=6){
        printf("Plz choose operation\n");
        printf("1: Print Numbers\n");
        printf("2: ADD\n");
        printf("3: Subtract\n");
        printf("4: Multiply\n");
        printf("5: Divide\n");
        printf("6: Exit\n");
        scanf("%d",&op);
        if (op == 1){
            printf("\n");
            PrintAllNumbers(ListOfNumber); // Print all numbers in the list
            printf("\n");
        }
        else if (op==2){
            printf("Plz choose two number:\n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            temp1 = FindInt(num1,ListOfNumber); // Find the first number in the list
            temp2 = FindInt(num2,ListOfNumber); // Find the secound number in the list
            res = Add(temp1->Integer,temp2->Integer,temp1->sign,temp2->sign);
            PrintFromEnd(res,res->Element);  // Print the result from the end
            PrintFromEndAtFile(res,res->Element); // Print the result from the end to a file
        }
        else if (op==3){
            printf("Plz choose two number:\n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            temp1 = FindInt(num1,ListOfNumber); // Find the first number in the list
            temp2 = FindInt(num2,ListOfNumber); // Find the second number in the list
            res = Subtract(temp1->Integer,temp2->Integer,temp1->sign,temp2->sign); // Perform subtraction
            PrintFromEnd(res,res->Element); // Print the result from the end
            PrintFromEndAtFile(res,res->Element); // Print the result from the end to a file
        }
        else if (op==4){
            printf("Plz choose two number:\n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            temp1 = FindInt(num1,ListOfNumber); // Find the first number in the list
            temp2 = FindInt(num2,ListOfNumber); // Find the second number in the list
            res = Multiply(temp1->Integer,temp2->Integer,temp1->sign,temp2->sign); // Perform multiplication
            PrintFromEnd(res,res->Element);  // Print the result from the end
            PrintFromEndAtFile(res,res->Element); // Print the result from the end to a file
        }
        else if (op==5){
            printf("Plz choose two number:\n");
            scanf("%d",&num1);
            scanf("%d",&num2);
            temp1 = FindInt(num1,ListOfNumber); // Find the first number in the list
            temp2 = FindInt(num2,ListOfNumber);  // Find the second number in the list
            Int R = CreateInt(); // Create a new Integer for the remainder
            res = Divide(temp1->Integer,temp2->Integer,R,temp1->sign,temp2->sign); // Perform division between temp1->Integer and temp2->Integer, storing the quotient in 'res' and the remainder in 'R'
            PrintFromEnd(res,res->Element); // Print the quotient from the end
            PrintFromEndAtFile(res,res->Element); // Print the quotient from the end to a file
            PrintFromEnd(R,0); // Print the remainder from the end
            PrintFromEndAtFile(R,0); // Print the remainder from the end to a file
        }
    }
}
//Function to build the addition operation
Int Add(Int x ,Int y,int signX , int signY){
    Int res = CreateInt(); //Creat new node type of Double linked list
    if (signX==0 && signY==0) //if both numbers are positive , the result is also positive
        res->Element=0;
    else if (signX==1 && signY==1)//if both numbers are negative , the result is also negative
        res->Element=1;
    else if (signX==0 && signY==1)//if one number is positive and the other is negative,subtract the smaller number from the larger number
        return Subtract(x,y,0,0);
    else
        return Subtract(y,x,0,0);

    Digit temp1 = x->Next , temp2 = y->Next ;  //temp1 point at the first node in list x and temp2  point at the first node in list y
    int sum , carry=0 ,num1,num2;

    while (temp1 !=NULL || temp2!=NULL || carry !=0){ //Add digits from both numbers and caru over any excess to the next digit
        if (temp1 != NULL)
            num1 = temp1->Element ;
        else //if temp1 = NULL then make the value of the number = 0 for the operation to be done correctly
            num1 = 0;

        if (temp2 != NULL)
            num2 = temp2->Element ;
        else //if temp2 = NULL then make the value of the number = 0 for the operation to be done correctly
            num2 = 0;

        sum = num1 + num2 + carry ;
        carry = sum / 10; //to Stores the second digit of the resulting number
        InsertDigitAtEnd(sum%10, res);

        if (temp1 != NULL)
            temp1 = temp1->Next;
        if (temp2 != NULL)
            temp2 = temp2->Next;
    }

    return res;
}
//Function to build the Subtraction operation
Int Subtract(Int x, Int y, int signX, int signY) {
    Int res = CreateInt(); // Create a new node to store the result
    Digit temp;
    int x_GreaterThan_y = CompareValue(x, y); // Compare the values of x and y using CompareValue function and store the result in x_GreaterThan_y

    if (signX == 0 && signY == 0) { // Both numbers are positive
        if (x_GreaterThan_y >= 0)
            res->Element = 0; // Set the sign of the result to positive (0)
        else {
            temp = x;
            x = y;
            y = temp;
            res->Element = 1; // Set the sign of the result to negative (1)
        }
    } else if (signX == 1 && signY == 1) { // Both numbers are negative
        if (x_GreaterThan_y >= 0)
            res->Element = 1; // Set the sign of the result to negative (1)
        else {
            temp = x;
            x = y;
            y = temp;
            res->Element = 0; // Set the sign of the result to positive (0)
        }
    } else if (signX == 0 && signY == 1) { // One number is positive and the other is negative
        return Add(x, y, 0, 0); // Perform addition of x and y with positive signs
    } else { // The first number is negative and the other is positive
        return Add(x, y, 1, 1); // Perform addition of x and y with negative signs
    }

    // Initialize variables
    Digit temp1 = x->Next, temp2 = y->Next;
    int sub, Bw = 0, num1, num2;

    while (temp1 != NULL || temp2 != NULL) {
        // Subtract digits from both numbers and borrow from the next digit if necessary
        if (temp1 != NULL)
            num1 = temp1->Element;
        else
            num1 = 0;

        if (temp2 != NULL)
            num2 = temp2->Element;
        else
            num2 = 0;

        sub = num1 - num2 - Bw;

        if (sub < 0) { // If the difference is negative, add 10 to the result and set borrow (Bw) to 1
            sub += 10;
            Bw = 1;
        } else
            Bw = 0;

        InsertDigitAtEnd(sub, res); // Insert the digit at the end of the result

        if (temp1 != NULL)
            temp1 = temp1->Next;
        if (temp2 != NULL)
            temp2 = temp2->Next;
    }

    temp = FindLastNode(res);
    while (temp->Element == 0 && temp->Prev != res) {
        // Remove trailing zeroes from the end of the result
        RemoveDigit(temp, res);
        temp = FindLastNode(res);
    }

    return res; // Return the resulting integer
}
// Function to multiply two Integers
Int Multiply(Int x, Int y, int signX, int signY) {
    Int result = CreateInt(); // Create a new Integer for the result
    InsertDigitAtEnd(0, result); // Initialize the result with a zero digit

    if (signX == signY)
        result->Element = 0; // If signs are the same, the result is positive (0)
    else
        result->Element = 1; // If signs are different, the result is negative (1)

    Digit ptr1, ptr2 = y->Next; // Pointers to iterate through digits of x and y
    int carry = 0, mul, digit, count = 0; // Variables for multiplication

    while (ptr2 != NULL) {
        ptr1 = x->Next;
        Int temp = CreateInt(); // Create a temporary Integer to hold intermediate results

        // Multiply by powers of 10 based on the count
        for (int i = 0; i < count; i++)
            InsertDigitAtEnd(0, temp);

        count++;
        carry = 0;

        while (ptr1 != NULL) {
            mul = ptr1->Element * ptr2->Element + carry; // Multiply two digits and add carry
            if (mul > 9) {
                InsertDigitAtEnd(mul % 10, temp); // Store the least significant digit of the product
                carry = mul / 10; // Calculate the carry for the next digit
            } else {
                InsertDigitAtEnd(mul, temp); // Store the product without carry
                carry = 0; // Reset the carry
            }

            ptr1 = ptr1->Next; // Move to the next digit of x
        }

        if (carry > 0)
            InsertDigitAtEnd(carry, temp); // Add the remaining carry as the most significant digit

        result = Add(temp, result, 0, 0); // Add the intermediate result to the final result
        ptr2 = ptr2->Next; // Move to the next digit of y
    }

    return result; // Return the multiplied result
}

Int Divide(Int x , Int y, Int R, int signX , int signY){
    Int result = CreateInt();
    Int Zero = CreateInt();
    int AddZero = 0 ;
    Int r = CreateInt();
    InsertDigitAtEnd(0,Zero);

    if(CompareValue(x,y)==-1){
        // If x is smaller than y, the result is 0 and the remainder is x
        InsertDigitAtEnd(0,result);
        MakeCopy(R, x);
        return result ;
    }

    if (CompareValue(y,Zero) == 0){
        // Division by zero is not allowed
        printf("You to divide by zero\n");
        return result;
    }

    if (signX == signY)
        result->Element=0;
    else
        result->Element=1;

    Digit temp = FindLastNode(x);
    while (CompareValue(r, y) == -1) {
        // Take digits from x to build the dividend r until it is greater than or equal to y
        InsertDigitAtBeginning(temp->Element, r);
        temp = temp->Prev;
    }

    while (CompareValue(r,y) >=0 ){
        int res = 0 ;

        while(CompareValue(r,y) >= 0){
            // Subtract y from the current value of r repeatedly to find the quotient digit
            r = Subtract(r,y,0,0);
            res++;
        }

        InsertDigitAtBeginning(res,result);
        AddZero = 0 ;

        if (temp != x ){
            if (temp->Element != 0 && CompareValue(r,Zero) == 0){
                // Remove leading zeros from r if necessary then add
                RemoveDigit(r->Next,r);
                InsertDigitAtBeginning(temp->Element,r);
                AddZero++;
                temp=temp->Prev;
            }
            else if (CompareValue(r,Zero) == 1) {
                // Add digit from x to r
                InsertDigitAtBeginning(temp->Element, r);
                AddZero++;
                temp = temp->Prev;
            }
        }

        while (CompareValue(r,Zero) == 0  && temp != x && temp->Element==0){
            // Insert zeros from x into the result
            InsertDigitAtBeginning(0,result);
            temp=temp->Prev;
        }

        if (CompareValue(r,Zero) == 0 && temp != x && temp->Element !=0){
            // after Insert zeros from x into the result and reminder still zero add digit to reminder
            RemoveDigit(r->Next,r);
            InsertDigitAtBeginning(temp->Element,r);
            AddZero++;
            temp=temp->Prev;
        }

        while (CompareValue(r,y) == -1 && temp != x) {
            // Insert leading zeros into the result and adjust r
            InsertDigitAtBeginning(0,result);
            InsertDigitAtBeginning(temp->Element,r);
            AddZero++;
            temp=temp->Prev;
        }

        if (AddZero && CompareValue(r,y) ==-1)
            // if AddZero > 0 and reminder < y add zero to result
            InsertDigitAtBeginning(0,result);
    }

    MakeCopy(R,r);
    return result;
}
void ReadNumbers(List ListOfNumber) {
    FILE* file = fopen("file.txt", "r"); // Open the file for reading
    int digit = getc(file); // Read the first character from the file
    int i = 1; // Counter for assigning index to numbers
    int s = 0; // Variable to store the sign of the number (0 for positive, 1 for negative)

    while (digit != EOF) { // Loop until the end of the file is reached
        while (digit == '\n' || digit == ' ') // Skip newline and space characters
            digit = getc(file);

        Int num = CreateInt(); // Create a new integer to store the read number

        if (digit == '-') { // Check if the number is negative
            s = 1; // Set the sign to negative
            digit = getc(file); // Read the next character
        } else {
            s = 0; // Set the sign to positive
        }

        while (digit >= 48 && digit <= 57) { // Loop while the character represents a digit (ASCII range: 0-9)
            InsertDigitAtBeginning(digit - 48, num); // Insert the digit at the beginning of the number
            digit = getc(file); // Read the next character
        }

        SingleNode ptr = InsertIntAtEnd(num, ListOfNumber); // Insert the number into the list and get a pointer to the node
        ptr->index = i++; // Assign the index to the node and increment the counter
        ptr->sign = s; // Set the sign of the number

    }

    fclose(file); // Close the file
}


//*********************************************************************
//                     Function for double linked list

Int CreateInt() {
    Int num = (Int)malloc(sizeof(struct DoubleNode));  // Allocate memory for a new Int node
    if (num == NULL)
        printf("Memory is full\n");  // Print an error message if memory allocation fails

    num->Next = NULL;  // Initialize the Next pointer to NULL
    num->Prev = NULL;  // Initialize the Prev pointer to NULL

    return num;  // Return the created Int node
}

void InsertDigitAtEnd(int x, Int num) {
    Digit temp = (Digit)malloc(sizeof(struct DoubleNode));
    Digit ptr = num;

    // Create a new digit node
    temp->Next = NULL;
    temp->Element = x;

    // Traverse to the last digit node
    while (ptr->Next != NULL)
        ptr = ptr->Next;

    // Append the new digit node at the end
    ptr->Next = temp;
    temp->Prev = ptr;
}

void InsertDigitAtBeginning(int x, Int num) {
    Digit temp = (Digit)malloc(sizeof(struct DoubleNode)); // Allocate memory for a new digit
    temp->Element = x; // Assign the value to the new digit
    temp->Next = num->Next; // Make the new digit point to the current first digit
    temp->Prev = num; // Make the new digit's previous pointer point to num

    if (num->Next != NULL)
        num->Next->Prev = temp; // If there is a current first digit, make its previous pointer point to the new digit

    num->Next = temp; // Make num's next pointer point to the new digit, effectively inserting it at the beginning
}
Digit FindLastNode (Int num){
    Digit temp = num;

    // Traverse the linked list until the last node is reached
    while (temp->Next != NULL)
        temp = temp->Next;

    return temp; // Return the last node
}

void PrintFromEnd(Int num, int sign) {
    // Check if the number is empty or has only one node
    if (num == NULL || num->Next == NULL) {
        printf("No value present\n");
        return;
    }

    // Print the sign of the number
    if (sign == 1)
        printf("-");
    else
        printf("+");

    Digit temp = FindLastNode(num); // Find the last node in the number

    // Traverse the linked list from the last node to the first node
    while (temp != num) {
        printf("%d", temp->Element); // Print the element of the current node
        temp = temp->Prev; // Move to the previous node
    }

    printf("\n"); // Print a new line after printing the number
}

int CompareValue(Int x, Int y) {
    // Check if one number has digits while the other doesn't
    if (x->Next == NULL && y->Next != NULL)
        return -1;
    else if (x->Next != NULL && y->Next == NULL)
        return 1;

    Digit temp1 = FindLastNode(x), temp2 = FindLastNode(y);

    // Traverse to the corresponding digits of x and y
    while (temp1 != x && temp2 != y) {
        temp1 = temp1->Prev;
        temp2 = temp2->Prev;
    }

    if (temp1 == x && temp2 == y) {
        // Both numbers have the same number of digits
        temp1 = FindLastNode(x);
        temp2 = FindLastNode(y);

        while (temp1 != x && temp2 != y) {
            if (temp1->Element == temp2->Element) {
                temp1 = temp1->Prev;
                temp2 = temp2->Prev;
            } else if (temp1->Element > temp2->Element)
                return 1; // x is greater than y
            else
                return -1; // y is greater than x
        }
    } else if (temp1 == x)
        return -1; // x has fewer digits than y, so x is less than y
    else
        return 1; // y has fewer digits than x, so y is less than x

    return 0; // x and y are equal
}

void MakeCopy(Int res, Int num) {
    // Copy the element from the original number to the result
    res->Element = num->Element;

    // Iterate through the digits of the original number starting from the next digit
    Digit temp = num->Next;
    while (temp != NULL) {
        // Insert each digit at the end of the result number
        InsertDigitAtEnd(temp->Element, res);

        // Move to the next digit
        temp = temp->Next;
    }
}

void RemoveDigit(Digit temp, Int num) {
    temp->Prev->Next = temp->Next;  // Update the Next pointer of the previous node to skip the current node
    if (temp->Next != NULL)
        temp->Next->Prev = temp->Prev;  // Update the Prev pointer of the next node to skip the current node
    free(temp);  // Free the memory allocated for the current node
}

void PrintFromEndAtFile(Int num, int sign) {
    FILE* fp = fopen("output.txt", "a"); // Open the file in append mode
    if (num == NULL || num->Next == NULL) {
        fprintf(fp, "Don't have a value\n"); // Print a message to the file if the list is empty or has no elements
        return;
    }
    if (sign == 1)
        fprintf(fp, "-"); // Print a minus sign if the number is negative
    else
        fprintf(fp, "+"); // Print a plus sign if the number is positive
    Digit temp = FindLastNode(num); // Find the last digit of the number
    while (temp != num) {
        fprintf(fp, "%d", temp->Element); // Print each digit to the file
        temp = temp->Prev; // Move to the previous digit
    }
    fprintf(fp, "\n"); // Print a newline character to separate the number from the next line
    fclose(fp); // Close the file
}


//*********************************************************************
//                     Function for single linked list

List CreateList() {
    List list = (List)malloc(sizeof(struct SingleNode)); // Allocate memory for the list
    if (list == NULL)
        printf("Memory is full\n"); // Error handling if memory allocation fails
    list->Next = NULL; // Set the next pointer of the list to NULL
    list->Integer = NULL; // Set the Integer pointer of the list to NULL
    return list; // Return the created list
}

// This function inserts an Integer node at the end of the list
SingleNode InsertIntAtEnd(Int num, List list) {
    SingleNode temp = (SingleNode)malloc(sizeof(struct SingleNode)), ptr = list;

    if (temp == NULL)
        printf("Memory is full\n");

    // Traverse to the end of the list
    while (ptr->Next != NULL)
        ptr = ptr->Next;

    // Create a new node and assign values
    temp->Next = NULL;
    temp->Integer = num;
    // Link the new node to the end of the list
    ptr->Next = temp;
    return temp; // Return the inserted node
}

void PrintAllNumbers(List list){
    // Check if the list or its next node is empty
    if (list == NULL || list->Next == NULL)
        printf("Please read the number from the file.\n");

    // Start iterating through the list nodes
    SingleNode temp = list->Next;
    while (temp != NULL){
        printf("%d: ", temp->index);  // Print the node index
        PrintFromEnd(temp->Integer, temp->sign);  // Print the number stored in the node
        temp = temp->Next;  // Move to the next node
    }
}

SingleNode FindInt(int index, List list){
    SingleNode temp = list->Next;
    // Traverse the list until either the end is reached or the desired index is found
    while (temp != NULL && temp->index != index)
        temp = temp->Next;
    // Return the found node or NULL if not found
    return temp;
}