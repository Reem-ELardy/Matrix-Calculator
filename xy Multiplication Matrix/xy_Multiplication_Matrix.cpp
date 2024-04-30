#include <iostream>

using namespace std;

int matrixA [11] [11] ;
int matrixB [11] [11] ;
int rowA , colA , rowB , colB , x ;

long long Multiplication ( int matrixA [11] [11] , int matrixB [11] [11] )
{
    for ( int i = 0 ; i < rowA ; i ++ )
    {
        for ( int row = 0 ; row < colB ; row ++ )
      {
          long long sum = 0 ;

            for ( int col = 0 ; col < colA ; col ++ )
            {
                 sum += ( matrixA [ i ] [ col ] * matrixB [ col ] [ row ] )  ;

            }
        cout << sum << "\t" ;
      }
    cout << "\n" ;
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
            //Subtraction ( matrixA , matrixB ) ;
             cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 3 :
            if ( colA == rowB ) Multiplication ( matrixA , matrixB );
            else
            {
                cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                break;
            }
            break ;

        case 4 :
            // A*Inverse_Matrix ( matrixB ) ;
            cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 5 :
           // Determinate ( matrixA , matrixB ) ;
           cout << "The operation you chose is invalid for the given matrices." << "\n" ;
            break ;

        case 6 :
           // Determinate ( matrixA , matrixB ) ;
           cout << "The operation you chose is invalid for the given matrices." << "\n" ;

            break;

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






