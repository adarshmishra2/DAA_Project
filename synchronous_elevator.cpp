#include<iostream>
#include<windows.h>
using namespace std;
bool findlift(int A[],int lift)
{
    for(int i=0; i<10; i++)
        if(A[i]==lift)return false;
    return true;
}
bool check(int f, int A[],int lift)
{
   if(A[f]==0 && findlift(A,lift))
   return true;
   return false;

}
int call(int floor, int arr[],int lift)
{
    if(check(floor,arr,lift)==true)
        {
            cout<<"\nPlease wait LIFT - "<<lift<<" is coming.....\n";
            Sleep(3000);
            cout<<"\nLift reached\n";
            arr[floor]=lift;
            cout<<"\nCall Lift 0-yes  \tRelease Lift 1-yes  \n";
            int resp=99;
            cin>>resp;
            if(resp ==1)
            {
              int resp;
               arr[floor]=0;
               cout<<"\nLift-"<<lift<<" Releases\n";
               cout<<"\nCall Lift 1-yes";
               cin>>resp;
               if(resp==1)
               {
                   cout<<"\nCalling from floor(0-9) and lift-(1 or 2)  :-  ";
                   cin>>floor;
                   call(floor,arr,lift);
               }
            }
            else if(resp == 0) {

                   cout<<"\nCalling from floor(0-9) and lift-(1 or 2)  :-  ";
                    cin>>floor>>lift;
                    call(floor,arr,lift);
            }
        }
        else
        {       cout<<"\nOther lift is on your floor OR Lift is in use please call again \n";
                cout<<"\nRelease lift 1-yes : \t Call lift yes-2";
                int tres=0;
                cin>>tres;
                if(tres==1)
            {
               int resp;
               arr[floor]=0;
               cout<<"\nLift-"<<lift<<" Releases\n";
               cout<<"\nCall Lift 1-yes";
               cin>>resp;
               if(resp==1)
               {
                   cout<<"\nCalling from floor(0-9) and lift-(1 or 2)  :-  ";
                   cin>>floor;
                   call(floor,arr,lift);
               }
            }
       }
}
int main()
{
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
    int lift_1=1,lift_2=2,res=1,floor,lift;
 while(1){
        cout<<"Do yo want Call lift 0-No  1-Yes : ";
        cin>>res;
        if(res==1)
        {
        cout<<"Calling from floor(0-9) and lift-(1 or 2)  :-  ";
        cin>>floor>>lift;
        call(floor,arr,lift);
        }
    }
}
