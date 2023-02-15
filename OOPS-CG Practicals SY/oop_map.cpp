#include<iostream>
#include<map>
using namespace std;

int main(){
    // Initialization of  map
	map<string, int> m;
	//Inserting data to the map named as 'm'
	m["Maharashtra"]=100; // M-1
	//m.insert({"Keral",200}); // M-2 -- iterator error
	m["Keral"]=200;
	m["AndhraPradesh"]=300;
	m["HimachalPradesh"]=400;
	m["Gao"]=500;
	m["Chennai"]=600;
	m["Bihar"]=700;
	m["Punjab"]=800;
	m["Gujrat"]=900;
	m["Karnataka"]=1000;
	m["Telangana"]=1100;
	m["Odisha"]=1200;
	m["Assam"]=1300;
	m["ArunachalPradesh"]=1400;
	m["Manipur"]=1500;
	m["WestBengal"]=1600;
	m["UttarPradesh"]=1700;
	m["TamilNadu"]=1800;
	m["Sikkim"]=1900;
	m["Manipur"]=2000;
	
	// map<string,int>::iterator ptr;
	// for( ptr=m.begin() ; ptr!=m.end() ;ptr++){ 
	// 	// to print entire map
	// 	cout<<"Population of "<< ptr->first<<" is : "<< (*ptr).second<<endl;
	// }

	while(true){
        string str;
        char ch;
		cout<<"Enter the name of state : ";
		cin>>str;
		map<string,int>::iterator it;
		it=m.find(str);
		if(it==m.end()){
			cout<<"Not in List \n";
		}
		else{
			cout<<"Population of "<< it->first<<" is : "<< (*it).second<<endl;
			char ch;
			cout<<"Do you want to continue (y/n) : ";
		}
		cin>>ch;
		if(ch=='n')
			break;
	}
    return 0;
}