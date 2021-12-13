#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"
class EntityManager {

public:
	Client* firstClient;
	int leavingClients = 0;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void addInspector(Inspector *i);
	void removeLeavingClients();
	std::vector<Entity*> entities;
};