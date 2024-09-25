#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};

class doubly_ll{
   public:
    node* head;
    node* tail;
    doubly_ll(){
        head=nullptr;
        tail=nullptr;
    }
  void display(){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
  }
  void insert_at_start(int val){
      node* new_node=new node(val);
      if(head==nullptr){
           head=new_node;
           tail=new_node;
           return;
      }
      new_node->next=head;
      head->prev=new_node;
      head=new_node;
  }
  void insert_at_end(int val){
    node* new_node=new node(val);
    if(tail==nullptr){
        tail=new_node;
        head=new_node;

    }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
  }
  void insert_at_pos(int val,int pos){
    node* new_node=new node(val);
    if(pos==1){
      if(head==nullptr)
         head=new_node;
      new_node->next=head;
      head->prev=new_node;
      head=new_node;
      return;
    }
      node* temp=head;
      int count=1;
      while(count<(pos-1)){
          temp=temp->next;
          count++;
      }
     new_node->next=temp->next;
     temp->next=new_node;
     new_node->prev=temp;
     temp->next->prev=new_node; 
  }
  void delete_at_start(){
    if(head==nullptr)
             return;
    node* temp=head;
    head=head->next;
    head->prev=nullptr;
    free(temp);
  }
  void delete_at_end(){
    if(tail==nullptr)
        return;
    node* temp=tail;
    tail=tail->prev;
    tail->next=nullptr;
    free(temp);
  }
  void delete_at_pos(int pos){
    if(pos==1){
         if(head==nullptr)
             return;
    node* temp=head;
    head=head->next;
    head->prev=nullptr;
    free(temp);
    return;
    }
    node*temp=head;
    int count=1;
    while(count<pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
  }

};
int main(){
    doubly_ll dll;
    dll.insert_at_start(1);
    dll.display();
    dll.insert_at_end(2);
    dll.display();
    dll.insert_at_end(8);
    dll.display();
    dll.insert_at_pos(3,1);
    dll.insert_at_pos(4,3);
    dll.insert_at_pos(3,2);
    dll.display();
    dll.delete_at_pos();
     dll.display();
    return 0;
}