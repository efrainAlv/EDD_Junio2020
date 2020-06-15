#include "AVL_Tree.h"

bool AVL_Tree::isEmpty() {
	return root == nullptr;
}


void AVL_Tree::add(std::string name) {

	TreeNode* newNode = new TreeNode(name);

	if (isEmpty()) {

		root = newNode;
	}
	else {

		TreeNode* aux = root;

		while (aux->leftChild != nullptr || aux->rightChild != nullptr) {

			if (aux->name > name) {
				if (aux->leftChild == nullptr)
					break;
				else
					aux = aux->leftChild;
			}
			else {
				if (aux->rightChild == nullptr)
					break;
				else
					aux = aux->rightChild;
			}
		}

		if (aux->name > name) {

			newNode->parent = aux;
			
			if (aux->rightChild !=nullptr) {
				newNode->sibling = aux->rightChild;
				aux->rightChild->sibling = newNode;
			}
			aux->leftChild = newNode;
			if (aux->height == 1) 
			{
				updateHeightAndBF(aux->leftChild);
			}
			
		}
		else if (aux->name < name) {

			newNode->parent = aux;

			if (aux->leftChild != nullptr) {

				newNode->sibling = aux->leftChild;
				aux->leftChild->sibling = newNode;
			}
			aux->rightChild = newNode;
			if (aux->height == 1)
			{
				updateHeightAndBF(aux->rightChild);
			}
			
		}

	}

}


void AVL_Tree::updateHeightAndBF(TreeNode* leaf) {


	while (leaf->parent!=nullptr) {


		if (leaf->sibling == nullptr) {
			leaf->parent->height = leaf->height + 1;

			if (leaf->parent->leftChild==nullptr) {
				leaf->parent->BF = leaf->height - 0;

			}
			else if(leaf->parent->rightChild == nullptr) {
				leaf->parent->BF = 0 - leaf->height;
			}
		}
		else {

			if (leaf->sibling->height == leaf->height) {
				leaf->parent->height = leaf->height + 1;
				leaf->parent->BF = 0;
			}
			else if (leaf->sibling->height < leaf->height) {
				leaf->parent->height = leaf->height + 1;
				leaf->parent->BF = leaf->parent->rightChild->height - leaf->parent->leftChild->height;

			}
			else {
				leaf->parent->height = leaf->sibling->height + 1;
				leaf->parent->BF = leaf->parent->rightChild->height - leaf->parent->leftChild->height;

			}

		}


		//SI EL FACTOR DE EQUILIBRIO PADRE DEL NODO QUE SE ESTA ANALIZANDO ES 2 O -2 ENTRA *****************************************
		if (leaf->parent->BF > 1 || leaf->parent->BF < -1) {
			

			//SI EL PADRE DEL PADRE DEL NODO QUE SE ESTA ANALIZANDO ES NULO, SIGNIFICA QUE EL PADRE DEL PADRE DEL NODO ES LA RAIZ DEL ARBOL **********
			if (leaf->parent->parent==nullptr) {
				
				std::cout << std::endl << "SE ENCONTRO UN DESBALANCE EN EL ARBOL " << std::endl;
				root = balance(leaf, true); //ENVIA COMO PARAMETRO AL PADRE DEL NODO ANALIZADO



				break;
			}
			//SI EL PADRE DEL PADRE DEL NODO QUE SE ESTA ANALIZANDO NO ES NULO, NO ES LA RAIZ
			else {

				std::cout << std::endl << "SE ENCONTRO UN DESBALANCE EN EL ARBOL " << std::endl;
				
				balance(leaf, true); //ENVIA COMO PARAMETRO AL PADRE DEL NODO ANALIZADO
				
				leaf->leftChild->height = leaf->leftChild->height - 2;
				leaf->BF = leaf->rightChild->height - leaf->leftChild->height;
				leaf->leftChild->BF = 0;

				/*
				leaf->leftChild->height = leaf->leftChild->height - 2;
				leaf->BF = 0;
				leaf->leftChild->BF = 0;
				leaf->rightChild->BF = 0;
				*/
				break;

			}

		}
		else {
			leaf = leaf->parent;
		}

		//updateHeightAndBF();

		
	}


}

