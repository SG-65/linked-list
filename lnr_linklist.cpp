#include<iostream>
using namespace std;

class node{
   public:
      int val;
      node* next;
       node(int data){
          val=data;
          next= NULL;
       }
};
class linkedlist{
 public:
   node* head;
     linkedlist(){
        head=NULL;
     }

   void insertathead(int data){
       node* new_node= new node(data);
       if(head==nullptr){
        head=new_node;
        return;
    }
        new_node->next=head;
        head=new_node;
   }

   void insertattail(int data){
       node* new_node= new node(data);
       node* temp=head;
        if(temp==NULL){
           new_node->next=head;
           head=new_node;
        }
          while(temp->next!=NULL){
            temp=temp->next;
          }
       temp->next=new_node;
   }

   void insertatanyposition(int data,int pos){
     node* new_node=new node(data);
     node* temp=head;
     int count=1;
     if(pos==1){
        insert_head(data);
        return;
     }
     
     if(temp->next==nullptr){
        insert_tail(data);
        return;
     }
     while(count<pos-1){
        temp=temp->next;
        count++;
     }
     new_node->next=temp->next;
     temp->next=new_node;
   }

   void display(){
     node* temp=head;
      while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
      cout<<endl;
   }
};
int main(){
  linkedlist ll;
    int choice,val,pos;
     do{
       cout<<"1->insert at head"<<endl;
       cout<<"2->insert at tail"<<endl;
       cout<<"3->insert at any position"<<endl;
       cout<<"4->display"<<endl;
       cout<<"5->exit"<<endl;
        cout<<"the choice is:";
         cin>>choice;
          switch(choice){
             case 1:
                cout<<"the inserted element is:";
                 cin>>val;
                 ll.insertathead(val);
                  break;
             case 2:
                 cout<<"the inserted element is:";
                 cin>>val;
                 ll.insertattail(val);
                 break;
             case 3:
                  cout<<"the inserted element is:";
                   cin>>val;
                  cout<<"the posistion is:";
                   cin>>pos;
                    ll.insertatanyposition(val,pos);
                     break;
             case 4:
               cout<<"the elements in list are:";
               ll.display();
                break;
             case 5:
                cout<<"exiting";
                 exit(0);
                 break;
          }
     }while(choice!=5);
  return 0;
}