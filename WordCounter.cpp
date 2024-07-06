#include<iostream>
#include<string>

int main()
{
	std::string String;
	
	std::cout<<"Enter the string:"<<"\n";
	std::getline(std::cin,String);
	std::cout<<String<<"\n";
	
	int i = 0;
	int count = 0;
	int dotCount = 0;
	int smallLettersCount= 0;
	
	while(++i<String.length()){
		if(String[i]==' '){
			count++;
		}else if(String[i] == '.'){
			dotCount++;
		}else if(97<=int(String[i])<=122){
			smallLettersCount++;
		}
	}
	
	std::cout<<"Total number of words : "<<count+1<<"\n";
	std::cout<<"Total number of characters(with full stop) : "<<String.length()-count<<"\n";
	std::cout<<"Total number of characters(without full stop): "<<String.length()-count-dotCount<<"\n";
	std::cout<<"Total Number of small letters: "<<smallLettersCount<<"\n";
		
	return 0;
}
