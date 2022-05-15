#include "Solution.hpp"
#include <cmath>

using namespace std;

Solution::Solution(string operators)
{
    this->outputQ = new Queue();
    this->operators = operators;
    this->result = 0;
}

Solution::~Solution()
{
    this->outputQ->DequeAll();
    delete this->outputQ;
}


void Solution::ShuntingYard(Queue* inputQ)
{
    Stack opStack = Stack();
    string toProcess = string();

    while (!inputQ->isEmpty())
    {

        toProcess = inputQ->Deque();
               
        if (IsNumeric(toProcess))
        {
            this->outputQ->Enque(toProcess);
            continue;
        }
        
        if (this->IsOperator(toProcess[0], operators)) 
        {   
            while ((!opStack.isEmpty() && this->GetOperatorPrio(toProcess) < this->GetOperatorPrio(opStack.GetTop()) 
            && opStack.GetTop().compare("(")!= 0) || (this->GetOperatorPrio(toProcess) == this->GetOperatorPrio(opStack.GetTop()) 
            && this->GetAssociate(toProcess) == left_to_right))
            {
                this->outputQ->Enque(opStack.GetTop());
                opStack.Pop();
            }
            opStack.Push(toProcess);
        }   
        
        if (toProcess.compare("(") == 0)
        {
            opStack.Push(toProcess);
        }

        if (toProcess.compare(")") == 0)
        {
            while (!opStack.isEmpty() && opStack.GetTop().compare("(") != 0)
            {
                this->outputQ->Enque(opStack.GetTop());
                opStack.Pop();
            }
            opStack.Pop();
        }
    }

    while (inputQ->isEmpty() && !opStack.isEmpty())
    {
        if (opStack.GetTop() == "(")
        {
            throw ("missmatch in parentheses");
        }       
        outputQ->Enque(opStack.GetTop());
        opStack.Pop();
    }

    opStack.PopAll();
}

void Solution::PostfixEval()
{
    Stack operandStack = Stack();
    string tmp = string();
  
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
            y = stof(operandStack.Pop());
            x = stof(operandStack.Pop());

            //do math
            res = this->Calculation(x, y, tmp);
            operandStack.Push(to_string(res));
        }
        
    }
    this->result = res;
    operandStack.PopAll();
   
}

float Solution::Calculation(float x, float y, string op)
{
    if (!op.compare("+"))
    {
        return x + y;
    }

    if (!op.compare("-"))
    {
        return x - y;
    }

    if (!op.compare("*"))
    {
        return x * y;
    }

    if (!op.compare("/"))
    {
        return x / y;
    } 
    
    return pow(x,y); //"^"
    
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


float Solution::DisplayResult()
{
    return this->result;
}
