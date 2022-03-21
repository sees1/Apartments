#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>

int main(){
int n;
int m;
int k;
int j;
bool fl = false;
int buff;
std::deque <int> aplicant;
std::deque <int> apartment;
std::cin>>n>>m>>k;

for(int i = 0; i < n;i++){
	std::cin>>buff;
	aplicant.push_back(buff);
}for(int i = 0; i < m;i++){
	std::cin>>buff;
	apartment.push_back(buff);
}buff = 0;



std::sort(aplicant.begin(),aplicant.end());
std::sort(apartment.begin(),apartment.end());
int i = 0;

if(m <= n){
	while(aplicant.empty() != true ){
		if(apartment.empty() == true) break;
		if(abs(aplicant[i] - apartment[i]) <= k){
			buff++;
			aplicant.pop_front();
			apartment.pop_front();
			i = 0;
		}else{
			if(aplicant[i] > apartment[i]){
				apartment.pop_front();
				continue;
			}else{
				j = i + 1;
				
				while(aplicant.begin()+j != aplicant.end() &&
				abs(aplicant[j] - apartment[i]) > k ){
					if(aplicant[j] > apartment[i]){
						fl = true;
						break;
					}
					j++;
				}
				
				if(aplicant.begin()+j  
				!= aplicant.end()) {
					for(int k = 0;k < j;k++){
						aplicant.pop_front();
					}
					apartment.pop_front();
					if(fl != true){
						buff++;
					}
				}else{
					apartment.pop_front();
				}
			}
		}
		i = 0;
	}			
}else{
	for(int i = 0;i < n;i++){
		if(abs(aplicant[i] - apartment[i]) <= k){
			buff++;
		}
	}
}

std::cout <<buff;
}	
	


