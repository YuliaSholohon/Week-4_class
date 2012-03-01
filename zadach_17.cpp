#include <iostream>
#include <iomanip>

using namespace std;
 
class CMountain
{
        char *name; // імя
        float height; // висота
 
        public:
		char  *Getname() {return name;}
		float  & GetHigh() {return  height;} 
        CMountain(int ); // Конструктор
		   
        void Show(); // Вивід інформациї на екран
        float sort(CMountain,CMountain);        
        ~CMountain() ;
private:
	void Del();
	void Construct(int);
                
};
 CMountain:: CMountain(int n=20) // Конструктор
 {
	 Construct(n);
 };
 void CMountain::Construct(int n ){
	  name=new char[n];
                // Ввід данних:
                cout<<" Name "; 
				cin>>name;
                cout<<" Height "; 
				cin>>height;

				while(height<0){
                cout<<" Enter right height "; 
				cin>>height;
				}
                cout<<endl;
 };

 void CMountain:: Show() // Вивід інформациї на екран
 {
	 cout<<setw(15)<<name<<" | "<<setw(0)<<setw(5)<<height<<" | "<<setw(0)<<endl;
 };
 CMountain::~CMountain()
 {
	 Del();
 };
 void  CMountain::Del(){
	 if(name){
		 delete[]name;
		 name=NULL;
	 }
 }
float CMountain::sort(CMountain A,CMountain B)
{
	if(A.height>B.height){
		return A.height;}else{
			return B.height;}
}
int main()
{       
        int const k=3;
       CMountain Mountain[k];
		 cout<<setw(15)<<"Name "<<" | "<<setw(0)<<setw(5)<<"High"<<" | "<<setw(0)<<endl;
        for(int i=0; i<k; i++){
        Mountain[i].Show();
		}
		float max=0;int pos;
		for(int i=0;i<k;i++){
			if(Mountain[i].GetHigh()>max){
			max=Mountain[i].GetHigh();
			pos=i;
		}		
		}
		cout<<"The biggest mountain is"<<endl;
		 cout<<setw(15)<<"Name "<<" | "<<setw(0)<<setw(5)<<"High"<<" | "<<setw(0)<<endl;
		Mountain[pos].Show();
        return 0;
}