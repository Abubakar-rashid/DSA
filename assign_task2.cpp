#include<iostream>
#include<string>
// #include <boost/multiprecision/cpp_int.hpp>
// #include <boost/lexical_cast.hpp>
// using namespace boost::multiprecision;
using namespace std;

class Node{
    public:
    int leng;
    long long int value;
    Node* next;
    public:
    Node(int value){
        this->value = value ;
        this->leng = to_string(value).length();

    } 
};
class PrimeList{
    public:
    int length ;
    Node* head ;
    Node* tail ;
    public:
    PrimeList(){
        this->length = 0;
        this->head = nullptr;
    }

    
int primeMod(int value) {
    Node* temp = head;
    int result = 0;
    
    while (temp != nullptr) {
        // Instead of using pow(), manually calculate powers of 10 using integer arithmetic
        int multiplier = 1;
        for (int i = 0; i < temp->leng; i++) {
            multiplier *= 10; // Equivalent to 10^i
        }
        
        result = (result * multiplier + temp->value) % value;
        temp = temp->next;
    }
    
    cout << "The remainder is: " << result <<" when divided by :"<<value<< endl;
    return result;
}

    void addNode(int val){
        Node* temp = new Node(val);
        if(this->length == 0){
            this->head = temp;
            this->tail = temp ;
            this->length++;
            cout<<"Node added"<<endl;
            return;


        }else{
            tail->next = temp;
            tail = temp;
            this->length++;
            cout<<"Node added"<<endl;
            return;

        }
    }

    // string getLargeNumber() {
    //     Node* temp = head;
    //     string largeNumber = "";
    //     while (temp != nullptr) {
    //         largeNumber = largeNumber + to_string(temp->value);  // Concatenate each chunk
    //         temp = temp->next;
    //     }
    //     return largeNumber;
    // }

    int get_len(){
        Node* temp = head ;
        int leng = 0 ;
        while(true){
            if(temp == tail){
               leng+=temp->leng;
               return leng;
            }
            leng += temp->leng;
            temp = temp->next;

        }
        
    }

    void display(){
        Node* temp = head;
        if(this->length == 0){
            cout<<"Nothing to display"<<endl;
            return;
        }
        while(true){
            if(temp == tail){
                cout<<temp->value<<" --> Null"<<endl;
                return;
            }
            cout<<temp->value<<"--> ";
            temp = temp->next;
        }
    }

    int findLength(int n) {
    return to_string(n).length();
}
    bool check_prime(){
        if(primeMod(2) == 0 || primeMod(3)==0 || primeMod(5)==0 || primeMod(7)==0 || primeMod(11)==0){
           cout<<"the number is not prime"<<endl;
           return false;
        }
        cout<<"The number was not divisible by 2, 3, 5, 7 and 11"<<endl;
        
        
        long long int i = 3;

    while (findLength(i * i) < get_len()+1) {
        if (primeMod(i) == 0){
             cout<<"The number is divisible by "<<i<<endl;
             return false;}
        cout<<i<<endl;
        
        i += 2;
    }
    cout<<"The number is a prime"<<endl;
    return true;
    }


};


int main(){
    PrimeList* l1 = new PrimeList();

    l1->addNode(579238414);
    l1->addNode(216451568);
    l1->addNode(853071456);
    l1->addNode(680970209);
    l1->addNode(945947882);
    l1->addNode(593729341);
    l1->addNode(719469942);
    l1->addNode(118631226);
    l1->addNode(722271245);
    l1->addNode(133424416);
    l1->addNode(324254968);
    l1->addNode(945828640);
    l1->addNode(445343858);
    l1->addNode(67);
    l1->primeMod(1000000007);
    l1->display();
    cout << "Prime Check: " << l1->check_prime() << endl;
    

    return 0;
}
