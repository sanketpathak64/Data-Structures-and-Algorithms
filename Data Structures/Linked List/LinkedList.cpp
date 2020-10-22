#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
class Node
{
	public:
		ll data;
		Node *next;
		Node(ll data)
		{
			this->data = data;
			this->next = NULL;
		}
};
class List
{
	public:
		Node *head;
		List()
		{
			this->head = NULL;
		}
		void insertNode(ll data, ll pos)
		{
			Node* node = new Node(data);
			ll len = listLength();
			if (pos > len + 1)
			{
				cout << "Position does not exists!\n";
				return;
			}
			if (pos == 1)
			{
				node->next = head;
				head = node;
				return;
			}
			Node *tmp = head, *tmp1;
			ll cnt = 1;
			while ((tmp) && (cnt < pos))
			{
				cnt++;
				tmp1 = tmp;
				tmp = tmp->next;
			}
			tmp1->next = node;
			node->next = tmp;
			return;
		}
		void deleteNode(ll pos)
		{
			ll cnt = 1;
			Node *tmp = head, *tmp1;
			if (!tmp)
			{
				cout << "List is Empty!\n";
				return;
			}
			if (pos == 1)
			{
				head = head->next;
				free(tmp);
				return;
			}
			while ((tmp) && (cnt < pos))
			{
				cnt++;
				tmp1 = tmp;
				tmp = tmp->next;
			}
			if (!tmp)
			{
				cout << "Position does not exists!\n";
				return;
			}
			tmp1->next = tmp->next;
			free(tmp);
			return;
		}
		ll listLength()
		{
			Node *tmp = head;
			ll cnt = 0;
			while (tmp)
			{
				cnt++;
				tmp = tmp->next;
			}
			return cnt;
		}
		void display()
		{
			Node *tmp = head;
			while (tmp)
			{
				if (!tmp->next)
					cout << tmp->data;
				else
					cout << tmp->data << " -> ";
				tmp = tmp->next;
			}
			cout << endl;
			return;
		}
		void reverse()
		{
			Node *curr = head, *prev = NULL, *next = NULL;
			while (curr)
			{
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
		}
		ll search(ll sv)
		{
			ll res = -1, cnt = 1;
			Node *tmp = head;
			while (tmp)
			{
				if (tmp->data == sv)
				{
					res = cnt;
					break;
				}
				tmp = tmp->next;
				cnt++;
			}
			return res;
		}
		void middleNode()
		{
			Node *slow = head, *fast = head;
			if (!slow)
			{
				cout << "List is Empty!\n";
				return;
			}
			while (fast && fast->next)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			cout << "Middle Node of list is: " << slow->data << " !" << endl;
		}
		void sort(Node **src)
		{
			Node *tmp = *src, *tmp1, *tmp2;
			if (!tmp)
			{
				cout << "List is Empty!\n";
				return;
			}
			if (!(tmp->next))
			{
				return;
			}
			split(tmp, &tmp1, &tmp2);
			sort(&tmp1);
			sort(&tmp2);
			*src = merge(tmp1, tmp2);
			head = *src;
		}
		Node* merge(Node* tmp1, Node* tmp2)
		{
			Node* result = NULL;
			if (tmp1 == NULL)
				return tmp2;
			if (tmp2 == NULL)
				return tmp1;
			if (tmp1->data <= tmp2->data)
			{
				result = tmp1;
				result->next = merge(tmp1->next, tmp2);
			}
			else
			{
				result = tmp2;
				result->next = merge(tmp1, tmp2->next);
			}
			return result;
		}
		void split(Node *src, Node **tmp1, Node **tmp2)
		{
			Node *slow = src, *fast = src->next;
			while (fast)
			{
				fast = fast->next;
				if (fast)
				{
					fast = fast->next;
					slow = slow->next;
				}
			}
			*tmp1 = src;
			*tmp2 = slow->next;
			slow->next = NULL;
		}
		void deleteDuplicates()
		{
			Node *tmp = head, *tmp1 = head;
			if (!tmp || !(tmp->next))
				return;
			int prev = -1, curr = tmp->data;
			while (tmp)
			{
				if (curr == prev)
				{
					tmp1->next = tmp->next;
					tmp = tmp->next;
					if (tmp)
						curr = tmp->data;
				}
				else
				{
					tmp1 = tmp;
					prev = curr;
					tmp = tmp->next;
					if (tmp)
						curr = tmp->data;
				}
			}
		}
		bool detectLoop()
		{
		    Node *slow = head, *fast = head;
		    while(fast && fast->next && slow)
		    {
		        fast = fast->next->next;
		        slow = slow->next;
		        if(fast == slow)
		            return true;
		    }
		    return false;
		}
		void detectAndRemoveLoop()
		{
			Node *slow = head, *fast = head, *looper;
		    int flg = 0, cnt = 1;
			while(fast && fast->next && slow)
		    {
		        fast = fast->next->next;
		        slow = slow->next;
		        if(fast == slow)
		        {
		            flg = 1;
		            looper = slow;
		            break;
		        }
		    }
		    if(flg == 0)
		        return;
		    fast = looper->next;
		    while(looper != fast)
		    {
		        fast = fast->next;
		        cnt++;
		    }
		    slow = head;
		    fast = head;
		    for(int i=0;i<cnt;i++)
		        slow = slow->next;
		    while (slow != fast) 
		    { 
		        fast = fast->next; 
		        slow = slow->next; 
		    } 
		    while (slow->next != fast) 
		        slow = slow->next; 
		    slow->next = NULL;
		}
		void reverseKelements()
		{
			
		}
};
int main()
{
	fastio;
	ll opt, d, p, len, res;
	bool flg;
	List* list = new List();
	while (1)
	{
		ll flg = 0;
		cout << "Menu:\n1.Insert Node:\n2.Delete Node:\n3.Display List:\n4.Find Length:\n5.Reverse the list:\n6.Search Node in the list:\n7.Find Middle Node of List:\n8.Sort the linked list:\n9.Delete Duplicate Nodes:\n10.Detect loop in list:\n11.Detect and remove loop in list:\n12.Exit:" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Enter Data:" << endl;
			cin >> d;
			cout << "Enter Position:" << endl;
			cin >> p;
			list->insertNode(d, p);
			break;
		case 2:
			cout << "Enter Position:" << endl;
			cin >> p;
			list->deleteNode(p);
			break;
		case 3:
			list->display();
			break;
		case 4:
			len = list->listLength();
			cout << "Length of list is " << len << endl;
			break;
		case 5:
			list->reverse();
			cout << "list is Reversed!" << endl;
			break;
		case 6:
			cout << "Enter Search Value:" << endl;
			cin >> d;
			res = list->search(d);
			if (res == -1)
				cout << "Node with data: " << d << " NOT found!" << endl;
			else
				cout << "Node with data: " << d << " found at position: " << res << " !" << endl;
			break;
		case 7:
			list->middleNode();
			break;
		case 8:
			list->sort(&list->head);
			cout << "List is sorted!" << endl;
			break;
		case 9:
			list->sort(&list->head);
			list->deleteDuplicates();
			break;
		case 10:
			flg = list->detectLoop();
			if(flg)
				cout<<"There is loop in list!"<<endl;
			else
				cout<<"There isn't any loop in list!"<<endl;
			break;
		case 11:
			list->detectAndRemoveLoop();
			break;
		case 12:
			flg = 1;
			break;
		default:
			cout << "Invalid Option!\n";
			break;
		}
		if (flg)
			break;
	}
	return 0;
}
