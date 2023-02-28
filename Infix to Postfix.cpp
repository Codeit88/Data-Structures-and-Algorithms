#include <iostream>
using namespace std;

template <class T>
class Stack
{
    int top;
    int maxsize;
    T *array;

public:
    Stack()
    {
        top = -1;
        maxsize = 10;
        array = new T[maxsize];
    }
    Stack(int size)
    {
        top = -1;
        maxsize = size;
        array = new T[maxsize];
    }
    bool IsEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool IsFull()
    {
        if (top == maxsize)
            return true;
        else
            return false;
    }
    bool push(T &val)
    {
        if (!IsFull())
        {
            array[++top] = val;
            return true;
        }
        else
        {
            cout << "Stack is Full\n";
            return false;
        }
    }
    bool pop()
    {
        if (!IsEmpty())
        {
            array[top--];
            return true;
        }
        else
        {
            cout << "Stack is Empty\n";
            return false;
        }
    }
    bool Top(T &val)
    {
        if (!IsEmpty())
        {
            val = array[top];
            return true;
        }
        else
           // val='99';
            return false;
    }
    ~Stack()
    {
        delete array;
    }
};

bool check(char expression[])
{
    char top_element;
    bool flag = true;
    Stack<char> s1;

    for (int i = 0; expression[i] != '\0' && flag == true; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s1.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            s1.Top(top_element);
            if (top_element == '(')
            {
                s1.pop();
            }
            else if(s1.IsEmpty())
            {
                flag = false;
            }
            else{
                flag=false;
            }
        }
        else if (expression[i] == '}')
        {
            s1.Top(top_element);
            if (top_element == '{')
            {
                s1.pop();
            }
            else if(s1.IsEmpty())
            {
                flag = false;
            }
            else{
                flag=false;
            }
        }
        else if (expression[i] == ']')
        {
            s1.Top(top_element);
            if (top_element == '[')
            {
                s1.pop();
            }
            else if(s1.IsEmpty())
            {
                flag = false;
            }
            else{
                flag=false;
            }
        }
    }
    if (flag == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void evaluate_postfix(char postfix[])
{
    Stack<int> s1;
    int number1 = 0, number2 = 0, result = 0;
    int val = 0;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            val = int(postfix[i]) - 48;
            s1.push(val);
        }
        else if (postfix[i] == '+')
        {
            s1.Top(number1);
            s1.pop();
            s1.Top(number2);
            s1.pop();
            result = number1 + number2;
            s1.push(result);
        }
        else if (postfix[i] == '-')
        {
            s1.Top(number1);
            s1.pop();
            s1.Top(number2);
            s1.pop();
            result = number1 - number2;
            s1.push(result);
        }
        else if (postfix[i] == '*')
        {
            s1.Top(number1);
            s1.pop();
            s1.Top(number2);
            s1.pop();
            result = number1 * number2;
            s1.push(result);
        }
        else if (postfix[i] == '/')
        {
            s1.Top(number1);
            s1.pop();
            s1.Top(number2);
            s1.pop();
            result = number1 / number2;
            s1.push(result);
        }
    }
    s1.Top(result);

    std::cout << "Ans : "<< result;
    std::cout << endl;
}
int priority(char element)
{
    if (element == '/' || element == '*')
    {
        return 2;
    }
    else if (element == '+' || element == '-')
    {
        return 1;
    }
    else
        return -1;
}
void infixtopostfix(char infix[])
{
    bool exp_check = check(infix);
    char top_element;
    string expression;
    Stack<char> s1;
    if (exp_check == false)
    {
        std::cout << "Wrong Paranthesis\n";
    }
    else
    {
        for (int i = 0; infix[i] != '\0'; i++)
        {
            s1.Top(top_element);
            if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
            {
                expression += infix[i];
            }
            else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
            {
                top_element = '(';
                s1.push(top_element);
            }
            else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
            {
                s1.Top(top_element);
                while (top_element != '(' && !s1.IsEmpty())
                {
                    expression += top_element;
                    s1.pop();
                    s1.Top(top_element);
                }
                s1.pop();
            }
            else if (priority(infix[i]) > priority(top_element) || s1.IsEmpty())
            {
                s1.push(infix[i]);
            }
            else if (priority(infix[i] <= priority(top_element)))
            {
                while (priority(top_element) >= priority(infix[i]) && !s1.IsEmpty())
                {
                    expression += top_element;
                    s1.pop();
                    s1.Top(top_element);
                }
                s1.push(infix[i]);
            }
        }

        while (!s1.IsEmpty())
        {
            s1.Top(top_element);
            expression += top_element;
            s1.pop();
        }
    }

    for (int i = 0; expression[i] != '\0'; i++)
    {
        cout << expression[i];
    }
    cout << endl;
}

int main()
{

    char arr[30];
    bool flag;
   
     
        
        
            cout << "Enter expression (Paranthesis) : ";
            cin.getline(arr, 30);
            flag = check(arr);
            if (flag == true)
            {
                cout << "True Expression\n";
            }
            else
            {
                cout << "False from paranthesis";
            }
            
			cout<<"Infix to postfix"<<endl;
            cin.ignore();
            cout<<"Enter expression : ";
            cin.getline(arr,30);
            infixtopostfix(arr);


    return 0;
}


