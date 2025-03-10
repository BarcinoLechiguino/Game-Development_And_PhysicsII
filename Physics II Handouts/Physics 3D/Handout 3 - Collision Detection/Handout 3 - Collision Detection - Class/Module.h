#pragma once

class  PhysBody3D;

class Module
{
private :
	bool enabled;

public:
	Module(bool start_enabled = true) : enabled(start_enabled)
	{}

	virtual ~Module()
	{}

	virtual bool Init() 
	{
		return true; 
	}

	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate(float dt)
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update(float dt)
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate(float dt)
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp() 
	{ 
		return true; 
	}

	//TODO 7: Create virtual method "On Collision", that recieves the two colliding PhysBodies
	virtual void OnCollision(PhysBody3D* Phys1, PhysBody3D* Phys2)
	{

	}
};