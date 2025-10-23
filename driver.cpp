#include "factory.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>    

int main(){
    Queue<int>* queue1 = QueueFactory::getQueue<int>();
    queue1->enqueue(10);
    queue1->enqueue(20);

    Queue<std::string>* queue2 = QueueFactory::getQueue<std::string>(5);
    queue2->enqueue("Hi my name is shawn");
    queue2->enqueue("I am 19 years old");

    delete queue1;  
    delete queue2; 


//EXAMPLE 1
    Queue<int>* waitingLine = QueueFactory::getQueue<int>(10);
    srand(time(0));
    int customer = 1;
    for (int i = 0; i < 100; i++) {
        int num = (rand() % 3) - 1; 
        
        if(num < 0){
            if(!waitingLine->isEmpty()){
            waitingLine->dequeue();
            std::cout << "Person number " << i << " has been served" << std::endl;
            } else{
                std::cout << " no customers to serve" << std::endl;
            }
        } else {
            if(waitingLine->getLength() < 10){
            std::cout << "Person number " << i << " joined the line" << std::endl;
            waitingLine -> enqueue(customer);
            customer++;
        } else{
            std::cout << "Person number " << i << " left because the line is full" << std::endl;
            customer++;
        }
    }
    }

delete waitingLine;



  //EXAMPLE 2
Queue<int>* bankLine = QueueFactory::getQueue<int>();
srand(time(0));
customer = 1;
for (int i = 0; i < 100; i++) {
int num = (rand() % 4) - 1;     
        if(num < 0){
            if(!bankLine->isEmpty()){
            bankLine->dequeue();
            std::cout << "Person number " << i << "has been served" << std::endl;
            } else{
                std::cout << "no customers to serve" << std::endl;
            }
        } else {     
            std::cout << "Person number " << i << "joined the line" << std::endl;
            bankLine -> enqueue(customer);
            customer++;
        }
    }

delete bankLine;
return 0;
}