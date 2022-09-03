#include <iostream>
#include <vector>

struct Node {
	int data;
	Node* next;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = nullptr;
	return temp;
}

int make_list_num_rev(Node* head) {
    if (!head) {
        return 0;
    }
    int sum = 0;
    int mul = 1;
    Node* temp = head;
    while (temp) {
        sum += temp->data * mul;
        mul *= 10;
        temp = temp->next;
    }
    return sum;
}
int number_digits(int num) {
    int count = 0;
    while (num) {
        num /= 10;
        ++count;
    }
    return count;
}
int num_power(int num, int p) {
    int sum = 1;
    while (p) {
        sum *= num;
        --p;
    }
    return sum;
}


void removeDuplicates(Node* head)
{
	Node *ptr1, *ptr2, *dup;
	ptr1 = head;
	while (ptr1 != nullptr && ptr1->next != nullptr) {
		ptr2 = ptr1;
		while (ptr2->next != nullptr) {
			if (ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete (dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}


Node* Kth_to_Last(Node* head, int k) {
	Node* ptr1 = head;
	Node* ptr2 = head;
	Node* res = head;
	int index = 0;
	if (head == nullptr || head->next == nullptr) {
		return nullptr;
	}
	while (k) {
		ptr2 = head->next;
		head = head->next;
		--k;
	}
	res = ptr2;
	head = ptr1;
	while (ptr2 != nullptr) {
		ptr2 = res->next;
		res = res->next;
		ptr1 = head->next;
		head = head->next;
		++index;
	}
	return head;
}


int Delete_Middle_Node(Node* head) {
	if (!head) {
		return -1;
	}
	if (!head->next) {
		delete (head);
		return -1; 
	}
	int count = 0;
	Node* ptr1 = head;
	Node* ptr2 = head;
	while (ptr2 != nullptr && ptr2->next != nullptr) {
		ptr2 = ptr2->next->next;
		ptr1 = ptr1->next;
		++count;
	}
	delete(ptr1);
	return count;
}


Node* partition(Node* head, int part) {
	Node* tmp = head;
	while (tmp) {
		if (tmp->data >= part) {
			break;
		}
		tmp = tmp->next;
	}
	Node* it = tmp;
	Node* prev_tmp = nullptr;
	while (it) {
		Node *tmp = it;
		if (it->data < part) {
			if (prev_tmp) {
				prev_tmp->next = tmp->next;
				tmp->next = head;
				it = prev_tmp;
			}
			head = tmp;
		}
		prev_tmp = it;
		it = it->next;
	}
	return  head;
}


Node* sum_lists_reverse(Node* list1, Node* list2) {
    int num1 = make_list_num_rev(list1);
    int num2 = make_list_num_rev(list2);
    Node* temp = list1;
    if (num1 < num2) {
        temp = list2;
    }
    int sum = num1 + num2;
    int mul = num_power(10, number_digits(sum)) / 10;
    while (temp) {
        temp->data = sum / mul;
        sum %= mul;
        mul /= 10;
        temp = temp->next;
    }
    if (!sum) {
        temp->next = newNode(sum);
    }
    if (num1 < num2) {
        return list2;
    }
    return list1;
}


bool isPalindrome(Node* head) {
  bool ans=true;
    std::vector<int> v;
    while(head!=NULL)
    {
        int temp = head->data;
        v.push_back(temp);
        head = head->next;
    }
    int h = 0;
    int n = v.size();
    for(int i = 0; i < v.size() / 2; ++i)
    {
        if(v[i] == v[n - i - 1])
        {
            continue;
        }
        else
        {
            ans=false;
            break;
        }
    }
    return ans;
}


Node* loop_Detection(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) { break; }
    }
    if(!fast || !fast->next) { return NULL; }
	slow = head;
	while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

 
void printList(Node*& node)
{
	while (node != nullptr) {
		std::cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	struct Node* start = newNode(8);
	start->next = newNode(5);
	start->next->next = newNode(11);
	start->next->next->next = newNode(8);
	start->next->next->next->next = newNode(2);
	start->next->next->next->next->next = newNode(20);
	start->next->next->next->next->next->next = newNode(25);

	//removeDuplicates(start);
	//printList(start); 
	//std::cout << Kth_to_Last(start, 3);
	Delete_Middle_Node(start);
	// partition(start,5);
	//printList(start);
	//isPalindrome(start);
	//loop_Detection(start);
	std::cout << std::endl;
	return 0;
}
