#include <iostream>

#include <stdlib.h>
#include<time.h>
#include <stdio.h>     
using namespace std;
class CMatrix
{
private:
    int Rows;
    int Cols;
    int ** Data;
   
       
public:
    CMatrix(int Row=2,int Col=2);
	CMatrix(const CMatrix & Matrix);
    ~CMatrix();
    int GetAt(int Row,int Col);
    void SetAt(int Row,int Col,int Data);
    void Display();
   void trans();
    void Fill();
};

CMatrix::CMatrix(int Row,int Col)
{
	Rows = Row;
	Cols = Col;
	
	Data= new int * [Rows];
	for (int j=0;j<Rows;j++){
		Data[j] = new int[Cols];
		for (int i=0;i<Cols;i++){
			Data[j][i]=0;
		}
	}
	return;
};
CMatrix::CMatrix(const CMatrix & M){
	Rows=M.Rows;
	Cols=M.Cols;
	Data= new int * [Rows];
	for (int j=0;j<Rows;j++){
		Data[j] = new int[Cols];
		for (int i=0;i<Cols;i++){
			Data[j][i]=M.Data[j][i];
		}
	}
	return;
}
CMatrix::~CMatrix()
{
	for (int j=0;j<Rows;j++){
		delete Data[j];
	}
   delete [] Data;
   
};

int CMatrix::GetAt(int Row,int Col)
{
	if (Row < 0 || Row > Rows)
		Row=0;
	if (Col < 0 || Col > Cols)
		Col=0;

	return Data[Row][Col]; 
};

void CMatrix::SetAt(int Row, int Col,int Dani)
{
	if (Row < 0 || Row > Rows)
		Row=0;
	if (Col < 0 || Col > Cols)
		Col=0;
	Data[Row][Col]=Dani;
	

}

void CMatrix::Display()
{
	printf("\n Matrix \n");
	for (int j=0;j<Rows;j++){
		
		for (int i=0;i<Cols;i++){
			cout<<Data[j][i]<<" ";
		}
		cout<<endl;
	}
	return;
}

void CMatrix::trans()
{
	int i,j;int result=0; 
	int** a = new int*[Rows];
  for(i = 0; i < Rows; i++)
       a[i] = new int[Cols];
	for(i=0;i<Rows;i++){
		for(j=0;j<Cols;j++){
			a[i][j]=Data[i][j];
		}
	}
	
	for(i=0;i<Rows;i++){
		for(j=i;j<Cols;j++){
		result=a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=result;
		}
	}
		cout<<"Transposed matrix"<<endl;
        for(i=0;i<Rows;i++){
		for(j=0;j<Cols;j++){
			cout<<" "<<a[i][j];
		}cout<<endl;
      }
delete []a;
}
	
	

void CMatrix::Fill()
{
	srand( (unsigned)time( NULL ) );
	for (int j=0;j<Rows;j++){
		for (int i=0;i<Cols;i++){
			Data[j][i]=(int)rand()%10;
		}
	}
	return;
	
}
int main()
{

	const int Col=3;

	const int Row=3;
	CMatrix A(Row,Col);
	CMatrix B;
	CMatrix C=A;
	A.Fill();
	A.Display();
	A.trans();
	
	

	
	cout<<"Default"<<endl;
	B.Fill();
	B.Display();
	B.trans();
	
	cout<<"Copy"<<endl;
	C.Fill();
	C.Display();
	C.trans();
	
	return 0;

}