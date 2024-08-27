#include<iostream>
#include<unistd.h>

int main()
{
    int number;
    std::cout<<"Enter the number : ";
    std::cin>>number;
    
    while(true){
        for(int i = 0;i<number;i++){
            for(int j = 0;j<i;j++){
                std::cout<<" *";
                usleep(1000);
            }
            for(int j = 0;j<(number-1-i);j++){
                std::cout<<"####";
                usleep(1000);
            }
            for(int j = 0;j<i;j++){
                std::cout<<" *";
                usleep(1000);
            }
            std::cout<<"\n";
        }
        for(int i = 0;i<4;i++){
            for(int j=0;j<(2*number-2);j++){
                std::cout<<" *";
            }
            std::cout<<"\n";
        }
        for(int i = 0;i<number;i++){
            for(int j = 0;j<(number-1-i);j++){
                std::cout<<" *";
                usleep(1000);
            }
            for(int j = 0;j<i;j++){
                std::cout<<"####";
                usleep(1000);
            }
            for(int j = 0;j<(number-1-i);j++){
                std::cout<<" *";
                usleep(1000);
            }
            std::cout<<"\n";
        }
    }
    
    return 0;
}
