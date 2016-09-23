#include<iostream>
using namespace std;

class MatrixOperation
{

public:
	int i,j;
	template <class tpMatrixType>
	void MatrixAddition(tpMatrixType MatrixOne[3][3], tpMatrixType MatrixTwo[3][3])
	{
		tpMatrixType MatrixSum[3][3];

		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				MatrixSum[i][j] = MatrixOne[i][j] + MatrixTwo[i][j];

			}

		}

		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				cout<<MatrixSum[i][j]<<" ";

			}

			cout<<endl;

		}

	}

};

int main()
{

	int iRepeat,iChoice;
	MatrixOperation moMatrix;
	int iMatrixOne[3][3],iMatrixTwo[3][3],i,j;
	float fMatrixOne[3][3],fMatrixTwo[3][3];

	do
	{
		cout<<"1. Integer Matrix\n";
		cout<<"2. Float Matrix\n";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter Matrix 1\n";
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++)
					{
						cin>>iMatrixOne[i][j];
					}

				}
				cout<<"Enter Matrix 2\n";
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++)
					{
						cin>>iMatrixTwo[i][j];
					}

				}
				moMatrix.MatrixAddition(iMatrixOne,iMatrixTwo);

			break;

			case 2:
				cout<<"Enter Matrix 1\n";
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++)
					{
						cin>>fMatrixOne[i][j];
					}

				}
				cout<<"Enter Matrix 2\n";
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++)
					{
						cin>>fMatrixTwo[i][j];
					}

				}
				moMatrix.MatrixAddition(fMatrixOne,fMatrixTwo);

		}
		cout<<"\n Repeat? 1.Yes 2.No\n";
		cin>>iRepeat;

	}while(iRepeat==1);

	return 0;
}



