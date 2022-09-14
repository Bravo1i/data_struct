TreeNode* head=NULL,*end=NULL;//head记录链表的第一个节点 
TreeNode* Convert(TreeNode* pRootOfTree) {
	coverSub(pRootOfTree);
        return head;
}
//中序遍历，先把左子树的转为链表，并记录左子树中序遍历后的最后一个节点end,因为end后的节点就是pRoot了，
//当把pRoot接到end后面后，pRoot就变成了双向链表中最后一个节点，即end=pRoot 
void coverSub(TreeNode* pRoot){
    	if(pRoot==NULL) return;
    	Convert(pRoot->left);//将左子树转成一个双向的有序链表 
    	//判断是不是第一个节点
	if(end==NULL) {//是双向链表中的第一个节点
		cout<<"end->NULL"<<endl;
		head=pRoot;
		end=pRoot; 
	}
	else{//不是第一个节点，则需要把之前遍历生成的双向链表的最后一个节点指向当前节点，当前结点指向双向链表的最后一个节点（往双向链表中添加节点操作） 
		end->right=pRoot;
		cout<<"end->right"<<endl;
		pRoot->left=end;
		end=pRoot;//当前节点变为链表的最后一个节点 
	}
	Convert(pRoot->right); //将右子树转成一个双向有序链表 
}

