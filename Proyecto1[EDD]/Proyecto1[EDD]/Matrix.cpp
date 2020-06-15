#include "Matrix.h"
#include <iostream>

bool Matrix::isEmpty() {
	return pivot->nextHeader == nullptr && pivot->belowHeader == nullptr;
}


MatrixNode* Matrix::getExistingNode(int x, int y) {

	MatrixNode* aux = pivot->nextHeader->below;

	return nullptr;

}


void Matrix::addUser(User user, std::string _dept, std::string _emp) {

	HeaderNode* depart;
	HeaderNode* empr;
	MatrixNode* userNode;

	if (isEmpty()) {

		depart = new HeaderNode(_dept, 0, pivot->y + 1);
		empr = new HeaderNode(_emp, pivot->x + 1, 0);

		MatrixNode* newNode = new MatrixNode(empr->x, depart->y);
		newNode->addUser(user);
		
		depart->below = newNode;
		empr->next = newNode;
		
		pivot->nextHeader = depart;
		pivot->belowHeader = empr;

		width++;
		height++;

	}
	else {

		HeaderNode* depart = pivot->nextHeader;
		HeaderNode*  empr = pivot->belowHeader;

		bool deptExist = false;
		bool empExist = false;


		while (depart->nextHeader!=nullptr) {

			if (depart->name == _dept) {
				deptExist = true;
				break;
			}

			depart = depart->nextHeader;
		}
		if (depart->name == _dept)
			deptExist = true;

		while (empr->belowHeader != nullptr) {

			if (empr->name == _emp) {
				empExist = true;
				break;
			}

			empr = empr->belowHeader;
		}
		if (empr->name == _emp)
			empExist = true;
		
		

		if (deptExist && empExist) {//SI EXISTE EL DEPARTAMENTO Y LA EMPRESA

			int y = depart->y , x = empr->x;

			userNode = new MatrixNode(x, y);

			HeaderNode* aux = pivot;
			MatrixNode* horizontal = empr->next;

			do {

				if (aux->y == y) {

					if (aux->below->x > x) {//AGREGAR AL INICIO

						userNode->addUser(user);

						aux->below->above = userNode;
						userNode->below = aux->below;
						aux->below = userNode;

						//*******************************************

						if (horizontal->y > y) {
							empr->next->previous = userNode;
							userNode->next = empr->next;
							empr->next = userNode;
						}
						else if (horizontal->y < y) {

							do
							{

								if (horizontal->next == nullptr) {
									horizontal->next = userNode;
									userNode->previous = horizontal;

									break;
								}
								if (horizontal->y < y) {
									horizontal = horizontal->next;
								}
								else if (horizontal->y > y) {

									horizontal->previous->next = userNode;
									userNode->previous = horizontal->previous->next;

									horizontal->previous = userNode;
									userNode->next = horizontal;

									break;

								}


							} while (horizontal != nullptr);

						}

						//*******************************************

						break;
					}
					else if (aux->below->x == x) {//AGREGAR EN LISTA EXISTENTE

						aux->below->addUser(user);
						break;
					}
					else if (aux->below->x < x) {//AGREGAR AL MEDIO/FINAL

						MatrixNode* vertical = aux->below;

						do {


							if (vertical->below==nullptr) {
								userNode->addUser(user);
								userNode->above = vertical;
								vertical->below = userNode;


									//*******************************************

									if (horizontal->y > y) {
										empr->next->previous = userNode;
										userNode->next = empr->next;
										empr->next = userNode;
									}
									else if (horizontal->y < y) {

										do
										{

											if (horizontal->next == nullptr) {
												horizontal->next = userNode;
												userNode->previous = horizontal;

												break;
											}
											if (horizontal->y < y) {
												horizontal = horizontal->next;
											}
											else if (horizontal->y > y) {

												horizontal->previous->next = userNode;
												userNode->previous = horizontal->previous->next;

												horizontal->previous = userNode;
												userNode->next = horizontal;

												break;

											}


										} while (horizontal != nullptr);

									}

									//*******************************************


								break;
							}
							if (vertical->x == x) {

								vertical->addUser(user);
								break;

							}
							else if (vertical->x > x) {

								userNode->addUser(user);
								
								vertical->above->below = userNode;
								userNode->above = vertical->above;
								
								vertical->above = userNode;
								userNode->below = vertical;

								//*******************************************

								if (horizontal->y > y) {
									empr->next->previous = userNode;
									userNode->next = empr->next;
									empr->next = userNode;
								}
								else if (horizontal->y < y) {

									do
									{

										if (horizontal->next == nullptr && y > horizontal->y) {
											horizontal->next = userNode;
											userNode->previous = horizontal;

											break;
										}
										if (horizontal->y < y) {
											horizontal = horizontal->next;
										}
										else if (horizontal->y > y) {

											horizontal->previous->next = userNode;
											userNode->previous = horizontal->previous;

											horizontal->previous = userNode;
											userNode->next = horizontal;

											break;
										}


									} while (horizontal != nullptr);

								}

								//*******************************************

								break;
							}
							else {

								vertical = vertical->below;

							}

						} while (vertical!=nullptr);

						break;

					}


				}
				else {
					aux = aux->nextHeader;
				}


			} while (aux->nextHeader != nullptr);

		}
		else if (!deptExist && !empExist) {//SI NO EXISTE EL DEPARTAMENTO NI LA EPMRESA

			HeaderNode* depar = new HeaderNode(_dept, 0, depart->y + 1);
			HeaderNode* emp = new HeaderNode(_emp, empr->x + 1, 0);
			userNode = new MatrixNode(empr->x + 1, depart->y + 1);
			userNode->addUser(user);

			depar->below = userNode;
			emp->next = userNode;

			empr->belowHeader = emp;
			depart->nextHeader = depar;

			width++;
			height++;

		}
		else if (deptExist && !empExist) {//SI EL DEPARTAMENTO EXISTE Y LA EMPRESA NO

			HeaderNode* emp = new HeaderNode(_emp, empr->x + 1, 0);
			
			MatrixNode* aux = depart->below;

			while (aux->below != nullptr) {
				aux = aux->below;
			}

			userNode = new MatrixNode(emp->x, depart->y);
			userNode->addUser(user);
			userNode->above = aux;
			aux->below = userNode;

			emp->next = userNode;
			empr->belowHeader = emp;

			height++;

		}
		else if (!deptExist && empExist) {//SI LA EMPRESA EXISTE Y EL DEPARTAMENTO NO

			HeaderNode* depar = new HeaderNode(_dept, 0, depart->y + 1);
			
			MatrixNode* aux = empr->next;

			while (aux->next != nullptr) {
				aux = aux->next;
			}

			userNode = new MatrixNode(empr->x, depar->y);
			userNode->addUser(user);
			userNode->previous = aux;
			aux->next = userNode;

			depar->below = userNode;
			depart->nextHeader = depar;


			width++;
		}
		
	}
}


