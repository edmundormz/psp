#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>


using namespace std;


int counter = 0;
float sum = 0;
float mean = 0;
float std_dev = 0;

struct node{
    float data;
    struct node *next;
};

struct list{
    struct node *start;
};


void InitList(struct list *sList);
void push(struct list *sList, float data);
void print(struct list *sList);
void calc_mean(struct list *sList);
void calc_std_dev(struct list *sList);


void InitList(struct list *sList)
{
    sList->start = NULL;
}

 /* Adds a value to the front of the list */
void push(struct list *sList, float data)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = sList->start;
    sList->start = p;
}

/* Prints the list */
void print(struct list *sList)
{
    struct node *p = sList->start;
    while(p != NULL) {
        printf("%f\n", p->data);
        p = p->next;
    }
}

void calc_mean(struct list *sList){
    
    struct node *p = sList->start;
    while(p != NULL){
        sum += p->data;
        p = p->next;
        counter += 1;
    }
    mean = sum/counter;
    //return mean;
}

void calc_std_dev(struct list *sList){
    float acum = 0;
    struct node *p = sList->start;
    while(p != NULL){
        acum += pow((p->data - mean),2);
        p = p->next;
        //cout << acum << endl;
    }
    std_dev = sqrt((acum)/(counter - 1));
    //return std_dev;
}

int main(){   

    float input;
    //float output;

    struct list MyList;
    InitList(&MyList);
 
    cout << "Enter numbers, press '0' key when finished to continue" << endl;
    while(true){
    cin >> input;
    if(input == 0){
        break;
        }
    else{
        push(&MyList, input);
        }
    cout << "Enter next number" << endl;
    }
    cout << "The data set is:" << endl;
    print(&MyList);
    calc_mean(&MyList);
    cout << "The mean is: " << mean << endl;
    //output = calc_std_dev(&MyList);
    calc_std_dev(&MyList);
    cout << "The standard deviation is: " << std_dev << endl;
    return 0;
}




