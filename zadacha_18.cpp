#include <iostream>
#include <iomanip>

using namespace std;
 
class CGroup
{
        char *name; // імя
        float height; // висота
		char female;
public:
          char  *Getname() {return name;}
         char  & Getfemale() {return female;}
          float  & GetHigh() {return  height;} 
        CGroup(int ); // Конструктор
		   
        void Show(); // Вивід інформациї на екран
        ~CGroup() ;
private:
	void Del();
	void Construct(int);
};
/////////////////////////////////////////////////////////////////
 CGroup:: CGroup(int n=20) // Конструктор
 {
	 Construct(n);
 };
 ///////////////////////////////////////////////////////////////
 void CGroup::Construct(int n){
	 name=new char[n];
                // Ввід данних:
                cout<<" Name "; 
				cin>>name;
				cout<<"Enter female (m/w or M/W) ";
				cin>>female;
				while(female!='m' && female !='w'&& female !='W'&& female !='M'){
					cout<<"Enter female (m/w or M/W) ";
				cin>>female;
				}
                cout<<" Height "; 
				cin>>height;

				while((height<0) || (height>3)){
                cout<<" Enter right height "; 
				cin>>height;
				}
                cout<<endl;
 };

  ///////////////////////////////////////////////////////////////
 void CGroup:: Show() // Вивід інформациї на екран
 {
	 cout<<setw(15)<<name<<" | "<<setw(0)<<setw(5)<<height<<" | "<<setw(0)<<setw(5)<<female<<" | "<<setw(0)<<endl;
 };
  ///////////////////////////////////////////////////////////////
 CGroup::~CGroup()
 {
	 Del();
 };
  ///////////////////////////////////////////////////////////////
 void CGroup::Del(){
	 if(name){
		 delete[]name;
		 name=NULL;
	 }
 };
  ///////////////////////////////////////////////////////////////

 int same_height(CGroup A[],int k);
 int hightest_man(CGroup A[],int k);
 float average_woman(CGroup A[],int k);
  ///////////////////////////////////////////////////////////////
int main()
{       
        int const k=3;
       CGroup Group[k];
		 cout<<setw(15)<<"Name "<<" | "<<setw(0)<<setw(5)<<"High"<<" | "<<setw(0)<<setw(5)<<"Female"<<" | "<<setw(0)<<endl;
        for(int i=0; i<k; i++){
        Group[i].Show();
		}
		
		if(same_height(Group,k)){
			cout<<"There are persons which have the same height "<<endl;
		}else{
			cout<<"There are no persons which have the same height "<<endl;
		}
		int pos= hightest_man(Group,k);
		cout<<"The highest man is "<<Group[pos].Getname()<<"   the height is "<<Group[pos].GetHigh()<<endl;
		cout<<"The average height of women is  "<< average_woman(Group,k)<<endl;
		
        return 0;
}
 ///////////////////////////////////////////////////////////////////////////
int same_height(CGroup A[],int k)
{
	 for(int i=0;i<k;i++)  { 
    for(int j=i+1;j<k;j++){ 
		if(A[i].GetHigh() == A[j].GetHigh()){ 
             return 1;
		}
	}
	 }
	 return 0;
}
 ///////////////////////////////////////////////////////////////
int hightest_man(CGroup A[],int k){
	float max=0;int pos;
		for(int i=0; i<k; i++){
			if((A[i].Getfemale()=='m')||(A[i].Getfemale()=='M')){
				if(A[i].GetHigh()>max){
			max=A[i].GetHigh();
			pos=i;
				}	
			}
		}
		return pos;
}
float average_woman(CGroup A[],int k)
{
	float woman_height=0;float count=0;float average=0;
		for(int i=0;i<k;i++){
				if((A[i].Getfemale()=='w')||(A[i].Getfemale()=='W')){
					woman_height+=A[i].GetHigh();
					count++;
				}
		}
		average=woman_height/count;
		return average;
}
