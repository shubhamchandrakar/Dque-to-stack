#include<iostream>
#include<string.h>
using namespace std;
class queue;
class _stack;
void stack_functionality(_stack);
void queue_functionality(queue);
class queue{
	int *q;
   int size, f, r;
public:
	queue()
	{
		q=NULL;
		size=0;
		f=r= -1;
		// std::cout << "queue constructor" << '\n';
	}
	~queue()
	{
		delete q;
//		cout<<"in delete = "<<s;
		size=0;
		f = r = -1;
		// std::cout << "queue destructor" << '\n';
	}

	void get_size(int);
	void Enque(int);
	int Dque();
	bool under_flow();
	bool over_flow();
	void display();
	void insert_front(int);
	int delete_last();
	int peap_last();

};

void queue::get_size(int n){
	q= new int[n];
	size= n;
	// cout << "queue get_size" << '\n';
}

bool queue::under_flow(){
	return((f==-1)&&(r==-1));
}

bool queue::over_flow(){
	return(f== (r+1)%size);
}

int queue::Dque(){
	int x =-99;
	if(!under_flow()){
			x= q[f];
			if (f==r) {
					f=r=-1;
			}else{
					// f++;
					f= (f+1)%size;
			}
	}else{
			cout<< "\n=========================== Queue is under flow ===========================\n";
	}
	return x;
}

int queue::delete_last(){
	int x =-99;
	if(!under_flow()){
			x= q[r];
			if (f==r) {
				f=r= -1;
			}
			if (r==0) {
					r=size-1;
			}else if(r>0){
					r--;
			}
	}else{
			cout<< "\n=========================== Queue is under flow ===========================\n";
	}
	return x;
}
int queue::peap_last(){
	int x =-99;
	if(!under_flow()){
			x= q[r];
	}else{
		cout<< "\n=========================== Queue is under flow ===========================\n";
	}
	return x;
}

void queue::Enque(int ele){
	if (!over_flow()) {

			if (r==-1&& f== -1) {
				f = (f+1)%size;
			}
				r= (r+1)%size;
				q[r] = ele;

	} else {
		cout<< "\n=========================== Queue is over flow ===========================\n";
	}
}
void queue::insert_front(int ele){
	if (!over_flow()) {
			if(f== 0){
				f = size;
			}
			if (r==-1&& f== -1) {
				f++;
				r++;
				q[f]= ele;
			}else{
				q[--f] = ele;
			}
	}else {
		cout<< "\n=========================== Queue is over flow ===========================\n";
	}
}

void queue::display(){
	if (!under_flow()) {
			int i;
			int tmp_r = r;
			cout<<"\n============================= Display =============================\n";
			// std::cout << "\n r= "<< r << '\n';
			// std::cout << "\n f= "<< f << '\n';
			if (r<f)
			{
				for(i=f;i!=r;){
					if (i < size) {
							cout<<" | "<<q[i];
							i++;
					}
					else{
						i=0;
					}
				}
				cout<<" | "<<q[i];
			}else{
				for(i=f;i<=r;i++){
					cout<<" | "<<q[i];
				}
			}

	} else {
		cout<< "\n=========================== queue is empty ===========================\n";
	}

}
class _stack:public queue{

public:


	_stack(){
		// std::cout << "stack constructor" << '\n';
	}
	~_stack(){
		// std::cout << "stack destructor" << '\n';
	}
	void push(int ele){
		if (!over_flow()) {
			Enque(ele);
			cout << "\n Element pushed in stack : "<< ele << '\n';
		}else{
			cout<<"\n====================== Stack is overflow ======================";
		}
	}

	int pop(){
		int x = -999;
		if (!under_flow()) {
			x = delete_last();
		}else{
			cout<<"\n====================== Stack is underflow ======================";
		}
		return x;
	}

	int peap(){
		int x = -999;
		if (!under_flow()) {
			x = peap_last();
		}else{
			cout<<"\n====================== Stack is underflow ======================";
		}
		return x;
	}

	void stack_display(){
		if (!under_flow()) {
			cout << "\n Stack Elements : " << '\n';
			display();
		}else{
			cout<<"\n====================== Stack is Empty ======================";
		}

	}


	void get_size(int n){
		// cout<<"\n from stack size : "<<n;
		queue::get_size(n);
	}


};
int main(){
		queue q1;
		_stack s1;
		int ch;
		cout << "\n 1: For stack " << '\n';
		cout << " 2: For Queue " << '\n';
		cin>>ch;
		if (ch == 1) {
			stack_functionality(s1); // stack_functionality function calling
		}else if(ch ==2){
			queue_functionality(q1); // queue_functionality function calling
		}else{
			cout<<"\nPlease select correct option";
		}


	return(0);
}

// all stack functionality
void stack_functionality(_stack s1) {
			int n,sw;
			int tmp, flag =0 ;
			cout<<"Enter the stack size : ";
			cin>>n;
			s1.get_size(n);
			while(flag == 0){
			cout << "\n================================================================== " << '\n';
			cout << "\nPlease select your choice" << '\n';
			cout << "\n 1: For push element in stack " << '\n';
			cout << " 2: For pop element in stack " << '\n';
			cout << " 3: For peap element in stack " << '\n';
			cout << " 4: For print elements of stack " << '\n';
			cout << " 5: Exit " << '\n';

			cin>>sw;
			switch(sw){
				case 1:
							if (!s1.over_flow()) {
								cout<<"Enter element : ";
								cin>> tmp;
								s1.push(tmp);
							}else{
								cout<<"\n====================== Stack is overflow ======================";
							}
							break;

				case 2:
							if (!s1.under_flow()) {
								cout<<"Poped element : "<<s1.pop();
							}else{
								cout<<"\n====================== Stack is Empty ======================";
							}
							break;
				case 3:
							if (!s1.under_flow()) {
								cout<<"Peaped element : "<<s1.peap();
							}else{
								cout<<"\n====================== Stack is Empty ======================";
							}
							break;
				case 4:
						s1.stack_display();
						break;
				case 5:
						flag = 1;
						break;
				default:
						break;
			}
		}
}


void queue_functionality(queue q1) {
			int n,sw;
			int tmp, flag =0 ;
			cout<<"Enter the queue size : ";
			cin>>n;
			q1.get_size(n);
			while(flag == 0){
			cout << "\n================================================================== " << '\n';
			cout << "\nPlease select your choice" << '\n';
			cout << "\n 1: Insert from rear in queue " << '\n';
			cout << " 2: Insert from front in queue " << '\n';
			cout << " 3: Delete from front in queue " << '\n';
			cout << " 4: Delete from rear in queue " << '\n';
			cout << " 5: Print queue " << '\n';
			cout << " 6: Exit " << '\n';

			cin>>sw;
			switch(sw){
				case 1:
							cout<<"Enter element for inserting element from rear: ";
							cin>> tmp;
							q1.Enque(tmp);
							break;
				case 2:
							cout<<"Enter element for inserting element from front: ";
							cin>> tmp;
							q1.insert_front(tmp);
							break;
				case 3:
							if (!q1.under_flow()) {
									cout<<"Deleted element from front: "<<q1.Dque();
							}else{
								cout<< "\n=========================== queue is empty ===========================\n";
							}

							break;
				case 4:
							if (!q1.under_flow()) {
								cout<<"Deleted element from rear: "<<q1.delete_last();
							}else{
								cout<< "\n=========================== queue is empty ===========================\n";
							}
							break;
				case 5:
							q1.display();
							break;
				case 6:
							flag = 1;
							break;
				default:
						break;
			}
		}
}
