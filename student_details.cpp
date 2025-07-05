#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
void edit_data(){    //edit file data at any line  all done
    cout<<"enter student full name for edit"<<endl;
    string name;
    bool file_stutas=false;
    getline(cin >> ws, name);  //get name without buffer
    ifstream file("score.txt" ,ios::in);
    ofstream newfile("demo.txt", ios::out);
    string data;
    while (getline(file , data))
    {
        if(data==name)
        {   cout<<"name found including your name enter how many line's you want to edit"<<endl;
            int n;
            cin>>n;        //for user choice how many line's want to edit
            cin.ignore();    //clear buffer
            for(int i=0 ; i<n ; i++){
            getline(cin , data);
            newfile<<data<<endl;
            }
            for(int i=0 ; i<n ; i++){
               getline(file , data);
                }
        file_stutas=true;   //it means file is open
        }
        else{
            newfile<<data<<endl;     //copy remaining data to new file
        }

      
    }
    if(!file_stutas){    //if name not found 
        cout<<"Wrong input data not found\ntry again..."<<endl;
    }
    newfile.close();
    file.close();
    remove("score.txt");
    rename("demo.txt"  , "score.txt");
    cout<<"data edited"<<endl;  
   
}
void read_file(){   //to read the file data
    bool n=false;
    ifstream file("score.txt", ios::in);
    string data;
    while(getline(file, data)){
     cout<<data<<"\n";
     n=true;      //for confirm that file have data
    }
    if(!n){
        cout<<"No data found"<<endl;
    }
    file.close();
}
void search_data(int n){    //to search data done 
    bool file_status=false;
    cout<<"enter student name"<<endl;
    string name;
    string old_data;
    cin.ignore();      //clear all buffer
    getline(cin , name);
    ifstream file("score.txt", ios::in);
    while(getline(file , old_data)){    //find name
        if(old_data==name){
            cout<<"\nEnter person data is:-"<<endl;
            for(int i=0 ; i<n ;i++){
                cout<<old_data<<endl;
                getline(file , old_data);
            }
           file_status=true;
            break;

        }
        
    }
    if(!file_status){          //for data not found
        cout<<"No data found"<<endl;
    }
    file.close();
    
}
void add_data(int n){      //add new data to end of the file done
    ofstream file("score.txt" , ios::app);
    cout<<"enter exit for forcefully stop and save"<<endl;
    string data;
    cin.ignore();
    for(int i=0 ;i<n ;i++){
        getline(cin , data);
       if(data=="exit"){      //to end loop
        break;
       }
       else
        file<<data<<endl;
        
    }
    cout<<"data saved"<<endl;
    file.close();
}
void delete_file(){    //for delete file
    cout<<"press 1 for confirm and 0 for cancle"<<endl;
    int f;
    cin>>f;
    if(f==1){          //for security
    ofstream file("score.txt" , ios::out);
    file.close();
    cout<<"data deleted successfully"<<endl;
    }
    else if(f==0){
        cout<<"canceled"<<endl;
    }
}
int main(){
    while(1){
    int n,k,a;
    cout<<"how many types of data for a person"<<endl;
    cout<<"for example name and age press 2"<<endl;
    cout<<"input=";
    cin>>a;
    cout<<"\t Please enter\n1. for search data \n2. for add new \n3. delete all old data \n4. for edit data \n5. for read file \n6. for cancel"<<endl;
    cin>>n;
    switch (n)
    {
    case 1://done
       search_data(a);
        break;
    case 2://only
       add_data(a);
       break;
    case 3: //ok
       delete_file();
       break;
    case 4: //ok
    edit_data();
    break;
    case 5://ok
    read_file();
      break;
    case 6:
    cout<<"canceled"<<endl;
    break;
    default:
    cout<<"invalid input"<<endl;
        break;
    }
    cout<<"enter 0 for exit or 1 for continue"<<endl;
    cin>>k;
    if(k==0){break;}
   
}


    return 0;
    
}
