#include<iostream>
#include<cstdlib>
#include<time.h>
#include<unistd.h>
#include<chrono>

int main()
{
    char arr[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
                    'p','q','r','s','t','u','v','w','x','y','z','\0'};
    char symbols[23] = {'~','!','@','#','$','%','^','&','*','(',')','-','='
                        ,'+','<','>','{','}','?',':','.','`','\0'};
    
    std::cout<<"Selct from the following"<<"\n";
    std::cout<<"w: for words only"<<"\n";
    std::cout<<"s: for symbols only"<<"\n";
    std::cout<<"sw or ws : for words + symbols"<<"\n";
    std::string select;
    while(true){
        std::cin>>select;
        if(select == "w"|| select=="s"|| select=="sw"|| select=="ws"){
            break;
        }else{
            std::cout<<"Please choose the correct option."<<"\n";
            std::cout<<"Choose Again"<<"\n";
        }
    }
    int size;
    std::cout<<"Enter the size of the string : ";
    while(true){
        std::cin>>size;
        if(size>0){
            break;
        }else{
            std::cout<<"Size must be positive."<<"\n";
            std::cout<<"Choose Again"<<"\n";
        }
    }
    int number;
    std::cout<<"Enter the number of strings you want to generate : ";
    while(true){
        std::cin>>number;
        if(number>0){
            break;
        }else{
            std::cout<<"Number must be positiive."<<"\n";
            std::cout<<"Choose Again"<<"\n";
        }
    }
    
    auto now = std::chrono::high_resolution_clock::now();
    auto seed = now.time_since_epoch().count();
    srand(static_cast<unsigned int>(seed));
    
    while(number!=0){
        if(select=="w"){
            for(int i = 0;i<size;i++){
                std::cout<<arr[rand()%26];
            }
        }else if(select =="s"){
            for(int i = 0;i<size;i++){
                std::cout<<symbols[rand()%23];
            }
        }else if(select == "sw"|| select=="ws"){
            for(int i = 0;i<size;i++){
                if(rand()%2==0){
                    std::cout<<arr[rand()%27];
                }else{
                    std::cout<<symbols[rand()%23];
                }
            }
        }
        std::cout<<"\n";
        usleep(100000);
        number--;
        
    }
    return 0;
}
