#include<iostream>
#include<unistd.h>

int main()
{
    int number;
    std::cout<<"Enter the number : ";
    std::cin>>number;
    while(true){
       for(int i = 0;i<number;i++){
            for(int j = 0;j<number;j++){
                if(i+j==(number-1)||i==j){
                    std::cout<<"##";
                    usleep(10000);
                }else{
                    std::cout<<"::";
                    usleep(10000);
                }
            }
            std::cout<<"\n";
        }
        for(int i = 0;i<number;i++){
            for(int j = 0;j<number;j++){
                if(i==j||i+j==(number-1)){
                    std::cout<<"##";
                    usleep(10000);
                }else{
                    std::cout<<"::";
                    usleep(10000);
                }
            }
            std::cout<<"\n";
        } 
    }
    return 0;
}
