#include <iostream>
#include <string>

using namespace std;

/*
This class will be in control of the process object. Each class will have an ID, arrival time, response time, wait time, turnaround time,
CPU burst, IO burst, and a next pointer. This class is a node class. There will be public functions that will help access and change the state
of an object
*/
class node
{
public:
	int data;
	node* next, *prev;
};

class int_list
{
public:
	int_list();
	void add(int x);
	void print_int_list();
	node* get_int_front();
	int int_pop();
	int return_prev();
	node* get_int_next(); //this is to be used after a pop
	int get_front_data();
	bool int_is_empty();
private:
	node* int_front, * int_back;
};

int_list::int_list()
{
	int_front = 0;
	int_back = 0;
}
void int_list::add(int x)
{
	node* newnode = new node;
	newnode->data = x;
	newnode->next = 0;
	newnode->prev = 0;
	if (int_front == 0)
	{
		int_front = newnode;
		int_back = newnode;
	}
	else
	{
		int_back->next = newnode;
		newnode->prev = int_back;
		int_back = newnode;
	}
}
void int_list::print_int_list()
{
	node* ptr = int_front;
	if (int_front != 0)
	{
		while (ptr != 0)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}
	else
	{
		cout << "int list is empty\n";
	}

}
node* int_list::get_int_front()
{
	return int_front;
}
int int_list::int_pop()
{
	node* ptr = int_front;
	if (int_front != 0)
	{
		//save the front
		int_front = int_front->next;
		return ptr->data;
	}
	else {
		cout << "unable to pop from int_list\n";
		return 0;
	}
}
int int_list::return_prev()
{
	node* ptr = int_front;
	if (ptr != 0 && ptr->prev != 0)
	{
		return ptr->prev->data;
	}
	else
	{
		cout << "previous pointer pointing to null\n";
		return NULL;
	}
}
node* int_list::get_int_next()
{
	node* ptr = int_front;
	if (ptr->next == 0)
	{
		return nullptr;
	}
	else
	{
		return ptr->next;
	}
}
int int_list::get_front_data()
{
	if (int_front != nullptr)
	{
		return int_front->data;
	}
	else
	{
		return 0;
	}

}
bool int_list::int_is_empty()
{
	if (int_front == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*
This class will be a singly linked node list. The nodes are the processes. In each process, there are two linked list of CPU and IO burst times
This class will be used to make the queues necessary for a FCFS schedulng process. The pointers in the state are of type process so that they may
point to the beginning or a list of processes
*/
class linked_list
{
public:
	class process
	{
	public:
		process(int_list& cpu_time, int_list& io_time, string process_id, int a_time);
		//set functions
		void set_processID(string s);
		void set_arrival_time(int arrive);
		void set_response_time(int response);
		void set_wait_time(int wait);
		void set_turnaround_time(int turnaround);
		void set_cpu_burst_list(int_list* list);
		void set_io_burst_list(int_list* list);
		void set_next(process* next_process);

		//get functions
		string get_processID();
		int get_arrival_time();
		int get_response_time();
		int get_wait_time();
		int get_turnaround_time();
		int_list* get_cpu_burst_time(); //this is a pointer of linked_list type to a linked list
		int_list* get_io_burst_time();
		process* get_next();
		int get_cpu_pop();
		int get_io_pop();
		int get_cpu_prev(); //gived you the previous int after you have popped
		int get_io_prev();
		node* get_int_next();
		node* get_io_next();
		int get_cpu_front_data();
		int get_io_front_data();
		bool is_cpu_empty();
		bool is_io_empty();


	private:
		string processID;
		int arrival_time;
		int response_time;
		int wait_time;
		int turnaround_time;
		int_list* cpu_burst_list; //this will be a linked list
		int_list* io_burst_list; //this will also be a linked list 
		process* next;
	};

	linked_list();
	linked_list(string s);
	~linked_list();
	bool is_empty();
	void add(process* process);
	void add_in_order(process* proc);
	process* search(process* proc);
	void remove(process* proc);
	process* get_front();
	int length();
	process* pop(); //pop out the first node only
	void print();


private:
	string name;
	process* front;
	process* back;
};

//definitions of process class
linked_list::process::process(int_list& cpu_time, int_list& io_time, string process_id = "", int a_time = 0)
{
	processID = process_id;
	arrival_time = a_time;
	response_time = 0;
	wait_time = 0;
	turnaround_time = 0;
	cpu_burst_list = &cpu_time; //please make sure this works i Have trouble understanding pointers in this manner
	io_burst_list = &io_time; //io_burst_list is a pointer of linked list type now pointing the the address of a linked_list called io_time
	next = 0;
}
void linked_list::process::set_processID(string id)
{
	processID = id;
}
void linked_list::process::set_arrival_time(int arrive)
{
	arrival_time = arrive;
}
void linked_list::process::set_response_time(int response)
{
	response_time = response;
}
void linked_list::process::set_wait_time(int wait)
{
	wait_time = wait;
}
void linked_list::process::set_turnaround_time(int turnaround)
{
	turnaround_time = turnaround;
}
void linked_list::process::set_cpu_burst_list(int_list* list)
{
	cpu_burst_list = list;
}
void linked_list::process::set_io_burst_list(int_list* list)
{
	io_burst_list = list;
}
void linked_list::process::set_next(process* process)
{
	next = process;
}

string linked_list::process::get_processID()
{
	return processID;
}
int linked_list::process::get_arrival_time()
{
	return arrival_time;
}
int linked_list::process::get_response_time()
{
	return response_time;
}
int linked_list::process::get_wait_time()
{
	return wait_time;
}
int linked_list::process::get_turnaround_time()
{
	return turnaround_time;
}
int_list* linked_list::process::get_cpu_burst_time()
{
	return cpu_burst_list;
}
int_list* linked_list::process::get_io_burst_time()
{
	return io_burst_list;
}
linked_list::process* linked_list::process::get_next()
{
	return next;
}
int linked_list::process::get_cpu_pop()
{
	return cpu_burst_list->int_pop();
}
int linked_list::process::get_io_pop()
{
	return io_burst_list->int_pop();
}
int linked_list::process::get_cpu_prev()
{
	return cpu_burst_list->return_prev();
}
int linked_list::process::get_io_prev()
{
	return io_burst_list->return_prev();
}
node* linked_list::process::get_int_next()
{
	return cpu_burst_list->get_int_next();
}
node* linked_list::process::get_io_next()
{
	return io_burst_list->get_int_next();
}
int linked_list::process::get_cpu_front_data()
{
	return cpu_burst_list->get_front_data();
}
int linked_list::process::get_io_front_data()
{
	return io_burst_list->get_front_data();
}
bool linked_list::process::is_cpu_empty()
{
	return cpu_burst_list->int_is_empty();
}
bool linked_list::process::is_io_empty()
{
	return io_burst_list->int_is_empty();
}


//linked_list class definitions
linked_list::linked_list()
{
	name = "";
	front = 0;
	back = 0;
}
linked_list::linked_list(string s)
{
	name = s;
	front = 0;
	back = 0;
}
linked_list::~linked_list()
{
	process* to_del;
	while (!is_empty())
	{
		to_del = front;
		front = front->get_next();
		delete to_del;
	}
	cout << "linked list has been destroyed\n";
}
bool linked_list::is_empty()
{
	if (front == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void linked_list::add(process* process)
{
	if (front == 0)
	{
		front = process;
		back = process;
	}
	else
	{
		back->set_next(process);
		back = process;
	}
}
void linked_list::add_in_order(process* proc)
{
	

	proc->set_next(0); //reset this incase we have it at end
	if (front == 0)
	{
		//cout << "making list starting with: " << proc->get_processID() << endl;
		front = proc;
		back = proc;
	}
	else if (proc->get_arrival_time() <= front->get_arrival_time()) //if the arrival time of proc is less than the leading process, put it right behind it
	{

		//cout << "adding to before front: " << proc->get_processID() << endl;
		proc->set_next(front->get_next());
		front->set_next(proc);
	}
	else if (proc->get_arrival_time() >= back->get_arrival_time()) //if the arrival time of proc is greater than the back process, we put it right behind back and make it new back
	{
		//problem is in here
		//cout << "back is: " << back->get_processID() << endl;
		//cout << "adding to back: " << proc->get_processID() << endl;
		back->set_next(proc);
		proc->set_next(0);
		back = proc;
		//cout << "proc is: " << proc->get_processID() << endl;
		//cout << "back is: " << back->get_processID() << endl;

	}
	else //if arrival time does not meet the above three requirments, it will land somewhere in the middle
	{
		//traverse till we find its spot
		process* ptr = front;
		process* prev = front;
		//cout << "we have entered the else loop\n";
		//cout << "back is: " << back->get_processID() << endl;
		while (ptr != 0 && proc->get_next() == 0)
		{
			//cout << "we have entered the while loop\n";
			//ptr = ptr->get_next(); //one ahead of prev pointer
			//cout << "THe prev arrival time is: " << prev->get_arrival_time() << " for " << prev->get_processID() << endl
				//<< "the proc arrival time is: " << proc->get_arrival_time() << " for " << proc->get_processID() << endl
				//<< "the ptr arrival time is: " << ptr->get_arrival_time() << " for " << ptr->get_processID() << endl;
			if (prev->get_arrival_time() <= proc->get_arrival_time() && proc->get_arrival_time() < ptr->get_arrival_time())
			{
				//cout << "entered the if loop\n";
				//this is if the prev is equal to proc but ptr is greater... we can put proc at the end of repeating arrival times but
				//ahead of arrival times that are larger than proc's
				//cout << "adding " << proc->get_processID() << " between " << prev->get_processID() << " and " << ptr->get_processID() << endl;
				prev->set_next(proc);
				//cout << "prev is now pointing to: " << prev->get_next()->get_processID() << endl;
				proc->set_next(ptr);
				//cout << "proc is now pointing to: " << proc->get_next()->get_processID() << endl;
				back->set_next(0);
				//cout << "proc is: " << proc->get_processID() << endl;
				//cout << "back is: " << back->get_processID() << endl;
				break;
			}
			prev = ptr;
			ptr = ptr->get_next();
		}
	}
}
linked_list::process* linked_list::search(process* proc)
{
	if (front != 0)
	{
		process* ptr = front;
		while (ptr != 0)
		{
			if (ptr == proc)
			{
				return ptr;
			}
			ptr = ptr->get_next();
		}
	}
	return 0;
}
void linked_list::remove(process* proc)
{
	process* to_remove = search(proc);
	if (to_remove != 0)
	{
		if (to_remove == front)
		{
			front = front->get_next();
			delete to_remove;
		}
		else if (to_remove == back)
		{
			process* prev = front;
			while (prev != 0 && prev != back)
			{
				if (prev->get_next() == back)
				{
					back = prev;
					back->set_next(0);
					delete to_remove;
				 }
				prev = prev->get_next();
			}
		}
		else {
			process* prev = front;
			while (prev != 0 && prev != to_remove)
			{
				prev = prev->get_next();
				if (prev->get_next() == to_remove)
				{
					prev->set_next(to_remove->get_next());
					delete to_remove;
				}
			}
		}
	}
}
linked_list::process* linked_list::get_front()
{
	return front;
}
int linked_list::length()
{
	int counter = 0;
	process* ptr = front;
	if (ptr != 0)
	{	
		while (ptr != 0)
		{
			counter++;
			ptr = ptr->get_next();
		}
		return counter;
	}
	else {
		return 0;
	}
}
linked_list::process* linked_list::pop()
{
	if (!is_empty())
	{
		process* ptr = front;
		front = front->get_next(); //next node is ready to be popped out
		return ptr;
	}
	else
	{
		cout << "unable to pop out a process because list is empty\n";
		return nullptr;
	}
}
void linked_list::print()
{
	process* ptr = front;
	if (!is_empty())
	{
		while (ptr != 0)
		{
			cout << "\t\t" << ptr->get_processID() << "\t\t" << ptr->get_cpu_front_data() << endl;
			ptr = ptr->get_next();
		}
	}
}

void easy_create(int_list& cpu_list, int b_array[], int x, int_list& io_list, int i_array[], int y)
{
	for (int i = 0; i < x; i++)
	{
		cpu_list.add(b_array[i]);
	}
	for (int i = 0; i < y; i++)
	{
		io_list.add(i_array[i]);
	}
}

int main()
{
	//create all list needed here
	linked_list ready_queue("ready queue");
	linked_list io_state("io state");
	linked_list completed("completed processes");
	//will need a current process that has a the paramter requirments made

	//create the processes to work with
	//for process 1
	int p1_cpu[] = { 6,9,5,4,3,6,4,8,3 };
	int p1_io[] = { 21,28,26,22,41,45,27,27 };
	int_list p1_cpu_list, p1_io_list;
	int p1_cpu_size = sizeof p1_cpu / sizeof p1_cpu[0];
	int p1_io_size = sizeof p1_io / sizeof p1_io[0];
	easy_create(p1_cpu_list, p1_cpu, p1_cpu_size, p1_io_list, p1_io, p1_io_size);
	//for process 2
	int p2_cpu[] = { 19,16,17,6,8,21,19,10,7 };
	int p2_io[] = { 48,32,29,44,34,34,39,31 };
	int p2_cpu_size = sizeof p2_cpu / sizeof(p2_cpu[0]);
	int p2_io_size = sizeof p2_io / sizeof(p2_io[0]);
	int_list p2_cpu_list, p2_io_list;
	easy_create(p2_cpu_list, p2_cpu, p2_cpu_size, p2_io_list, p2_io, p2_io_size);
	//process 3
	int p3_cpu[] = { 12,6,3,7,8,11,9 };
	int p3_io[] = { 14,21,29,45,54,44 };
	int p3_cpu_size = sizeof p3_cpu / sizeof(p3_cpu[0]);
	int p3_io_size = sizeof p3_io / sizeof(p3_io[0]);
	int_list p3_cpu_list, p3_io_list;
	easy_create(p3_cpu_list, p3_cpu, p3_cpu_size, p3_io_list, p3_io, p3_io_size);
	//process 4
	int p4_cpu[] = { 11,5,6,8,4,13,11,10 };
	int p4_io[] = { 45,41,45,51,61,54,61 };
	int p4_cpu_size = sizeof p4_cpu / sizeof(p4_cpu[0]);
	int p4_io_size = sizeof p4_io / sizeof(p4_io[0]);
	int_list p4_cpu_list, p4_io_list;
	easy_create(p4_cpu_list, p4_cpu, p4_cpu_size, p4_io_list, p4_io, p4_io_size);
	//process 5
	int p5_cpu[] = { 16,15,12,14,13,16,12,10,11 };
	int p5_io[] = { 22,21,31,26,31,18,21,33 };
	int p5_cpu_size = sizeof p5_cpu / sizeof(p5_cpu[0]);
	int p5_io_size = sizeof p5_io / sizeof(p5_io[0]);
	int_list p5_cpu_list, p5_io_list;
	easy_create(p5_cpu_list, p5_cpu, p5_cpu_size, p5_io_list, p5_io, p5_io_size);
	//process 6
	int p6_cpu[] = { 20,22,25,11,17,18,6,16 };
	int p6_io[] = { 31,30,29,44,34,31,22 };
	int p6_cpu_size = sizeof p6_cpu / sizeof(p6_cpu[0]);
	int p6_io_size = sizeof p6_io / sizeof(p6_io[0]);
	int_list p6_cpu_list, p6_io_list;
	easy_create(p6_cpu_list, p6_cpu, p6_cpu_size, p6_io_list, p6_io, p6_io_size);
	//process 7
	int p7_cpu[] = { 3,7,6,5,4,7,6,5,6,4 };
	int p7_io[] = { 44,24,34,54,24,44,54,21,43 };
	int p7_cpu_size = sizeof p7_cpu / sizeof(p7_cpu[0]);
	int p7_io_size = sizeof p7_io / sizeof(p7_io[0]);
	int_list p7_cpu_list, p7_io_list;
	easy_create(p7_cpu_list, p7_cpu, p7_cpu_size, p7_io_list, p7_io, p7_io_size);
	//process 8
	int p8_cpu[] = { 15,4,11,4,3,5,8,6,9 };
	int p8_io[] = { 50,23,31,31,47,21,31,44 };
	int p8_cpu_size = sizeof p8_cpu / sizeof(p8_cpu[0]);
	int p8_io_size = sizeof p8_io / sizeof(p8_io[0]);
	int_list p8_cpu_list, p8_io_list;
	easy_create(p8_cpu_list, p8_cpu, p8_cpu_size, p8_io_list, p8_io, p8_io_size);
	//Now I have created the integer linked list that will be part of the processes that are
	//considered nodes of the processing linked list

	ready_queue.add(new linked_list::process(p1_cpu_list, p1_io_list, "P1", 0));
	ready_queue.add(new linked_list::process(p2_cpu_list, p2_io_list, "P2", 0));
	ready_queue.add(new linked_list::process(p3_cpu_list, p3_io_list, "P3", 0));
	ready_queue.add(new linked_list::process(p4_cpu_list, p4_io_list, "P4", 0));
	ready_queue.add(new linked_list::process(p5_cpu_list, p5_io_list, "P5", 0));
	ready_queue.add(new linked_list::process(p6_cpu_list, p6_io_list, "P6", 0));
	ready_queue.add(new linked_list::process(p7_cpu_list, p7_io_list, "P7", 0));
	ready_queue.add(new linked_list::process(p8_cpu_list, p8_io_list, "P8", 0));
	//All the processes have been created and are put into the ready queue. The ready queue is now set up with all
	//arrival times set to 0, now we can begin FCFS process
	//ready_queue.print(); //testing line

	//Here begins the main loop
	linked_list::process* current_process = 0;
	linked_list::process* current_io_process = 0;
	int length = ready_queue.length();
	int time = 0; //this is the clock of the whole scheduling system. will add 1 each loop of processing loop
	int temp_time = 0; //this will help us when we are counting the time units off of the current processes burst
	int io_temp_time = 0;
	int prev_cpu_burst = 0;
	int prev_io_burst = 0;
	int context_switch = 0;
	while (completed.length() != length) //while the completed linked list is not full... meaning there are some processes still not done
	{
		if (current_process == 0 && !ready_queue.is_empty())
		{
			current_process = ready_queue.pop(); //now it is filled with one process
			//capture the burst time
			temp_time = current_process->get_cpu_pop(); //integer value
		}
		cout << "Current Time: " << time << endl << endl;
		if (current_process != 0)
		{
			cout << "Now Running: " << current_process->get_processID() << endl;
		}
		else
		{
			cout << "[IDLE]\n";
		}
		cout << ".....................................................................................\n";
		cout << "Ready Queue:\tProcess\t\tBurst\n";
		ready_queue.print();

		
		time += temp_time;
		//now that we have done the burst, we need to do the IO (out of CPU time but gives new arrival time)
		//If int_front == 0, then we know we have no upcoming cpu burst which means there isnt a trailing IO burst
		//we would not need to add the process back into the ready queue because there is no upcoming cpu burst.
		//This means we are done so we can put this process in the completed list
		if (current_process != 0 && current_process->get_cpu_front_data() != 0) 
		{	//we also don't need to add it back into the ready queue because it has been completed
			//io_state.add(current_process);//this does not have to be in order because it will complete a fcfs process right there
			current_io_process = current_process;
			//capture the io burst time
			io_temp_time = current_io_process->get_io_pop(); //shoud be an integer there is a nullptr error here
			//now set the new arrival time of this process
			current_io_process->set_arrival_time(current_io_process->get_arrival_time() + temp_time + io_temp_time);
			//now that the new arrival time is set, we need to add it back into the ready queue in the proper order
			current_io_process->set_next(nullptr);
			ready_queue.add_in_order(current_io_process);

			cout << ".....................................................................................\n";
			cout << "Now in I/O:\tProcess\t\tRemaining I/O Time\n";
			if (current_io_process == 0 || current_io_process->is_io_empty())
			{
				cout << "\t\t\t[empty]" << endl << endl;
			}
			else
			{
				cout << "\t\t" << current_io_process->get_processID() << "\t\t" << current_io_process->get_io_prev() << endl;
			}
		}
		else if (current_process->get_cpu_front_data() == 0)
		{
			current_process->set_next(nullptr);
			completed.add(current_process);
			if (!(completed.is_empty()))
			{
				cout << "Completed Processes:\n";
				completed.print();
			}
		}
		
		cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
		temp_time = 0;
		io_temp_time = 0;
		current_process = 0; //resetting the current_process so that it can accept more processes
		current_io_process = 0;
	}
	cout << "final time: " << time << endl;

	return 0;
}