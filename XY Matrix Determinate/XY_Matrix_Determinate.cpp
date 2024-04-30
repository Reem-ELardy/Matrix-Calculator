
#include <iostream>
#include <cmath>

using namespace std;

double matrixA [11] [11] ;
double matrixB [11] [11] ;
int rowA , colA , rowB , colB , x ;

long long Determinate ( double matrix [11] [11] , int row )
{
    long long det = 0 ;
    double submatrix [11] [11] ;

    if ( row == 1 )
    {
        return matrix [0] [0] ;
    }

    else if ( row == 2 )
    {
        long long y = ( matrix [0] [0] * matrix [1] [1] ) - ( matrix [1] [0] * matrix [0] [1] ) ;
        return y;
    }
    else
    {
        for ( int w = 0 ; w < row ; w ++ )
        {
            int subi = 0 ;

            for (int i = 1 ; i < row ; i ++ )
            {
                int subj = 0 ;

                for ( int j = 0 ; j < row ; j ++ )
                {
                    if ( j == w )
                        continue ;

                    submatrix [subi] [subj] = matrix [i] [j] ;
                    subj ++ ;
                }
                subi ++ ;
            }

            det = det + ( pow( (-1) , w ) * matrix [0] [w] * Determinate ( submatrix , (row - 1) ) ) ;
        }

       return det ;
    }
}



void choose ( int x )
{
     switch ( x )
    {
        case 1 :
            //Addition (  matrixA , matrixB ) ;
            cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 2 :
           // Subtraction ( matrixA , matrixB ) ;
           cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 3 :
            cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 4 :
            // A*Inverse_Matrix ( matrixB ) ;
            cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 5 :
            if ( rowA == colA )
            {
               cout << Determinate ( matrixA , rowA ) << "\n" ;
            }

            else
            {
                 cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                 break ;
            }
            break ;

        case 6 :
            if ( rowB == colB )
            {
               cout << Determinate ( matrixB , rowB ) << "\n" ;
            }

            else
            {
                 cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                 break ;
            }
            break ;


        case 7 :
            cout << " Thank you! " ;
            break ;
    }
}

int main()
{
    cout << " Please enter dimensions of Matrix A: " << "\n" ;
    cin >> rowA >> colA ;
    cout << " Please enter dimensions of Matrix B: " << "\n" ;
    cin >> rowB >> colB ;

    cout << " Please enter values of Matrix A: " << "\n" ;

    for ( int row = 0 ; row < rowA ; row ++ )
       {
            for ( int col = 0 ; col < colA ; col ++ )
            {
                cin >> matrixA [ row ] [ col ] ;
            }
       }


    cout << " Please enter values of Matrix B: " << "\n" ;

    for ( int row = 0 ; row < rowB ; row ++ )
      {
            for ( int col = 0 ; col < colB ; col ++ )
            {
                cin >> matrixB [ row ] [ col ] ;
            }
      }

      for ( int i = 0 ; ; i ++ )
      {
          cout << " Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit): " << "\n" ;
          cin >> x ;
          choose (x) ;

          if ( x == 7)  break;

          else continue ;
      }
}
