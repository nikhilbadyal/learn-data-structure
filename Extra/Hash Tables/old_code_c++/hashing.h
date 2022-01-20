#define size 100

int h(int );
typedef struct{
     bool b;
     int pos;
}SearchResult;
int h(int x)
{
    return x%size;
}
typedef struct{
    int hashTable[size];
    void addData();
    SearchResult searchData();
    void displayData();
    void deleteData();

}hashTable;



void hashTable::addData()
{
    int temp;
    cout<<"Enter the value you want to insert .\n";
    cin>>temp;
    int key  = h(temp);
    if(hashTable[key]== -1)
    {
        hashTable[key] = temp;
    }
    else{
            if( key < size - 1)
            {
                for(int i = key+1  ; i < size ; ++ i )
                {
                    if(hashTable[i] == -1)
                    {
                        hashTable[i] = temp;
                        return ;
                       // break;
                    }
                }
            }
            for(int i = 0  ; i < key ; ++ i )
            {
                if(hashTable[i] == -1)
                {
                    hashTable[i] = temp;
                    return ;
                    //break;
                }
            }
    }
}
void hashTable::deleteData()
{
    SearchResult check =searchData();
    if(check.b )
    {
        cout<<"Item deleted.\n";
        hashTable[check.pos] = -1;
    }

}
void hashTable::displayData()
{
    for(int i = 0 ; i < size -1 ; ++i)
    {
        cout<<hashTable[i]<<"  ";
    }
    cout<<endl;
}
SearchResult hashTable::searchData()
{
    int flag = 0;
    int temp;
    cout<<"Enter the value .\n";
    cin>>temp;
    int key = h(temp);
    if(hashTable[key] == temp)
    {
        flag = 1;
    }
    else{
        for(int i  = key+1 ; i < size - 1 ;++i)
        {
            if(hashTable[i]== temp)
            {
                flag = 1;
                break;
            }
        }
    }
    if(!flag)
    {
        for(int i = 0 ; i< key; ++i)
        {
            if(hashTable[i]== temp)
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"Value found at "<<key+1<<endl;
        SearchResult s ;
        s.b = true;
         s.pos = key;
        return s;
    }
    else{
        cout<<"Value not found.\n";
        SearchResult s ;
        s.b = false;
         s.pos = key;
        return s;
    }
}
