class ListNode  {
public:
    ListNode(int val, ListNode* ptr) : info(val), next(ptr){ }
    static ListNode* FirstMin(ListNode* list);
private:
    int        info;
    ListNode*  next;
};

ListNode* ListNode::FirstMin(ListNode* list) {
	if (list == 0) { return 0; }
	int min_val = list->info;
	ListNode* pMinNode = list;
	ListNode* pList = list->next;
	while(pList) {
		if (pList->info < min_val) {
			min_val = pList->info;
			pMinNode = pList;
		}
		pList = pList->next;
	}	
	return pMinNode;
}

int main(void) {
	return 0;
}