#include <iostream>
#include <cmath>

using namespace std;

double matrixA [3] [3] ;
double matrixB [3] [3] ;
double matrixC [3] [3] ;
double matrixD [3] [3] ;
int rowA , colA , rowB , colB , x , y ;

long long Approximator ( double sum )
{
   if ( round (sum) == -0)
   {
       return 0 ;
   }

   else
    return round ( sum ) ;
}

long long Multiplication ( double matrixA [3] [3] , double matrixB [3] [3] )
{
    for ( int i = 0 ; i < 3 ; i ++ )
    {
        for ( int row = 0 ; row < 3 ; row ++ )
      {
          double sum = 0 ;

            for ( int col = 0 ; col < 3 ; col ++ )
            {
                 sum += matrixA [ i ] [ col ] * matrixB [ col ] [ row ]  ;
            }
        cout << Approximator ( sum ) << "\t" ;
      }
    cout << "\n" ;
    }
}

double Determinate ( double matrix [3] [3] , int row )
{
    if ( row == 2 )
    {
        long long l = ( matrix [0] [0] * matrix [1] [1] ) - ( matrix [1] [0] * matrix [0] [1] ) ;
        return l;
    }

    else
    {
        int z = 0 , q = 0 , r = 0 , y = 0 ;

        z = ( matrix [1] [1] * matrix [2] [2] ) - ( matrix [1] [2] * matrix [2] [1] ) ;
        q = ( matrix [1] [0] * matrix [2] [2] ) - ( matrix [1] [2] * matrix [2] [0] ) ;
        r = ( matrix [1] [0] * matrix [2] [1] ) - ( matrix [1] [1] * matrix [2] [0] ) ;

        y = ( matrix [0] [0] * z ) - ( matrix [0] [1] * q ) + ( matrix [0] [2] * r ) ;

        return y ;
    }

}

double AinverseB ( double matrixA [3] [3] , double matrixB [3] [3] )
{
    double s = Determinate ( matrixB , rowB ) ;
    long long det = 0 ;
    double submatrix [3] [3] ;

    for ( int q = 0 ; q < 3 ; q ++ )
    {
         for ( int w = 0 ; w < 3 ; w ++ )
        {
            int subi = 0 ;

            for (int i = 0 ; i < 3 ; i ++ )
            {
                int subj = 0 ;

                if ( i == q )
                    continue ;

                for ( int j = 0 ; j < 3 ; j ++ )
                {
                    if ( j == w )
                        continue ;

                    submatrix [subi] [subj] = matrixB [i] [j] ;
                    subj ++ ;
                }
                subi ++ ;
            }

            matrixC [q] [w] = ( pow( (-1) , w + q ) * Determinate ( submatrix , rowB - 1 ) ) ;
        }
    }

    for ( int i = 0 ; i < 3 ; i ++ )
    {
        for ( int j = 0 ; j < 3 ; j ++)
        {
            matrixD [i] [j] = matrixC [j] [i] / s  ;
        }
    }

    Multiplication ( matrixA , matrixD ) ;
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
             Multiplication ( matrixA , matrixB ) ;
            break ;

        case 4 :
            if ( Determinate ( matrixB , rowB ) == 0)
            {
                cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                break ;
            }
            else
                AinverseB ( matrixA , matrixB ) ;

            break ;

        case 5 :
           cout << Determinate ( matrixA , rowA ) << "\n" ;
            break ;

        case 6 :
            cout << Determinate ( matrixB , rowB ) << "\n" ;
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
