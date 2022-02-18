// #include "hw1.h"
#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

// man neveshtam ina ro ke in zire
namespace algebra
{
using Matrix = std::vector<std::vector<double>>;

Matrix zero (int n,int m)
{
// int n {1};
// int m {2};

using Matrix = std::vector<std::vector<double>>;

Matrix a ;

vector<double> vect;
 

for (int i=0 ; i < m ;i++)
{
    vect.push_back(0);
}
for (int j=0; j < n ; j++)
{
    a.push_back(vect);   


}

return a;

}

Matrix ones(int n, int m)
{
using Matrix = std::vector<std::vector<double>>;

Matrix a ;

vector<double> vect;
 

for (int i=0 ; i < m ;i++)
{
    vect.push_back(1);
}
for (int j=0; j < n ; j++)
{
    a.push_back(vect);   


}
return a ;

}

Matrix random(size_t n, size_t m, double min, double max)
{
    Matrix a ;
    vector<double> vect;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(min, max); 

        for (int i=0 ; i < m ; i++)
        {
                vect.push_back(0);
        }
    
        for (int j=0; j < n ; j++)
        {
            for (int i=0 ; i < m ;i++)
            {
                vect[i]=dist(mt);
            }

            a.push_back(vect);
            
        }
        
    
     return a ;
        
}

void show(const Matrix& matrix){
int rows = matrix. size() ;
int cols = matrix[0].size();

for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j)
    {
        cout << setprecision(2) ;
        cout << setw(5) ;
        cout << matrix[i][j];
        
    }
        cout << endl ;

}
    
}

Matrix multiply(const Matrix& matrix, double c)
{
Matrix result;

int rows = matrix. size();
int cols = matrix[0]. size();

for(int i=0;i<rows;i++)    
{    
    for(int j=0;j<cols;j++)    
    {    
        result [i][j]=0;   
        //nemidoonam in harekat doroste ya bayad push back konam 
           
        result[i][j]+=matrix[i][j]*c;    
               
    }       
}    
    return result;
}


Matrix multiply(const Matrix& matrix1, const Matrix& matrix2)
{
    Matrix result;

    int rows1 = matrix1. size();
    int cols1 = matrix1[0]. size();

    int rows2 = matrix2. size();
    int cols2 = matrix2[0]. size();


    if (cols1!=rows2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

       
    }

    
    // Initializing elements of matrix mult to 0.
    for(int i = 0; i < rows1; ++i)
        for(int j = 0; j < cols2; ++j)
        {
            result[i][j]=0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(int i = 0; i < rows1; ++i)
        for(int j = 0; j < cols2; ++j)
            for(int k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }

    // // Displaying the multiplication of two matrix.
    // cout << endl << "Output Matrix: " << endl;
    // for(int i = 0; i < rows1; ++i)
    // for(int j = 0; j < cols2; ++j)
    // {
    //     cout << " " << result[i][j];
    //     if(j == cols2-1)
    //         cout << endl;
    // }
    return result;
}

Matrix sum(const Matrix& matrix, double c){

Matrix result,zerom;
int rows = matrix. size();
int cols = matrix[0]. size();

zerom = zero(rows,cols);

for(int i=0;i<rows;i++)    
{    
    for(int j=0;j<cols;j++)    
    {    
        
        //nemidoonam in harekat doroste ya bayad push back konam 
           
        zerom[i][j]+=matrix[i][j]+c;    
               
    }       
}    
    return zerom;


}

Matrix sum(const Matrix& matrix1, const Matrix& matrix2)
{
    int rows1 = matrix1. size();
    int cols1 = matrix1[0]. size();
    int rows2 = matrix2. size();
    int cols2 = matrix2[0]. size();

    Matrix result,zerom;
    if (cols1!=cols2 & rows1!=rows2)
    {
        cout << "Error! matrix dont have the same dimentions";

       
    }
    
    zerom = zero(rows1,cols1);

    for(int i=0;i<rows1;i++)    
    {    
         for(int j=0;j<cols1;j++)    
        {    
        
        //nemidoonam in harekat doroste ya bayad push back konam 
           
            zerom[i][j]+=matrix1[i][j]+matrix2[i][j];    
               
        }       
    }    
    return zerom;


}
Matrix transpose(const Matrix& matrix)
{
    int rows = matrix. size();
    int cols = matrix[0]. size();
    Matrix A,B;
    A=zero(rows,cols);
    B=zero(cols,rows);
    A=matrix;
    int i, j;
    for (i = 0; i < cols; i++)
        for (j = 0; j < rows; j++)
            B[i][j] = A[j][i];

    return B;

}
Matrix minor(const Matrix& matrix, size_t n, size_t m)
{
    //age faghat 2*2 bashe
    size_t rows = matrix. size();
    size_t cols = matrix[0]. size();
    Matrix A;
    A=zero(rows-1,cols-1);
    int crow =0;
    int ccol =0;
    for (size_t i = 0; i < rows; i++)
    {
        
        for (size_t j = 0; j < cols; j++)
        {
            
            if ( n!=i && m!=j)
            {
                A[crow][ccol]=matrix[i][j];
                ccol++;
                if (ccol==(cols-1))
                {
                    ccol=0;
                    crow++;
                }
                
            }

        }
        
        
    }
    
    return A;
     
    
    
}
double determinant(const Matrix& matrix){
    double det =0;
    Matrix getmin;
    size_t rows = matrix. size();
    size_t cols = matrix[0]. size();
    int sign = 1;
    if (rows == 1 && cols==1){
        det=matrix[0][0];
        return det; 
    }
    getmin=zero(rows-1,cols-1);
    for (int f = 0; f < cols; f++)
    {
        // Getting Cofactor of mat[0][f]
        getmin=minor(matrix,0,f);
        det += sign * matrix[0][f]* determinant(getmin);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }    
    
return det;
}
 Matrix inverse(const Matrix& matrix){
    size_t rows = matrix. size();
    size_t cols = matrix[0]. size();
    Matrix inv;
    inv=zero(rows,cols);
    Matrix invout;
    invout=zero(rows,cols);
    Matrix minerplaceholder;
    minerplaceholder=zero(rows-1,cols-1);
    int sign=1;
    if (rows!=cols){
         cout<<"this matrix does have an inverse"<<endl;
         return matrix;
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
        
            inv[j][i]=sign*determinant(minor(matrix,i,j));
           cout<<i<<"    "<<j<<endl;
            sign=-1*sign;
    }
    
    }
    show(inv);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
           
            invout[i][j]=(inv[i][j]/determinant(matrix));
        }
    }
    
    return invout;    
     
 }
  Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis=0){
      //=0 esh ghalat nist?
      //age cols ha baham barabar nabashan fekr konam segmentation error bokhorim
    size_t rows1 = matrix1. size();
    size_t cols1 = matrix1[0]. size();
    size_t rows2 = matrix2. size();
    size_t cols2 = matrix2[0]. size();
    if (axis==0)
    {
        Matrix result ;
        for (size_t i = 0; i < rows1; i++)
        {
            vector<double> vec;
        for (size_t j = 0; j < cols1; j++)
        {
            
            vec.push_back(matrix1[i][j]);
            
        }
        result.push_back(vec);
       
            
        }
        for (size_t i = 0; i < rows2; i++)
        {
            vector<double> vec;
        for (size_t j = 0; j < cols2; j++)
        {
           vec.push_back(matrix2[i][j]);
            
        }
        result.push_back(vec);
       
            
        }
        
      return result ;  
    }
      
  }

}


