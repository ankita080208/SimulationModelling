#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int num_of_cust =7; //number of customers
    int table[num_of_cust][7]; //Table to store values
   
    int totals[7]; //Table to store sum of all columns
    
    //Set total array values to zero
    memset(totals, 0, sizeof(totals));

    cout<<"\nEnter arrival time and service time of the customers -- \n";
    
    //Input variables- arrival time, service time
    for(int i=0; i<num_of_cust; i++)
    {
        cin>>table[i][1]>>table[i][3];
        table[i][0] = i+1;
        //summing their values
        totals[1]+=table[i][1];
        totals[3]+=table[i][3];
    }

    //Find service begin column
    table[0][2] = table[0][1];
    totals[2] += table[0][2];

    //next service begin is later of next's arrival time and current's service end time
    for(int i=1; i<num_of_cust; i++)
    {
        table[i][2] = max(table[i][1], table[i-1][2]+table[i-1][3]);
        totals[2]+=table[i][2];
    }

    //service end, wait columns
    int nonWaitCust=0;
    for(int i=0; i<num_of_cust; i++)
    {
        //Service end
        table[i][4]= table[i][2] + table[i][3];
        totals[4]+=table[i][4];
        //wait = service begin - arrival
        table[i][5]= table[i][2] - table[i][1];
        totals[5]+=table[i][5];
        if(table[i][5]>0) nonWaitCust++;
    }

    //Idle server = next arrival time - current service end time
    for(int i=0; i<num_of_cust-1; i++)
    {
        table[i][6] = max(table[i+1][1] - table[i][4], 0);
        totals[6]+=table[i][6];
    }
    table[num_of_cust-1][6]=0;
    totals[6]+=table[num_of_cust-1][6];

    cout<<"\n\t--Table Created--\nCustomer(0), Arrival time(1), service begin(2), service time(3), service end(4), wait(5), server idle time(6)\n";
    
    //Print table
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<num_of_cust; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<"\nTotal values of the columns:\n";
    //Print totals
    for(int i=0; i<7; i++)
        cout<<totals[i]<<" ";

    //Finding the values using direct formulae as per in slide 2 given
    cout<<"\n\n\t--Finding the values using direct formulae as per in slide 2 given--";
    float value1 = float(totals[5])/float(num_of_cust);
    float value2 = float(nonWaitCust)/float(num_of_cust);
    float value3 = float(totals[6])/float(totals[3]);
    float value4 = float(totals[3])/float(num_of_cust);
    float value5 = float(totals[1])/float(num_of_cust);
    float value6 = float(table[num_of_cust-1][4])/float(num_of_cust);

    //printing values calculated from above
    cout<<"\n\nAverage Waiting time per customer: "<<value1;
    cout<<"\nProbability of a customer to wait in the queue: "<<value2;
    cout<<"\nIdle time for servers: "<<value3;
    cout<<"\nAverage service time: "<<value4;
    cout<<"\nAverage arrival time: "<<value5;
    cout<<"\nAverage time customer spent in system: "<<value6;
    cout<<"\n";
    
    //Finding the values using direct formulae as per in slide 3 given
    cout<<"\n\t--Finding the values using direct formulae as per in slide 3 given--";
    float S = (value5/(value5-value4)); //value4 is λ = 11.8 and value5 is μ = 1.5
    float Q = (S-(value5/value4));
    float W = (S-(1/value4));
    float T = (W+(1/value4));
    float Q1= (value4/(value5-value4));
    float P = (1-(value5/value4));
    
    
    //printing the values calculated from above
    cout<<"\n\nAverage Number in System: "<<S;
    // cout<<"\nAverage Number in Queue: "<<Q;
    cout<<"\nAverage Queuing: "<<W;
    cout<<"\nAverage time in the System: "<<T;
    cout<<"\nAverage number in the Queue when it is not empty: "<<Q1;
    // cout<<"\nProbability of Number customer in the System: "<<P;
    cout<<"\n";
    
    return 0;
}
