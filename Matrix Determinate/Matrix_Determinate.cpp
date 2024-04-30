#include <iostream>
#include <cmath>

using namespace std;

int matrixA [3] [3] ;
int matrixB [3] [3] ;
int rowA , colA , rowB , colB , x , y ;

int Determinate ( int matrix [3] [3] )
{
    int z = 0 , q = 0 , r = 0 , y = 0 ;

    z = ( matrix [1] [1] * matrix [2] [2] ) - ( matrix [1] [2] * matrix [2] [1] ) ;
    q = ( matrix [1] [0] * matrix [2] [2] ) - ( matrix [1] [2] * matrix [2] [0] ) ;
    r = ( matrix [1] [0] * matrix [2] [1] ) - ( matrix [1] [1] * matrix [2] [0] ) ;

    y = ( matrix [0] [0] * z ) - ( matrix [0] [1] * q ) + ( matrix [0] [2] * r ) ;

    cout << y << "\n" ;
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
            Determinate ( matrixA ) ;
            break ;

        case 6 :
            Determinate ( matrixB ) ;
            break ;


        case 7 :
            cout << " Thank you! " ;
            break ;
    }
}

int main()
{

    int rowA , colA , rowB , colB , x ;

    cout << " Please enter dimensions of Matrix A: " << "\n" ;
    cin >> rowA >> colA ;
    cout << " Please enter dimensions of Matrix B: " << "\n" ;
    cin >> rowB >> colB ;

    cout << " Please enter values of Matrix A: " << "\n" ;

    for ( int row = 0 ; row < 3 ; row ++ )
       {
            for ( int col = 0 ; col < 3 ; col ++ )
            {
                cin >> matrixA [ row ] [ col ] ;
            }
       }


    cout << " Please enter values of Matrix B: " << "\n" ;

    for ( int row = 0 ; row < 3 ; row ++ )
      {
            for ( int col = 0 ; col < 3 ; col ++ )
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




