#include<iostream>
#include<unistd.h>

int main()
{
    while(true){
        for(int i = 0;i<10;i++){
            for(int j = 0;j<i;j++){
                std::cout<<" *";
                usleep(1000);
            }
            for(int j = 0;j<(10-i);j++){
                std::cout<<"    ";
                usleep(1000);
            }
            for(int j = 0;j<i;j++){
                std::cout<<" *";
                usleep(1000);
            }
            std::cout<<"\n";
        }
        for(int i = 0;i<10;i++){
            for(int j = 0;j<(10-i);j++){
                std::cout<<" *";
                usleep(1000);
            }
            for(int j = 0;j<i;j++){
                std::cout<<"    ";
                usleep(1000);
            }
            for(int j = 0;j<(10-i);j++){
                std::cout<<" *";
                usleep(1000);
            }
            std::cout<<"\n";
        }
    }
    return 0;
}
