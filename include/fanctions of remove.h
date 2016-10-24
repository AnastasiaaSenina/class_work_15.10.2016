struct CNode{
	int date;
	CNode *next;
};

CNode RemElemInEnd(CNode* list, int size, int pos);
void RemRepeatElem(CNode* list);