#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main()
{   float total_cost;
    int P, Q, stock, today, dueDate, unitsDue, startDate, demand, reorderCost;
    

    for(int i=0;i<5;i++)
    {   cout<<"\n---ENTER THE INPUT OF P AND Q ---\n";
        cin>>P>>Q; //user will enter the values.
        srand(0); //for constant random values.

        startDate = 1;
        dueDate = 0;
        today = startDate;
        unitsDue = 0;
        reorderCost = 2; 
        stock = 115;
        total_cost=0;

        while(today<=180)
        {
            //If due date,  then
            if(today==dueDate)
            {
                stock+= Q; // refill stock
                unitsDue=0;
            }
            demand = rand() % 100;   //current demand of orders

            //If demand less than stock, then
            if(demand<=stock)
            {
                stock-= demand;
                total_cost+= stock*0.75; //add carrying cost.
            }
            //If demand more than stock,then 
            else
            {
                total_cost+= (demand - stock)*18; //add lost sale cost.
                stock = 0;
            }
            //If stock is lower than minimum level, 
            if(stock + unitsDue <= P)
            {
                unitsDue = Q;
                total_cost+= reorderCost*unitsDue; //restock order.
                dueDate = today+3;
            }
            today++;
        }

        cout<<"Total Cost for P= "<<P<<" and Q= "<<Q<<" is "<<total_cost<<"\n";
    }
    return 0;
}