#include <stdio.h>
#include <stdlib.h>

typedef struct Node* np;

struct Node{
	np lc;
	np rc;
	int val;
};

np insertNode(np root, int key){
	np new = (np)malloc(sizeof(struct Node));
	new->val = key;

	if(root == NULL){
		return new;
	}

	if(key < root->val){
		root->lc = insertNode(root->lc, key);
	}else{
		root->rc = insertNode(root->rc, key);
	}

	return root;
}

void inorder(np root){
	if(root != NULL){
		inorder(root->lc);
		printf("%d ", root->val);
		inorder(root->rc);
	}
}

void preorder(np root){
	if(root != NULL){
		printf("%d ", root->val);
		preorder(root->lc);
		preorder(root->rc);
	}
}

void postorder(np root){
	if(root != NULL){
		postorder(root->lc);
		postorder(root->rc);
		printf("%d ", root->val);
	}
}

int search(np root, int key){
	if(root == NULL)
		return 0;

	if(key == root->val)
		return 1;

	if(key < root->val)
		return search(root->lc, key);
	else
		return search(root->rc, key);
}

int main(){
	np root = NULL;
	int n, key;

	printf("Enter the number of values to insert in the BST\n");
	scanf("%d", &n);

	printf("Enter the values to be inserted in BST\n");
	for(int i=0; i<n; i++){
		scanf("%d", &key);
		root = insertNode(root, key);
	}

	printf("Choose:\n1->Search\n2->Inorder\n3->Preorder\n4->Postorder\n0->Exit\n");
	int choice = -1;
	int item;
	
	while(choice != 0){
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the key to search\n");
				scanf("%d", &item);

				if(search(root, item)){
					printf("Found\n");
				}else{
					printf("Not Found\n");
					root = insertNode(root, item);
					printf("Inserted %d into the tree\n", item);
				}
				break;

			case 2:
				printf("Inorder Traversal: ");
				inorder(root);
				printf("\n");
				break;

			case 3:
				printf("Preorder Traversal: ");
				preorder(root);
				printf("\n");
				break;

			case 4:
				printf("Postorder Traversal: ");
				postorder(root);
				printf("\n");
				break;

			case 0:
				printf("Exiting\n");
				break;

			default:
				printf("Invalid Choice\n");
		}
	}
}