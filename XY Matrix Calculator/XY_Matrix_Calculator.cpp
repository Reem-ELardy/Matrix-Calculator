#include <iostream>
#include <cmath>

using namespace std;

double matrixA [11] [11] ;
double matrixB [11] [11] ;
double matrixC [11] [11] ;
double matrixD [11] [11] ;
int rowA , colA , rowB , colB , x ;

long long Approximator ( double sum )
{
   if ( round (sum) == -0)
   {
       return 0 ;
   }

   else
    return round ( sum ) ;
}

long long  Addition ( double matrixA [11] [11] , double matrixB [11] [11] )
{
     for ( int row = 0 ; row < rowA ; row ++ )
      {
            for ( int col = 0 ; col < colA ; col ++ )
            {
                cout << matrixA [ row ] [ col ] + matrixB [ row ] [ col ] << "\t" ;
            }
        cout << "\n" ;
      }
}

long long Subtraction ( double matrixA [11] [11] , double matrixB [11] [11] )
{
     for ( int row = 0 ; row < rowA ; row ++ )
      {
            for ( int col = 0 ; col < colA ; col ++ )
            {
                cout << matrixA [ row ] [ col ] - matrixB [ row ] [ col ] << "\t" ;
            }
        cout << "\n" ;
      }
}

long long  Multiplication ( double matrixA [11] [11] , double matrixB [11] [11] )
{
    for ( int i = 0 ; i < rowA ; i ++ )
    {
        for ( int row = 0 ; row < colB ; row ++ )
      {
          double sum = 0 ;

            for ( int col = 0 ; col < colA ; col ++ )
            {
                 sum += ( matrixA [ i ] [ col ] * matrixB [ col ] [ row ] )  ;

            }
        cout << Approximator ( sum ) << "\t" ;
      }
    cout << "\n" ;
    }

}

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

            det += ( pow( (-1) , w ) * matrix [0] [w] * Determinate ( submatrix , (row - 1) ) ) ;
        }

       return det ;
    }
}

double AinverseB ( double matrixA [11] [11] , double matrixB [11] [11] )
{
    double s = Determinate ( matrixB , rowB ) ;
    double sub_matrix [11] [11] ;

    for ( int q = 0 ; q < colB ; q ++ )
    {
         for ( int w = 0 ; w < colB ; w ++ )
        {
            int subi = 0 ;

            for (int i = 0 ; i < colB ; i ++ )
            {
                int subj = 0 ;

                if ( i == q )
                    continue ;

                for ( int j = 0 ; j < colB ; j ++ )
                {
                    if ( j == w )
                        continue ;

                    sub_matrix [subi] [subj] = matrixB [i] [j] ;
                    subj ++ ;
                }
                subi ++ ;
            }

            matrixC [q] [w] =  pow( (-1) , w + q ) * Determinate ( sub_matrix , rowB - 1 )  ;
        }
    }

    for ( int i = 0 ; i < rowB ; i ++ )
    {
        for ( int j = 0 ; j < rowB ; j ++)
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
            if ( rowA == rowB && colA == colB )
                    Addition (  matrixA , matrixB ) ;
            else
            {
                 cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                 break ;
            }
            break ;

        case 2 :
           if ( rowA == rowB && colA == colB )
                Subtraction ( matrixA , matrixB ) ;
            else
            {
                cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                break ;
            }
            break ;

        case 3 :
            if ( colA == rowB )
                Multiplication ( matrixA , matrixB );
            else
            {
                cout << "The operation you chose is invalid for the given matrices." << "\n" ;
                break;
            }
            break ;

        case 4 :
            if ( Determinate ( matrixB , rowB ) != 0 && colA == rowB && rowB == colB )
                 AinverseB ( matrixA , matrixB ) ;
           else
           {
               cout << "The operation you chose is invalid for the given matrices." << "\n" ;
               break ;
           }
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
