#include "AssetsList.h"

bool AssetsList::isEmpty() {

	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void AssetsList::addLast(TreeNode* newNode) {

	bool pass =false;

	AssetNode* newN = new AssetNode(newNode);


	if (isEmpty()) {
		head = newN;
		head->next = nullptr;
		size++;
	}
	else {

		AssetNode* auxNode = head;

		while (auxNode->next != nullptr) {
			
			if (auxNode== newN) {
				pass = true;
			}
			auxNode = auxNode->next;
		}
		
		if (!pass) {
			auxNode->next = newN;
			auxNode->next->next = nullptr;
			size++;
		}
	}

}


Assets* AssetsList::findAsset(std::string ID) {

	AssetNode* aux = head;

	do {

		if (aux->node->asset->getID()==ID) {
			break;
		}
		else {

			aux = aux->next;
		}

	} while (aux != nullptr);


	if (aux != nullptr) {
		return aux->node->asset;
	}
	else {
		return nullptr;
	}

}


void AssetsList::printRents() {

	AssetNode* node = head;

	do {

		std::cout << "ID: " << node->node->asset->getID() << "  NOMBRE: " << node->node->asset->getName();
		if (!node->node->asset->isAvaliable()) {

		}

		node = node->next;

	} while (node != nullptr);

}


void AssetsList::printAssets() {

	AssetNode* node = head;

	do {

		std::cout << "ID: " << node->node->asset->getID() << "  NOMBRE: " << node->node->asset->getName() << std::endl;

		node = node->next;

	} while (node!=nullptr);

}


void AssetsList::deleteAsset(std::string ID) {

	AssetNode* aux= head;
	AssetNode* auxNex = aux->next;

	int n = 1;

	if (head->node->asset->getID() == ID) {

		head = head->next;

	}
	else {

		do {

			if (aux->next->node->asset->getID() == ID && aux->next->next != nullptr) {

				aux->next = aux->next->next;

			}
			if (aux->next->next==nullptr && aux->next->node->asset->getID()==ID) {
				aux->next = nullptr;
			}

			aux = aux->next;

		} while (aux->next!= nullptr);

	}


}