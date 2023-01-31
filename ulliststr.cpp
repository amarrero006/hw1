#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

using namespace std;

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
    numNodes_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}

int ULListStr::numNodes(){
    return numNodes_;
}

string const & ULListStr:: back() const {
    return tail_->val[tail_->last - 1];
}

string const & ULListStr:: front() const {
    return head_->val[head_->first];
}

string* ULListStr::getValAtLoc(size_t loc) const {
    // Error case.
    if(loc >= size_){
        return NULL;
    }
    // The algorithm here works by using a temporary pointer to iterate through 
    // items as is necessary. The "sofar" variable tracks how many used or "actual" 
    // indexes have been iterated through and thereby determining 
    // whether or not a transition to the next Item is needed.
    // The "current" variable will track the relative location of the current Item's
    // starting point. Simple arithmatic is used to then compute the index
    // of the string pointer to be returned. 


    // Case where Item iteration is necessary.
    else{
        string* result;
        Item* temp = head_;
        int sofar = 0;
        sofar = (temp->last - temp->first) - 1;
        if(loc > sofar){
            int current = 0;
            while(loc > sofar){
                temp = temp->next;
                current = sofar + 1;
                sofar+= (temp->last - temp->first);
            }
                int index = temp->first + ((loc - current));
                result = &(temp->val[index]);

                return result;
        }
        // Trivial case.
        else{
            result = &temp->val[temp->first + loc];
            return result;
        }

    }
}

void ULListStr::push_back(const std::string& val){
    // Empty list
    if(head_ == nullptr){
        Item* added = new Item();
        numNodes_++;
        head_ = tail_ = added;
        size_++;
        added->val[0] = val;
        added->last++;
    }
    // Trivial addition
    else{
        if(tail_ -> last != 10) {
            tail_->val[tail_->last] = val;
            tail_->last++;
            size_++;
        }
        //Case where newly allocated item is necessary.
        else{
            Item* added = new Item();
            numNodes_++;
            tail_->next = added;
            added->prev = tail_;
            added->next = nullptr;
            tail_ = added;
            added->val[added->first] = val;
            added->last++;
            size_++;
        }
    }
}

void ULListStr::pop_front(){
  //Empty list
    if(head_ == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    else{
      //One item to the left
        if(head_->last == 1 && head_-> first == 0){
          //tail_->val[0] = nullptr;
          head_->last = 0;
          head_->first = 0;
          size_--;
        }
      //One item to the right
        else if(head_->last == 10 && head_->first == 9){
         // tail_->val[9] = nullptr;
          head_->last = 0;
          head_->first = 0;
          size_--; 
        }
      //All other cases
        else{
          head_->first++;
          size_--;
        }

      //Deallocation cases

        //Case of more than one node when head is to be deallocated
        if(head_->first == 0 && head_->last == 0){
          if(numNodes_ > 1){
            Item* temp = head_;
            head_ = head_->next;
            head_->prev = nullptr;
            delete temp;
            numNodes_--;
          }
          //Case of deallocating the final node
          else{
            Item* temp = head_;
            head_ = nullptr;
            tail_ = nullptr;
            delete temp;
            numNodes_--;
          }
        }
    }
}

void ULListStr::pop_back() {
  //Empty list
    if(head_ == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    else{
      //One item to the left
        if(tail_->last == 1){
          //tail_->val[0] = nullptr;
          tail_->last = 0;
          size_--;
        }
      //One item to the right
        else if(tail_->last == 10 && tail_->first == 9){
         // tail_->val[9] = nullptr;
          tail_->last = 0;
          tail_->first = 0;
          size_--; 
        }
      //All other cases
        else{
          tail_->last--;
          size_--;
        }
      
      //Deallocation cases

        //Case of more than one node when head is to be deallocated
        if(tail_->first == 0 && tail_->last == 0){
          if(numNodes_ != 1){
            tail_->prev->next = nullptr;
            Item* temp = tail_;
            tail_ = tail_->prev;
            delete temp;
            numNodes_--;
          }
          //Case of deallocating the final node
          else{
            Item* temp = tail_;
            head_ = nullptr;
            tail_ = nullptr;
            delete temp;
            numNodes_--;
          }
        }
    }
}


void ULListStr::push_front(const std::string &val) {
  //Empty list
    if(head_ == nullptr){
        Item* added = new Item();
        numNodes_++;
        head_ = added;
        tail_ = added;
        size_++;
        added->val[0] = val;
        added->last++;
    }

    else {
        //Trivial case
        if (head_->first != 0) {
            head_->val[head_->first - 1] = val;
            head_->first--;
            size_++;
        } else {
        //Case of a necessary allocation of new Item
            Item *added = new Item();
            numNodes_++;
            added->val[9] = val;
            added->last = 10;
            added->first = 9;
            size_++;
            added->prev = nullptr;
            added->next = head_;
            head_->prev = added;
            head_ = added;
        }
    }
}


void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if(ptr == NULL){
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}


void ULListStr::clear()
{
    while(head_ != NULL){
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
    numNodes_ = 0;
}
