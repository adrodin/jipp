#include <iostream>
#include <pthread.h>
#include <windows.h>
#define NUMBER_OF_PHILOSOPHERS 5
using namespace std;

pthread_t philosophers[NUMBER_OF_PHILOSOPHERS];
pthread_mutex_t forks[NUMBER_OF_PHILOSOPHERS];

void *eat(void *number)
{
    int num = *(int*)number;
    pthread_mutex_t* left_fork = &forks[num];
    pthread_mutex_t* right_fork = &forks[(num + 1) % NUMBER_OF_PHILOSOPHERS];
    cout<<"philosopher "<<num+1<<" thinking"<<endl;

    pthread_mutex_lock(left_fork);
    pthread_mutex_lock(right_fork);

    cout<<"philosopher "<<num+1<<" eatting"<< endl;
    Sleep(2000);

    pthread_mutex_unlock(left_fork);
    pthread_mutex_unlock(right_fork);

    cout<<"philosopher "<<num+1<<" finished"<<endl;

    return nullptr;
}

int main(){
    for (auto &fork : forks){
        pthread_mutex_init(&fork, nullptr);
    }

    for (int i=0;i<NUMBER_OF_PHILOSOPHERS;i++){
        pthread_create(&philosophers[i], nullptr, eat, (void *)&i);
        Sleep(3);
    }
    for (auto &p : philosophers){
        pthread_join(p, nullptr);
    }

    return 0;
}