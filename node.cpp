#include <iostream>
using namespace std;

struct Node {
	int body;
	Node* next;
	Node* prev;
};

Node* firstel(int body);
void addel(Node** end, Node** beg, int body);
Node* findel(Node* const beg, int body);
bool delel(Node** beg, Node** end, int key);
Node* insertel(Node* const beg, Node** end, int key, int body);

int main() {

	Node* beg = firstel(1);

	Node* end = beg;

	addel(&end, &beg, 2);
	addel(&end, &beg, 3);
	addel(&end, &beg, 4);
	addel(&end, &beg, 5);
	addel(&end, &beg, 6);
	addel(&end, &beg, 7);

	insertel(beg, &end, 2, 29);

	if (!delel(&beg, &end, 29)) {
		cout << "Cant delete element";
	}

	Node* pv = beg;

	int amount = 0;

	do{
		cout << pv->body << " ";
		pv = pv->next;
		amount++;
	} while (pv != beg);

	cout << endl << "Amount of elements: " << amount;

	return 0;
}

Node* firstel(int body) {
	Node* pv = new Node;
	pv->body = body;
	pv->next = 0;
	pv->prev = 0;
	return pv;
}

void addel(Node** end, Node** beg, int body) {
	Node* pv = new Node;
	pv->body = body;
	pv->prev = *end;
	pv->next = *beg;
	(*end)->next = pv;
	*end = pv;
}

Node* findel(Node* const beg, int body) {
	Node* pv = beg;

	while (pv) {
		if (pv->body == body) {
			break;
		}
		pv = pv->next;
	}

	return pv;
}

bool delel(Node** beg, Node** end, int key) {
	if (Node* pkey = findel(*beg, key)) {

		if (pkey == *beg) {
			*beg = (*beg)->next;
			(*beg)->prev = 0;
		}

		else if (pkey == *end) {
			*end = (*end)->prev;
			(*end)->next = *beg;
		}

		else {
			(pkey->prev)->next = pkey->next;
			(pkey->next)->prev = pkey->prev;
		}

		delete pkey;
		return true;
	}

	return false;
}

Node* insertel(Node* const beg, Node** end, int key, int body) {
	if (Node* pkey = findel(beg, key)) {
		Node* pv = new Node;
		pv->body = body;
		pv->next = pkey->next;
		pv->prev = pkey;
		pkey->next = pv;

		if (pkey != *end) {
			(pv->next)->prev = pv;
		}
		else *end = pv;
		return pv;
	}

	return 0;
}
