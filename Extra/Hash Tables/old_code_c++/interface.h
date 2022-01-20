typedef struct
{
    int ch;
    void printMenu()
    {
        hashTable h;
        memset(h.hashTable , -1  , sizeof(h.hashTable));
        while(1)
        {
            cout<<"\n\n";
            cout<<"\n1.Add data";
            cout<<"\n2.Search data.";
            cout<<"\n3.Delete data.";
            cout<<"\n4.Display.";
            cout<<"\n5.To exit.";
            cout<<"\nYour choice : ";
            cin>>ch;
            switch(ch)
            {
                case 1:h.addData();
                       break;
                case 2:h.searchData();
                       break;
                case 3:h.deleteData();
                       break;
                case 4:h.displayData();
                       break;
                case 5: exit(0);
                default:cout<<"Wrong choice ";
                          break;
            }
        }
    }
}Menu;