// RECIBE COMO PARAMETRO EL PADRE DEL NODO QUE SE ANALIZA
TreeNode* AVL_Tree::balance(TreeNode* leaf, bool isRoot) {


	if (leaf->parent->BF > 1) {

		if (leaf->BF == 1) {

			return LR(leaf);
		}
		else if (leaf->BF == -1) {
			return nullptr;
		}
	}
	else if (leaf->parent->BF < -1) {

		if (leaf->BF == -1) {
			return nullptr;
		}
		else if (leaf->BF == 1) {
			return nullptr;
		}
	}


}


TreeNode* AVL_Tree::leftRotaction(TreeNode* leaf, bool isRoot) {

	TreeNode* parent = leaf->parent;
	TreeNode* node = leaf;

	parent->rightChild = leaf->leftChild;
	
	leaf->parent->rightChild = leaf;

	leaf->parent = parent->parent;

	parent->parent = leaf;

	leaf->leftChild = parent;
	parent->parent = leaf;

	
	if (leaf->parent->leftChild!=nullptr) {
		leaf->parent->leftChild->sibling = leaf;
		leaf->sibling = leaf->parent->leftChild;
	}
	
	leaf->rightChild->sibling = leaf->leftChild;
	leaf->leftChild->sibling = leaf->rightChild;

	if (leaf->leftChild->rightChild!=nullptr && leaf->leftChild->leftChild!=nullptr) {

		leaf->leftChild->rightChild->sibling = leaf->leftChild->leftChild;
		leaf->leftChild->leftChild->sibling = leaf->leftChild->rightChild;

	}

	

	return node;

}



TreeNode* AVL_Tree::LR(TreeNode* leaf) {

	TreeNode* parent = leaf->parent; //EL NODO DESEQUILIBRADO
	TreeNode* node = leaf;


	// SI EL NODO DESEQUILIBRADO NO TIENE PADRE
	if (parent->parent!=nullptr) {
		parent->parent->rightChild = node;				//EL HIJO DERECHO DEL PADRE DEL NODO DESEQUILIBRADO SERA IGUAL AL HIJO DERECHO DEL NODO DESEQUILIBRADO
		parent->parent->leftChild->sibling = node;		//EL HERMANO DEL HIJO IZQUIERDO DEL PADRE DEL NODO DESEQUILIBRADO SERA IGUAL AL HIJO DERECHO DEL NODO DESEQUILIBRADO
		node->sibling = parent->parent->leftChild;		//LO MISMO DE ARRIBA, SOLO QUE SE DECLARA PARA EL HIJO DEL NODO DESEQUILIBRADO
	}
	//SI EL NODO DESEQUILIBRADO ES LA RAIZ DEL ARBOL (NO TIENE PADRE)
	else {

		parent->leftChild->sibling = node->leftChild;		//EL HERMANO DEL HIJO IZQUIERDO EL NODO DESEQUILIBRADO SERA IGUAL AL HIJO IZQUIERDO DEL HIJO DEL NODO DESEQUILIBRADO

		if (node->leftChild!=nullptr) {
			node->leftChild->sibling = parent->leftChild;	//LO MISO DE ARRIBA, PERO DECLARANDO PARA EL HIJO IZQUIERDO DEL HIOJ DEL NODO DESEQUILIBRADO EN CASO QUE SEA DIFERENTE DE NULO
		}

	}

	node->parent = parent->parent;			//EL PADRE DEL HIJO DEL NODO DESEQUILIBRADO AHORA SERA EL PADRE DEL NODO DESEQUILIBRADO
		
	parent->parent = node;					//EL PADRE DEL NODO DESEQUILIBRADO AHORA SERA SU HIJO DERECHO

	parent->rightChild = node->leftChild;	//EL HIJO DERECHO DEL NODO DESEQUILIBRADO AHORA SERA EL HIJO DEL HIJO DEL NODO DESEQUILIBRADO

	node->leftChild = parent;				//EL HIJO IZQUIERDO DEL HIJO DEL NODO DESEQUILIBRADO AHORA SERA IGUAL AL NODO DESEQUILIBRADO

	parent->sibling = node->rightChild;		//EL HERMANO DEL NODO DESEQUILIBRADO AHORA SERA EL HIJO DERECHO DEL HIJO DEL NODO DESEQUILIBRADO
	node->rightChild->sibling = parent;		//EL HERMANO EL HIJO DERECHO DEL HIJO DEL NODO DESEQUILIBRADO AHORA SERA EL NODO DESEQUILIBRADO


	return node;

}



