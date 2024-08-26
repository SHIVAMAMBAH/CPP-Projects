#include<iostream>
#include<chrono>
#include<cstdlib>

int main()
{
    char letters[27] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                        'm','n','o','p','q','r','s','t','u','v','w','x',
                        'y','z'};
                        
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
            std::cout<<letters[rand()%27];
        }
        std::cout<<" ";
        number--;
    }
    
    return 0;
}
