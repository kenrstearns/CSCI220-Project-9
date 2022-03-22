#include <iostream>

using namespace std;        // Allows all standard names to be used

// This will define the structure of the node(s) used in the LinkedList
typedef struct _node
{
        int listInfo;
        struct _node *next;
} node;

// The LinkedList class
class LinkedList
{
    Private:
    node *headNode;

    public:
    // The constructor to create a new LinkedList
    LinkedList()
    {
        headNode = nullptr;
    }

    // To re-initialize the LinkedList
    // Postcondition: the LinkedList reset to empty
    void reinitialize()
    {
        headNode = nullptr;
    }

    // A function to add a user input value into a LinkedList
    // Precondition: An integer value that must be a real number
    // Postcondition: The user input integer being added and sorted within the LinkedList
    // as long as the value is not already present within the list
    void add(int num)
    {
        node *newNode = new node;
        newNode -> listInfo = num;

        if(headNode == nullptr)
        {
            newNode ->next = nullptr;
            headNode = newNode;
            return;
        }

        node *previousNode;
        node *tempNode = headNode;

        if(tempNode != NULL && tempNode ->listInfo == num)
        {
            cout << "That value is already present." << endl;
            return;
        }

        if(tempNode ->listInfo > num)
        {
            newNode ->next = headNode;
            headNode = newNode;
            return;
        }

        while(tempNode != NULL && tempNode ->listInfo < num)
        {
            previousNode = tempNode;
            tempNode = tempNode ->next;
        }

        newNode ->next = tempNode;
        previousNode ->next = newNode;

    }

    // A function to remove a number from a LinkedList
    // Precondition: An integer value that must be a real number
    // Postcondition: The user input number removed if it is present
    void remove(int num)
    {
        node *tempNode;
        node *prevNode;
        tempNode = headNode;

        if(tempNode ->listInfo == num)
        {
            headNode = tempNode ->next;
            tempNode ->next = nullptr;
            delete tempNode;
            return;
        }

        while(tempNode != nullptr && tempNode ->listInfo != num)
        {
            prevNode = tempNode;
            tempNode = tempNode ->next;
        }

        if(tempNode == nullptr)
            return;

        prevNode ->next = tempNode ->next;

        tempNode ->next = nullptr;
        delete tempNode;
    }

    // A function to return the size of the LinkedList
    // Postcondition: returns the number of values found within the LinkedList
    int listSize()
    {
        node *tempNode = headNode;
        int counter = 0;

        while(tempNode != nullptr)
        {
            tempNode = tempNode ->next;
            counter++;
        }
        return counter;
    }

    // A function to determine whether or not a certain number can be found in the LinkedList
    // Precondition: An integer value that must be a real number
    // Postcondition: If the searched for integer is/ or is not found the console will print the result
    void isPresent(int num)
    {
        node *tempNode = headNode;

        while(tempNode != nullptr && tempNode ->listInfo != num)
        {
            tempNode = tempNode ->next;
        }

        if(tempNode != nullptr && tempNode->listInfo == num)
            cout << "The value " << num << " is present within the list." << endl;
        else
            cout << "The value " << num << " is not present within the list." << endl;
    }

    // A function to return the value of the searched for nth element of the LinkedList.
    // Precondition: An integer value that must be a real number
    // Postcondition: Finds the position of the integer within the list if there is a value present
    int findNum(int n)
    {
        node *tempNode = headNode;

        for(int i = 1; tempNode != nullptr && i < n; i++)
        {
            tempNode = tempNode ->next;
        }

        if(tempNode == nullptr)
            return -1;

        return tempNode ->listInfo;
    }

    // A function to display all values found within the LinkedList
    // Postcondition: The console will print all values found within the LinkedList
    void printList()
    {
        node *tempNode = headNode;

        if(tempNode == nullptr)
        {
            cout << "The list is currently empty." << endl;
            return;
        }
        cout << "List consists of the value(s): < " << tempNode ->listInfo;
        tempNode = tempNode ->next;

        while(tempNode != nullptr)
        {
            cout << ", " << tempNode ->listInfo;
            tempNode = tempNode ->next;
        }
        cout << " >" << endl;
    }

    // A function to check if the LinkedList is empty or not
    // Postcondition: Returns and prints if the LinkedList is empty
    void empty()
    {
        if(headNode == nullptr)
            cout << "The list is empty." << endl;
        else
            cout << "The list is not empty." << endl;
    }
};

    // A function to show the user the menu
    // Postcondition: Returns and displays the menu for the user to see
    void displayMenu()
    {
        cout << "This program responds to commands the user enters to " << endl;
        cout << "manipulate an ordered list of integers, which is " << endl;
        cout << "initially empty. In the following commands, k is a " << endl;
        cout << "position in the list, and v is an integer. Press 'Enter' to submit a command." << endl << endl;
        cout << "e -- Re-initialize the list to be empty. " << endl;
        cout << "i v -- Insert the value v into the list. " << endl;
        cout << "r v -- Remove the value v from the list. " << endl;
        cout << "m -- Is the list empty? " << endl;
        cout << "l -- Report the length of the list. " << endl;
        cout << "p v -- Is the value v present in the list? " << endl;
        cout << "k k1 -- Report the k1th value in the list. " << endl;
        cout << "w -- Write out the list. " << endl;
        cout << "h -- See this menu. " << endl;
        cout << "q -- Quit." << endl << endl;
    }

int main()
{

list<int> mylist{ 1, 2, 3, 4, 5 };

    cout << mylist.size();

    return 0;

    char userInput;            // A char type to hold the users input to traverse through the menu
    LinkedList userList;        // A new list to hold the users entered values.
    int userInt;        // holds the integer the user enters and wishs to manipulate within the program
    int m;                // Used to hold the nth place within the list

    cout << "Welcome to the Integer Organizer by Barbara Tavarez" << endl;
    displayMenu();

    // While the user has not entered 'q' to quit the console will keep switching the char
    // and performing the respective function as the user enters the command
    while(1)
    {
        cout << " -->";
        cin >> userInput;
        switch(userInput)
        {
            case'e':
                userList.reinitialize();
                cout << endl;
                break;
            case 'i':
                cin >> userInt;
                userList.add(userInt);
                break;
            case 'r':
                cin >> userInt;
                userList.remove(userInt);
                break;
            case 'm':
                userList.empty();
                break;
            case 'l':
                userInt = userList.listSize();
                cout << "The size of the list is: " << userInt << endl;
                break;
            case 'p':
                cin >> userInt;
                userList.isPresent(userInt);
                break;
            case 'k':
                cin >> m;
                userInt = userList.findNum(m);

                if(userInt == -1)
                    cout << "This list does not have " << m << "values yet." << endl;
                else
                    cout << "The " << m << "th element of this list is " << userInt << endl;
                break;
            case 'w':
                userList.printList();
                break;
            case 'h':
                displayMenu();
                break;
            case 'q':
                cout << "Thank you for using the Integer Organizer. Goodbye!";
                exit(0);
                break;
            default:
                cout << "You have entered an invalid command. Please try again." << endl;
        };
    }
    return 0;
}
