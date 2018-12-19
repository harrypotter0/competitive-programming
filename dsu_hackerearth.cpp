
//modified initialize function:
void initialize( int Arr[ ], int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i;
        size[ i ] = 1;
    }
}

// O(log*N) ==> recursive log log log log .....(log N)
// finding root of an element.
// modified root function.
int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)    //chase parent of current element until it reaches root.
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;  //path compression
        i = Arr[ i ]; 
    }
    return i;
}

/*modified union function where we connect the elements by changing 
the root of one of the element */
void weighted-union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}

bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}

