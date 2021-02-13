#include "calculator.h"
void Calculator::digitButtonPressed(int pNum)
{
   if (flag_frac==0)
   {
       double mNextNumber = displayValue*10+pNum;
       if (displayValue < mMaxValue)
       {
           displayValue = mNextNumber;
           emit valueChanged(displayValue);
       }
       else
           return;
   }
   else
   {
       double mNextNumber = displayValue+pNum*pow(10,(-1)*flag_frac);
       ++flag_frac;
       if (displayValue < mMaxValue)
       {
           displayValue = mNextNumber;
           emit valueChanged(displayValue);
       }
       else
           return;
   }
}
void Calculator::operationButtonPressed(const QString(value))
{
    if (value == "C")
    {
        displayValue = 0;
        mSum = 0;
        last_operation = "none";
        flag_count = 0;
        flag_frac = 0;
        frac_pow = 1;
        emit valueChanged(displayValue);
    }
    else if (value == "+")
    {
        flag_frac = 0;
        frac_pow = 1;
        if (last_operation == "none")
        {
            mSum = displayValue;
        }
        else if(flag_count==0)
        {
            flag_count = 1;
            this->operationButtonPressed(last_operation);
            flag_count=0;
        }
        else
        {
            mSum+=displayValue;
        }
        last_operation='+';

        displayValue = 0;//готовы принимать новое значение

        //как запомнить следующее число?
    }
    else if (value == "-")
    {
        flag_frac = 0;
        frac_pow = 1;
        if (last_operation == "none")
        {
            mSum = displayValue;
        }
        else if(flag_count==0)
        {
            flag_count = 1;
            this->operationButtonPressed(last_operation);
            flag_count=0;
        }
        else
        {
            mSum-=displayValue;
        }
        last_operation='-';

        displayValue = 0;//готовы принимать новое значение

    }
    else if (value == "*")
    {
        flag_frac = 0;
        frac_pow = 1;
        if (last_operation == "none")
        {
            mSum = displayValue;
        }
        else if(flag_count==0)
        {
            flag_count = 1;
            this->operationButtonPressed(last_operation);
            flag_count=0;
        }
        else
        {
            mSum*=displayValue;
        }
        last_operation='*';

        displayValue = 0;//готовы принимать новое значение

    }
    else if (value == "/")
    {
        flag_frac = 0;
        frac_pow = 1;
        if (last_operation == "none")
        {
            mSum = displayValue;
        }
        else if(flag_count==0)
        {
            flag_count = 1;
            this->operationButtonPressed(last_operation);
            flag_count=0;
        }
        else
        {
           if (displayValue!=0)
           {
               mSum=mSum/displayValue;
           }
        }
        last_operation='/';

        displayValue = 0;//готовы принимать новое значение

    }
    else if (value == "=")
    {
        flag_count=1;
        this->operationButtonPressed(last_operation);
        displayValue = mSum;
        flag_count = 0;
        flag_frac = 0;
        frac_pow = 1;
        last_operation = "none";
        emit valueChanged(displayValue);
    }
    else if (value == ".")
    {
        flag_frac = 1;
    }
}
