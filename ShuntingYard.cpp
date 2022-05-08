#include "ShuntingYard.hpp"

using namespace std;





bool ShuntingYard::IsNumeric(string str)
{
    return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

bool ShuntingYard::IsOperator(char ch, string delimitrList)
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

int ShuntingYard::GetAssociate(string str)
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

int ShuntingYard::GetOperatorPrio(string op)
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
//ShuntingYard class rename to Sollution and make Shunting one of its method, dalsi metoda bude postfix evaluace
//Queue*(outputQ) Solution::ShuntingYard()

//vlastni is operator fce ==> modularita nezavislo na jinych modulech
//udelat sollution jako tridy jejiz soucasti bude metodo shuntingYard a postfixevaluaton
ShuntingYard::ShuntingYard(string input, string operators, string parenthesis)
{
    this->input = input; //ted pokud udelam public metodu(interface) na get, budou mit access i z vne
    this->operators = operators;
    Queue* inputQ = ExpressionParser::Split(input, operators + parenthesis);
    inputQ->Display();
    Queue* outputQ = new Queue();
    Stack* opStack = new Stack();
    string toProcess = string();
    

    //const string input2("3 + 4 * 2 / ( 1 - 5 )");
    // 3 4 2 * 1 5 - / +

    //const string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"
    //3 4 2 × 1 5 − 2 3 ^ ^ ÷ +
    //while tokens
    while (!inputQ->isEmpty())
    {

        //Deque value(string)
        toProcess = inputQ->Deque();
        cout << "\n--------------------PROCESSING: " << toProcess << endl;
        cout << "\nBEGGINING\n";
        cout<<"op-STACKT:\n";
        opStack->Display();
        cout<<"INUPT-Q:\n";
        inputQ->Display();
        cout<<"OUTPUT-Q:\n";
        outputQ->Display();
        
        if (IsNumeric(toProcess))
        {
            //NE >convert it to num, treba uz pujde rovnou v podmince -> i outputQ pracuje s retezci -> convertovat budem az pri jejim zpracovani v postfixu
            outputQ->Enque(toProcess);
            continue;
        }

        //funkce netestuju
        
        if (this->IsOperator(toProcess[0], operators)) //BLBE Z pohledu modularity
        {   

            cout << "opsPROCESSING: " << toProcess << endl;
            cout << "!!!!!!!associate: "<< this->GetAssociate(toProcess) << endl;
            cout << "!!!!!!!prio: "<< this->GetOperatorPrio(toProcess) << endl;
            cout << "PEEK: " << opStack->GetTop() << endl;
            
            while ((!opStack->isEmpty() && this->GetOperatorPrio(toProcess) < this->GetOperatorPrio(opStack->GetTop()) 
            && opStack->GetTop().compare("(")!= 0) || (this->GetOperatorPrio(toProcess) == this->GetOperatorPrio(opStack->GetTop()) 
            && this->GetAssociate(toProcess) == left_to_right)) //zavorky a asociativita
            {
                outputQ->Enque(opStack->GetTop());
                opStack->Pop();
            }

            opStack->Push(toProcess);
            opStack->Display();

        }   
        

        //ta ktere bude vyzadovata nejaky castecny zanorovani tak pushuj dolu a jeji ukonceni hned podto
        if (toProcess.compare("(") == 0)
        {
            opStack->Push(toProcess);
        }

        if (toProcess.compare(")") == 0)
        {
            /*string temp = opStack->Pop();
            while (temp != "(")
            {
                outputQ->Enque(temp);
                temp = opStack->Pop();
            }*/
            //string tmp = string();        
            while (!opStack->isEmpty() && opStack->GetTop().compare("(") != 0)
            {
                outputQ->Enque(opStack->GetTop());
                opStack->Pop();
            }

            /*if (opStack->isEmpty() && opStack->GetTop().compare("(") != 0)
            {
                throw ExpressionException("mismatch in parenthes");
            }*/
          
            opStack->Pop();
            //toProcess = string();
        }


    }

    while (inputQ->isEmpty() && !opStack->isEmpty())
    {
        if (opStack->GetTop() == "(")
        {
            ;//throw an exepton > operator mismatch
        }
        
        outputQ->Enque(opStack->GetTop());
        opStack->Pop();
    }
    
    cout << "\nEND\n";
    cout<<"op-STACKT:\n";
    opStack->Display();
    cout<<"INUPT-Q:\n";
    inputQ->Display();
    cout<<"OUTPUT-Q:\n";
    outputQ->Display();

    outputQ->Display();
    
    //mozna ceknei ze neni prazdna
    delete inputQ;
    delete opStack;
    
}