#include "fanctions of remove.h"



CNode RemElemInEnd(CNode* list, int size, int pos){
	if (pos <= size) {
	CNode* list1 = list;
	CNode *ppos;
	if (pos != size){
		for (int i = 0; i < size - pos - 1; ++i)
			list = list->next;
		ppos = list->next;
		list->next = list->next->next;
		delete ppos;
	}
	else {
		list1 = list1->next;
		delete list;
	}
	return *list1;
}
	else throw 1;
	
};

void RemRepeatElem(CNode* list){
	CNode *plist;

	while (list != 0){

		while ((list->next != 0) && (list->date == list->next->date)){
			plist = list->next;
			list->next = list->next->next;
			delete plist;
		}

		if (list->next == 0) break;
		else
			list = list->next;

	}
};

