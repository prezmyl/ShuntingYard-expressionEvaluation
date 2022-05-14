#include "Solution.hpp"
#include <cmath>

using namespace std;

Solution::Solution(string operators)
{
   // this->inputQ = new Queue();
    this->outputQ = new Queue();
    this->operators = operators;
    this->result = 0;
}

Solution::~Solution()
{
    //this->inputQ->DequeAll();
    this->outputQ->DequeAll();
    //delete inputQ;
    delete this->outputQ;
}


void Solution::ShuntingYard(Queue* inputQ)
{
    Stack opStack = Stack();
    //Queue* outputQ = new Queue();
    string toProcess = string();

//const string input2("3 + 4 * 2 / ( 1 - 5 )");
    // 3 4 2 * 1 5 - / +

    //const string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"
    //3 4 2 × 1 5 − 2 3 ^ ^ ÷ +
    //while tokens

    //mozna ceknei ze neni prazdna
    while (!inputQ->isEmpty())
    {

        //Deque value(string)
        toProcess = inputQ->Deque();
        cout << "\n--------------------PROCESSING: " << toProcess << endl;
        cout << "\nBEGGINING\n";
        cout<<"op-STACKT:\n";
        opStack.Display();
        cout<<"INUPT-Q:\n";
        inputQ->Display();
        cout<<"OUTPUT-Q:\n";
        outputQ->Display();
        
        if (IsNumeric(toProcess))
        {
            //NE >convert it to num, treba uz pujde rovnou v podmince -> i outputQ pracuje s retezci -> convertovat budem az pri jejim zpracovani v postfixu
            this->outputQ->Enque(toProcess);
            continue;
        }

        //funkce netestuju
        
        if (this->IsOperator(toProcess[0], operators)) //BLBE Z pohledu modularity to bylo, kdyz jsem tady pouzival metodu jine tridy??
        {   

            cout << "opsPROCESSING: " << toProcess << endl;
            cout << "!!!!!!!associate: "<< this->GetAssociate(toProcess) << endl;
            cout << "!!!!!!!prio: "<< this->GetOperatorPrio(toProcess) << endl;
            cout << "PEEK: " << opStack.GetTop() << endl;
            
            while ((!opStack.isEmpty() && this->GetOperatorPrio(toProcess) < this->GetOperatorPrio(opStack.GetTop()) 
            && opStack.GetTop().compare("(")!= 0) || (this->GetOperatorPrio(toProcess) == this->GetOperatorPrio(opStack.GetTop()) 
            && this->GetAssociate(toProcess) == left_to_right)) //zavorky a asociativita
            {
                this->outputQ->Enque(opStack.GetTop());
                opStack.Pop();
            }

            opStack.Push(toProcess);
            opStack.Display();

        }   
        

        //ta ktere bude vyzadovata nejaky castecny zanorovani tak pushuj dolu a jeji ukonceni hned podto
        if (toProcess.compare("(") == 0)
        {
            opStack.Push(toProcess);
        }

        if (toProcess.compare(")") == 0)
        {
            /*string temp = opStack.Pop();
            while (temp != "(")
            {
                outputQ->Enque(temp);
                temp = opStack.Pop();
            }*/
            //string tmp = string();        
            while (!opStack.isEmpty() && opStack.GetTop().compare("(") != 0)
            {
                this->outputQ->Enque(opStack.GetTop());
                opStack.Pop();
            }

            /*if (opStack.isEmpty() && opStack.GetTop().compare("(") != 0)
            {
                throw ExpressionException("mismatch in parenthes");
            }*/
          
            opStack.Pop();
            //toProcess = string();
        }


    }

    while (inputQ->isEmpty() && !opStack.isEmpty())
    {
        if (opStack.GetTop() == "(")
        {
            ;//throw an exepton > operator mismatch
        }
        
        outputQ->Enque(opStack.GetTop());
        opStack.Pop();
    }
    
    cout << "\nEND\n";
    cout<<"op-STACKT:\n";
    opStack.Display();
    cout<<"INUPT-Q:\n";
    inputQ->Display();
    cout<<"OUTPUT-Q:\n";
    outputQ->Display();

    outputQ->Display();
    opStack.PopAll();

    //return outputQ;
}

void Solution::PostfixEval()
{
    Stack operandStack = Stack();
    string tmp = string();
    int nrOperands = 0;
    float x = 0;
    float y = 0;
    
    float res = 0;

    while (!this->outputQ->isEmpty())
    {
        string tmp = this->outputQ->Deque();
        if (this->IsNumeric(tmp))
        {
            operandStack.Push(tmp);
        }
        else
        {
            nrOperands = this->GetNumberOfOperands(tmp);
            if (nrOperands == 2)
            {
                x = stof(operandStack.Pop());
                y = stof(operandStack.Pop());

                //do math
                res = this->Calculation(x, y, tmp);
                operandStack.Push(to_string(res));
            }
            
            /*if (nrOperands == 1)
            {
                x = stof(operandStack.Pop());

                res = this->Calculation(x, y, tmp);
                operandStack.Push(to_string(res));
            }*/

        }
        
    }
    this->result = res;
    operandStack.PopAll();
   
}

float Solution::Calculation(float x, float y, string op)
{
    if ( !op.compare("+"))
    {
        return x + y;
    }

    if ( !op.compare("-"))
    {
        return x - y;
    }

    if ( !op.compare("*"))
    {
        return x * y;
    }

    if ( !op.compare("/"))
    {
        return x / y;
    } 
    
    if ( !op.compare("^"))
    {
        return pow(y,x);
    } 

    return -10000000000;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
}

bool Solution::IsNumeric(string str)
{
    return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

bool Solution::IsOperator(char ch, string delimitrList)
{
    size_t i = 0;
    while (delimitrList[i])
    {
        if (delimitrList[i] == ch)
        {
            return true;
        }
        i++;
    }
    return false;
    
}

int Solution::GetAssociate(string str)
{
    if (str.compare("^") == 0)
    {
        return right_to_left;
    }
    else
    {
        return left_to_right;
    }
    
}

int Solution::GetOperatorPrio(string op)
{
    if (!op.compare("+") || !op.compare("-"))
    {
        return 2;
    }
    if (!op.compare("*") || !op.compare("/"))
    {
        return 3;
    }
    else return 4; // "^"
    
}

int Solution::GetNumberOfOperands(string op)
{
    if (!op.compare("+") || !op.compare("-")
        || !op.compare("*") || !op.compare("/"))
    {
        return 2;
    }

    else return 1; // "^"
}

float Solution::DisplayResult()
{
    return this->result;
}
//Solution class rename to Sollution and make Shunting one of its method, dalsi metoda bude postfix evaluace
//Queue*(outputQ) Solution::Solution()

//vlastni is operator fce ==> modularita nezavislo na jinych modulech
//udelat sollution jako tridy jejiz soucasti bude metodo shuntingYard a postfixevaluaton


