#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const double EPSILON = 1e-10; // machine precision, if Amat[1][1] value is smaller than that code interprets as zero.
int n;

void partial_pivoting(double** Amat, double* bmat, int k){
    int max_row = k;
    double max_value = abs(Amat[k][k]);
    
    for (int i=k+1;i<n ;i++){
        if (abs(Amat[i][k])>max_value){

            max_value=abs(Amat[i][k]);
            max_row=i;
        }
    }

//swapping rows in order for the higher pivot to go up

    if (max_row !=k){
        swap(Amat[k],Amat[max_row]);
        swap(bmat[k],bmat[max_row]);
    }
}

int main (int argc, char *argv[])
{
   //controlling the number of inputs

   if(argc!=4){
       cout << "Wrong number of inputs!";
       return 0;
    }

   //read the file and create the "cikti" in order to use for writing to the text file

   ifstream myf (argv[1]);
   ifstream myv (argv[2]);
   ofstream cikti (argv[3]);
   string mystr;

   n = 0;

   //finding the dimension of the matrices

   if(myf.is_open()){
       while(getline(myf,mystr)){
           n++;
       }
    }
   
   //reset the open file

   myf.clear();
   myf.seekg(0);
  
//dynamically creating 2-dimensional matrix and fill it with the values inside A.txt

   double** Amat;
   Amat = new double* [n];
   for (int i=0; i<n; i++){
       Amat[i] = new double[n];
       for (int j=0; j<n; j++){
           myf >> Amat[i][j];
        }
    }

   double* bmat;
   bmat = new double [n];

   for (int i=0; i<n; i++){
        myv >> bmat[i];
    }
     //print the 2D matrix.
    cout << "Matrix A is: " << endl;
   for (int i=0; i<n; i++){
       for (int j=0; j<n; j++){
           cout << Amat[i][j] << " ";
       }
       cout << endl;
    }
    cout << endl;
    cout << "Matrix b is: "<< endl << "[";
    for (int i=0; i<n; i++){
        cout << bmat[i]<<" ";
    }
    cout << "]^T" << endl << endl;

//CONDITION NUMBER
//finding 1 and infinity norms in 2x2 cases previous to finding the condition numbers of the matrix. 
//By doing that, we want to find out whether the problem is ill or well conditioned 
    
    if (n == 2){
        double normAmat1, normAmatInv1, normAmatINF, normAmatInvINF;
        double determinant = Amat[0][0] * Amat[1][1] - Amat[0][1] * Amat[1][0];
        normAmat1 = max(abs(Amat[0][0]) + abs(Amat[1][0]), abs(Amat[0][1]) + abs(Amat[1][1]));
        normAmatINF = max(abs(Amat[0][0]) + abs(Amat[0][1]), abs(Amat[1][0]) + abs(Amat[1][1]));
        normAmatInv1 = max(abs(Amat[1][1]/determinant)+ abs(-1*Amat[1][0]/determinant), abs(-1*Amat[0][1]/determinant)+abs(Amat[0][0]/determinant));
        normAmatInvINF = max(abs(Amat[1][1]/determinant)+ abs(-1*Amat[0][1]/determinant), abs(-1*Amat[1][0]/determinant)+abs(Amat[0][0]/determinant));

        cout << "1-Condition number is: " << normAmat1 * normAmatInv1 << endl;
        cout << "Infinity-Condition number is: " << normAmatINF * normAmatInvINF << endl << endl;
        
    }   

    //gaussian elimination with partial pivoting for each row

    for (int k = 0 ; k < n-1 ; k++){
        partial_pivoting(Amat, bmat, k);
        for (int i = k+1 ; i < n ; i++){
            double carp = Amat[i][k]/Amat[k][k];
            for (int j=k ; j<n ; j++){
                Amat[i][j]-= carp * Amat[k][j];
            }
            bmat[i] -= carp * bmat[k];
        }
    }

    //checking for the singularity, if one of our diagonal entries is zero, it implies the
    //fact that A is singular; other than that if it is so close to zero, that means it is nearly singular

    for (int i = 0; i < n; i++){
        if (abs(Amat[i][i]) <= EPSILON){cout << "Matrix is singular";return 1;}
    }

    //realizing the back substitution process in order to find X

    double* x;
    x = new double [n];

    for (int i = n - 1; i >= 0; --i) {
        x[i] = bmat[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= Amat[i][j] * x[j];
        }
        x[i] /= Amat[i][i]; 
    }

    //printing the x values to the x.txt file and also printing to the terminal

    cout <<"SOLUTION VECTOR X:"<< endl << endl << "[";

    for (int i=0; i<n; i++){
        cikti << x[i] << "\n";
        cout << x[i] <<" ";
    }

     cout << "]^T" << endl;
     
}
