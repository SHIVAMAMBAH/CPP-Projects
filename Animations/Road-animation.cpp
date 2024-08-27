#include<iostream>
#include<unistd.h>

int main()
{
	int number;
	std::cout<<"Enter the number : ";
	std::cin>>number;

	while(true){
	    for(int i = 0; i<number; i++) {
		    for(int j =0; j<number; j++) {
			    if(j==((number-1)/2)) {
				    if(i==0||i==1||i==(number-1)||i==(number-2)){
				        std::cout<<"::";
				        usleep(5000);
				    }else{
				        std::cout<<"##";
				        usleep(5000);
				    }
			    }else if(j==0 || j==(number-1)) {
				    std::cout<<"#";
			    }else{
			        std::cout<<"::";
				    usleep(5000);
			    }
		    }
		    std::cout<<"\n";
	    }
	}
	
	return 0;
}
