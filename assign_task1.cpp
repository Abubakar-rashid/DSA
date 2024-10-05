// Muhammad Abubakar Rashid 
// 459565   


#include<iostream>
#include<string>

using namespace std;
static int process_ids = 1234;

class Process{
    public:
    int process_id ;
    string name ;
    int exextution_time ;
    int remaining_time ;
    Process* next;
    public:
    Process(string name,int e_time){
        this->name = name ;
        this->process_id = process_ids;
        this->exextution_time = e_time;
        this->remaining_time = e_time;
        this->next = nullptr;
        process_ids++;

    }
    void set_time(int value){
         if(this->remaining_time <= value){
            this->remaining_time = 0;
         }
         else{
            this->remaining_time = this->remaining_time - value;
         }

    }

};


class CPUscheldule{
    public:
    Process* head ;
    int length;
    int count;
    public:
    CPUscheldule(){
        this->head = nullptr;
        this->length = 0;
        this->count = 1;
        
    }
    void addProcess(string name ,int time){
        Process * temp = new Process(name,time);
        if(this->length==0){
            head = temp;
            temp->next = temp;
            this->length++;
            cout<<"New process arrives: "<<name<<"(Remaining :"<<time<<")"<<endl;
            return;
        }
        else{
            Process* temp = head;
            while(true){
                if(temp->next == head){
                    Process* temp2 = new Process(name,time);
                    temp->next = temp2;
                    temp2->next = head;
                    this->length++;
                    cout<<"New process arrives: "<<name<<"(Remaining :"<<time<<")"<<endl;
                    return;
                }
                temp = temp->next;
            }
        }
    }
    void removeProcess(int id) {

    if (this->length == 0) {
        cout << "Nothing to remove!" << endl;
        return;
    }

    Process* temp = head;
    Process* prev = nullptr;

    if (temp->process_id == id) {
        if (this->length == 1) {
            delete head;
            head = nullptr;
        } else {
            Process* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = head->next;
            delete head;
            head = tail->next;
        }
        this->length--;
        // cout << "Process terminated!" << endl;
        return;
    }

    prev = head;
    temp = head->next;
    while (temp != head) {
        if (temp->process_id == id) {
            prev->next = temp->next;
            delete temp;
            this->length--;
            // cout << "Process terminated!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Process ID not found!" << endl;
}


    void display(){
        Process* temp = head;
        if(this->length==0){
            cout<<"Nothing to show plaese add a process !"<<endl;
            return;
        }
        while(true){
            if(temp->next == head){
                cout<<temp->process_id<<endl;
                return;
            }
            cout<<temp->process_id<<endl;
            temp = temp->next;            

        }
    }
    void Cycle(int tim){
        
        Process* temp = this->head;
        cout<<"Cycle :"<<this->count<<" ";
        int counter = 0;
        int maxx = this->length;
        while(counter != maxx){
            temp->set_time(tim);
            cout<<temp->name<<" Remaining("<<temp->remaining_time<<") ";  
            if(temp->remaining_time == 0){
                removeProcess(temp->process_id);
            }
            temp = temp->next;
            counter++;

        }
        cout<<endl;
        this->count++;

    }



};
int main(){
    
    CPUscheldule* l1 = new CPUscheldule();
    l1->addProcess("P1",30);
    l1->addProcess("P2",5);
    l1->addProcess("P3",17);
    
    //3 can be changed to any desired value
    cout<<"CPU time per process per cycle "<<3<<endl;
    l1->Cycle(3);
    l1->Cycle(3);
    l1->addProcess("P4",9);
    l1->Cycle(3);
    l1->Cycle(3);
    l1->addProcess("P5",12);
    l1->Cycle(3);


return 0;
}