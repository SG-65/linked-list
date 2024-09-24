#include<iostream>
using namespace std;
class node{
  public:
    int data;
    node* next;
     node(int val){
        data=val;
        next=nullptr;
     }
};
class linked_list{
     public:
      node* head;
       linked_list(){
         head=nullptr;
       }
    void insert(int val,int pos){
          node* new_node=new node(val);
     node* temp=head;
     int count=1;
     if(pos==1){
        insert_head(val);
        return;
     }
     
     if(temp->next==nullptr){
        insert_tail(val);
        return;
     }
     while(count<pos-1){
        temp=temp->next;
        count++;
     }
     new_node->next=temp->next;
     temp->next=new_node;
    }
     void delete_at_head(){
          node* temp=head;
       head=head->next;
       cout<<"the deleted element is:"<<temp->data<<endl;
       delete temp;
     }
      void delete_at_tail(){
           node* temp=head;
      while(temp->next->next!=nullptr){
        temp=temp->next;
      }
       cout<<"the deleted element is:"<<temp->next->data<<endl;
       temp->next=nullptr;
       delete temp->next;
       }
       void delete_at_any_pos(int pos){
        node* temp=head;
    int count=1;
    if(pos==1){
      delete_head();
      return;
    }
    if(temp->next==nullptr){
      delete_tail();
      return;
    }
    while(count<pos-1){
      temp=temp->next;
      count++;
    }
    node* del_node=temp->next;
    temp->next=temp->next->next;
    cout<<"the deleted element is:"<<del_node->data<<endl;
    delete del_node;
   }
       void display(){
          node* temp=head;
          while(temp!=NULL){
          cout<<temp->data<<" ";
          temp=temp->next;
      }
      cout<<endl;
   }
    
};
int main(){
    linked_list ll;
    int val;ch,pos;
    do{
      cout<<"1->insert\n2->delete head\n3->delete tail\n4->delete position\n5->display\n6->exit"<<endl;
      cout<<"the choice is:";
      cin>>ch;
       switch(ch){
          case 1:
              cout<<"the inserted element is:";
              cin>>val;
              ll.insert(val);
              break;
          case 2:
              ll.delete_at_head();
              break;
          case 3:
              ll.delete_at_tail();
              break;
          case 4:
              cout<<"the deleted position is:";
              cin>>pos;
              ll.delete_at_any_position(pos);
              break;
          case 5:
              ll.display();
              break;
          case 6:
            cout<<"exiting...";
            exit(0);
            break;
          default:
             cout<<"invalid choice";
       }
    }while(ch!=6);
    return 0;
}