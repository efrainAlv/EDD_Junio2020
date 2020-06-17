#include "AVL_Tree.h"

bool AVL_Tree::isEmpty() {
	return root == nullptr;
}


void AVL_Tree::add(Assets* asset) {

	TreeNode* newNode = new TreeNode(asset);

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


void AVL_Tree::add(std::string name, bool bolean) {

	TreeNode* newNode = new TreeNode(name, 0);

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

			if (aux->rightChild != nullptr) {
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

				/*
				leaf->leftChild->height = leaf->leftChild->height - 2;
				leaf->BF = leaf->rightChild->height - leaf->leftChild->height;
				leaf->leftChild->BF = 0;
				*/

				break;
			}
			//SI EL PADRE DEL PADRE DEL NODO QUE SE ESTA ANALIZANDO NO ES NULO, NO ES LA RAIZ
			else {

				std::cout << std::endl << "SE ENCONTRO UN DESBALANCE EN EL ARBOL " << std::endl;
				
				balance(leaf, true); //ENVIA COMO PARAMETRO AL PADRE DEL NODO ANALIZADO
				
				/*
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

			return leftRotation(leaf);
		}
		else if (leaf->BF == -1) {
			
			return doubleRotationRL(leaf);
		}
	}
	else if (leaf->parent->BF < -1) {

		if (leaf->BF == -1) {
			
			return rightRotation(leaf);

		}
		else if (leaf->BF == 1) {
			
			return doubleRotationLR(leaf);
		}
	}


}



TreeNode* AVL_Tree::leftRotation(TreeNode* leaf) {

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

		if (parent->leftChild!=nullptr) {
			parent->leftChild->sibling = node->leftChild;		//EL HERMANO DEL HIJO IZQUIERDO EL NODO DESEQUILIBRADO SERA IGUAL AL HIJO IZQUIERDO DEL HIJO DEL NODO DESEQUILIBRADO
		}
		
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


	node->leftChild->height = node->leftChild->height - 2;
	node->rightChild->height = 1;
	node->leftChild->BF = 0;
	node->rightChild->BF = 0;
	node->BF = 0;


	return node;

}


TreeNode* AVL_Tree::rightRotation(TreeNode* leaf) {

	TreeNode* parent = leaf->parent; //EL NODO DESEQUILIBRADO
	TreeNode* node = leaf;


	// SI EL NODO DESEQUILIBRADO NO TIENE PADRE
	if (parent->parent != nullptr) {
		parent->parent->leftChild = node;				//EL HIJO IZQUIERDO DEL PADRE DEL NODO DESEQUILIBRADO SERA IGUAL AL HIJO DERECHO DEL NODO DESEQUILIBRADO
		parent->parent->rightChild->sibling = node;		//EL HERMANO DEL HIJO IZQUIERDO DEL PADRE DEL NODO DESEQUILIBRADO SERA IGUAL AL HIJO DERECHO DEL NODO DESEQUILIBRADO
		node->sibling = parent->parent->rightChild;		//LO MISMO DE ARRIBA, SOLO QUE SE DECLARA PARA EL HIJO DEL NODO DESEQUILIBRADO
	}
	//SI EL NODO DESEQUILIBRADO ES LA RAIZ DEL ARBOL (NO TIENE PADRE)
	else {

		if (parent->rightChild!=nullptr) {
			parent->rightChild->sibling = node->rightChild;		//EL HERMANO DEL HIJO IZQUIERDO EL NODO DESEQUILIBRADO SERA IGUAL AL HIJO IZQUIERDO DEL HIJO DEL NODO DESEQUILIBRADO
		}
		
		if (node->rightChild != nullptr) {
			node->rightChild->sibling = parent->rightChild;	//LO MISO DE ARRIBA, PERO DECLARANDO PARA EL HIJO IZQUIERDO DEL HIOJ DEL NODO DESEQUILIBRADO EN CASO QUE SEA DIFERENTE DE NULO
		}

	}

	node->parent = parent->parent;			//EL PADRE DEL HIJO DEL NODO DESEQUILIBRADO AHORA SERA EL PADRE DEL NODO DESEQUILIBRADO

	parent->parent = node;					//EL PADRE DEL NODO DESEQUILIBRADO AHORA SERA SU HIJO DERECHO

	parent->leftChild = node->rightChild;	//EL HIJO DERECHO DEL NODO DESEQUILIBRADO AHORA SERA EL HIJO DEL HIJO DEL NODO DESEQUILIBRADO

	node->rightChild = parent;				//EL HIJO IZQUIERDO DEL HIJO DEL NODO DESEQUILIBRADO AHORA SERA IGUAL AL NODO DESEQUILIBRADO

	parent->sibling = node->leftChild;		//EL HERMANO DEL NODO DESEQUILIBRADO AHORA SERA EL HIJO DERECHO DEL HIJO DEL NODO DESEQUILIBRADO
	node->leftChild->sibling = parent;		//EL HERMANO EL HIJO DERECHO DEL HIJO DEL NODO DESEQUILIBRADO AHORA SERA EL NODO DESEQUILIBRADO


	node->rightChild->height = node->rightChild->height - 2;
	node->leftChild->height = 1;
	node->rightChild->BF = 0;
	node->leftChild->BF = 0;
	node->BF = 0;

	return node;
	
}


TreeNode* AVL_Tree::doubleRotationRL(TreeNode* leaf) {

	TreeNode* parent = leaf->parent; //EL NODO DESEQUILIBRADO
	TreeNode* node = leaf;

	if (parent->parent != nullptr) {

		if (parent->parent->rightChild!=nullptr) {

			if (parent->parent->leftChild==parent) {
				parent->parent->leftChild = node->leftChild;
				node->leftChild->parent = parent->parent;
			}
			else if(parent->parent->rightChild == parent){
				node->parent->parent->rightChild = node->leftChild;
				node->leftChild->parent = parent->parent;
			}

		}

	}
	else {
		node->leftChild->parent = parent->parent;
	}

	node->parent = node->leftChild;
	parent->parent = node->leftChild;

	node->leftChild->rightChild = node;
	node->leftChild->leftChild = parent;

	node->leftChild = nullptr;
	parent->rightChild = nullptr;


	//ESTABLECER NODOS COMO HERMNOS
	node->parent->leftChild->sibling = node->parent->rightChild;
	node->parent->rightChild->sibling = node->parent->leftChild;


	//ESTABLECER ALTURAS
	node->parent->height = node->height;
	node->height = node->height - 1;
	node->parent->leftChild->height = node->parent->leftChild->height - 2;

	//ESTABLECER FACTORES DE BALANCE
	node->parent->BF = 0;
	node->parent->leftChild->BF = 0;
	node->parent->rightChild->BF = 0;


	//ESTABLECER HERMANO AL HIJO IZQUIERDO DEL PADRE DEL PADRE
	if (node->parent->parent != nullptr) {

		if (node->parent->parent->leftChild == node->parent) {
			node->parent->sibling = node->parent->parent->rightChild;
			node->parent->parent->rightChild->sibling = node->parent;
		}
		else if (node->parent->parent->rightChild==node->parent) {
			node->parent->parent->leftChild->sibling = node->parent;
			node->parent->sibling = node->parent->parent->leftChild;
		}

	}

	return node->parent;

}



TreeNode* AVL_Tree::doubleRotationLR(TreeNode* leaf) {

	TreeNode* parent = leaf->parent; //EL NODO DESEQUILIBRADO
	TreeNode* node = leaf;

	if (parent->parent != nullptr) {

		if (parent->parent->leftChild != nullptr) {

			if (parent->parent->leftChild == parent) {
				parent->parent->leftChild = node->rightChild;
				node->rightChild->parent = parent->parent;
			}
			else if (parent->parent->rightChild == parent) {
				node->parent->parent->rightChild = node->rightChild;
				node->rightChild->parent = parent->parent;
			}

		}

	}
	else {
		node->rightChild->parent = parent->parent;
	}

	node->parent = node->rightChild;
	parent->parent = node->rightChild;

	node->rightChild->leftChild = node;
	node->rightChild->rightChild = parent;

	node->rightChild = nullptr;
	parent->leftChild = nullptr;


	//ESTABLECER NODOS COMO HERMNOS
	node->parent->leftChild->sibling = node->parent->rightChild;
	node->parent->rightChild->sibling = node->parent->leftChild;


	//ESTABLECER ALTURAS
	node->parent->height = node->height;
	node->height = node->height - 1;
	node->parent->rightChild->height = node->parent->rightChild->height - 2;

	//ESTABLECER FACTORES DE BALANCE
	node->parent->BF = 0;
	node->parent->leftChild->BF = 0;
	node->parent->rightChild->BF = 0;


	//ESTABLECER HERMANO AL HIJO IZQUIERDO DEL PADRE DEL PADRE

	if (node->parent->parent!=nullptr) {
		if (node->parent->parent->rightChild != nullptr) {
			node->parent->parent->rightChild->sibling = node->parent;
			node->parent->sibling = node->parent->parent->rightChild;
		}
	}


	//ESTABLECER HERMANO AL HIJO IZQUIERDO DEL PADRE DEL PADRE
	if (node->parent->parent != nullptr) {

		if (node->parent->parent->leftChild == node->parent) {
			node->parent->sibling = node->parent->parent->rightChild;
			node->parent->parent->rightChild->sibling = node->parent;
		}
		else if (node->parent->parent->rightChild == node->parent) {
			node->parent->parent->leftChild->sibling = node->parent;
			node->parent->sibling = node->parent->parent->leftChild;
		}

	}


	return node->parent;

}



void AVL_Tree::printTree(TreeNode* node) {

	
	std::cout << "ID: " << node->asset->getID() << "   NOMBRE: " << node->asset->getName() << std::endl;

	if (node->leftChild != nullptr) {
		printTree(node->leftChild);
	}

	if (node->rightChild != nullptr) {
		printTree(node->rightChild);
	}

}


TreeNode* AVL_Tree::find(std::string ID) {

	TreeNode* aux = root;

	while (aux->leftChild != nullptr || aux->rightChild != nullptr) {

		if (aux->asset->getID() == ID) {
			break;
		}
		if (aux->asset->getID() > ID) {
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

	return aux;

}