
void PolynomialExpression::appendNode(int c, int e)
{
    Node *newNode = new Node(c, e);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *prev = NULL, *curr = head;
        while (curr != NULL && curr->exponent > e)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL && curr->exponent == e)
        {
            curr->coefficient += c;
            if (curr->coefficient == 0)
            {
                if (curr == head)
                {
                    head = curr->next;
                }
                else if (curr == tail)
                {
                    tail = prev;
                    prev->next = NULL;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
            }
            else
            {
                delete newNode;
            }
        }
        else
        {
            if (curr == head)
            {
                head = newNode;
            }
            else
            {
                prev->next = newNode;
            }
            newNode->next = curr;
            if (curr == NULL)
            {
                tail = newNode;
            }
        }
    }
}

PolynomialExpression add(PolynomialExpression exp1, PolynomialExpression exp2)
{
    PolynomialExpression result;
    Node *temp1 = exp1.head, *temp2 = exp2.head;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent == temp2->exponent)
        {
            int sum = temp1->coefficient + temp2->coefficient;
            if (sum != 0)
            {
                result.appendNode(sum, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exponent > temp2->exponent)
        {
            result.appendNode(temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else
        {
            result.appendNode(temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        result.appendNode(temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        result.appendNode(temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }
    return result;
}

PolynomialExpression getPolynomialExpression(string polynomialStr)
{
    PolynomialExpression exp;
    int len = polynomialStr.length();
    int i = 0;
    while (i < len)
    {
        int sign = 1;
        if (polynomialStr[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (polynomialStr[i] == '+')
        {
            sign = 1;
            i++;
        }
        int coefficient = 0, exponent = 0;
        while (i < len && polynomialStr[i] >= '0' && polynomialStr[i] <= '9')
        {
            coefficient = coefficient * 10 + (polynomialStr[i] - '0');
            i++;
        }
        if (i < len && polynomialStr[i] == 'x')
        {
            i++;
            if (i < len && polynomialStr[i] == '^')
            {
                i++;
                while (i < len && polynomialStr[i] >= '0' && polynomialStr[i] <= '9')
                {
                    exponent = (exponent * 10 + (polynomialStr[i]) - '0');
                    i++;
                }
            }
            else
            {
                exponent = 1;
            }
        }
        else
        {
            exponent = 0;
        }
        coefficient *= sign;
        exp.appendNode(coefficient, exponent);
    }
    return exp;
}