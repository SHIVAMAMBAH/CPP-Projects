#include<iostream>
#include<chrono>
#include<cstdlib>

int main()
{
    char consonants[22] = {'b','c','d','f','g','h','j','k','l',
                        'm','n','p','q','r','s','t','v','w','x',
                        'y','z','\0'};
    
    char vowels[6] = {'a','e','i','o','u','\0'};
                        
    int number;
    std::cout<<"Enter the number of words : ";
    
    while(true){
        std::cin>>number;
        if(number>0){
            break;
        }else{
            std::cout<<"Number should be positive"<<"\n";
            std::cout<<"Please try again"<<"\n";
        }
    }
    
    auto now = std::chrono::high_resolution_clock::now();
    auto seed = now.time_since_epoch().count();
    srand(static_cast<unsigned int>(seed));
    
    while(number!=0){
        for(int i = 0;i<(rand()%(16)+5);i++){
            if(rand()%2==0){
                std::cout<<consonants[rand()%21];
            }else{
                std::cout<<vowels[rand()%5];
            }
        }
        std::cout<<" ";
        number--;
    }
    
    return 0;
}
