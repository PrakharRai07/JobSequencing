//
//  main.cpp
//  JobSequencing
//
//  Created by Prakhar Rai on 28/09/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool slots[100];

struct Job {
    char id;
    int profit;
    int deadline;
};

bool compareProfit(Job a, Job b){
    
    if(a.profit > b.profit)
        return true;
    
        return false;
}

int maxDeadline(Job jobs[],int n){
    int max;
    max=jobs[0].deadline;
    int i;
    
    for(i=0;i<n;i++){
    
        if(max<jobs[i].deadline)
            max=jobs[i].deadline;
    }
    
    return max;
}

void freeSpaces(int n){  //n has value of mDeadline
    int i;
    
    for(i=0;i<n;i++){
        slots[i] = false;
    }

}

void JobSequencing(Job jobs[],int mDeadline,int n){
    
    char *timeSlots = new char[mDeadline];
    int i,dtemp;
    
    for(i=0;i<n;i++) {
        dtemp = jobs[i].deadline;
    
        while(dtemp >= 0) {
            if(slots[dtemp]==false) {
                timeSlots[dtemp-1] = jobs[i].id;
                slots[dtemp] = true;
                break;
            }
            else
            dtemp--;
        }
        
    }
    cout<<"Order of job Sequencing is :";
    for(i=0;i<mDeadline;i++){
        cout<<"\n "<<i+1<<" position : "<<timeSlots[i];
    }
}

int main(){
    Job jobs[10];
    int n,i;
    int mDeadline;
    cout<<"\n Enter the number of jobs : ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"\n Enter job Id : ";
        cin>>jobs[i].id;
        cout<<"\n Enter the profit :";
        cin>>jobs[i].profit;
        cout<<"\n Enter the deadline :";
        cin>>jobs[i].deadline;
    }
    sort(jobs, jobs+n, compareProfit);
    
    mDeadline = maxDeadline(jobs,n);
    
    freeSpaces(mDeadline);
    
    JobSequencing(jobs,mDeadline,n);
  /*  cout<<"\n Max deadline is :"<<mDeadline;
    for(i=0;i<n;i++){
        cout<<"\n Enter job Id : "<<jobs[i].id;
        cout<<"\n Enter the profit :"<<jobs[i].profit;
        cout<<"\n Enter the deadline :"<<jobs[i].deadline;
    }
    */
}
