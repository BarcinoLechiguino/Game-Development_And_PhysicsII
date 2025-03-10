#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModuleCamera3D.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	//vec3 position = { 1, 1, 0 };
	App->camera->Position.Set(1, 1, 1);
	
	vec3 center = { 0, 0, 0 };
	App->camera->LookAt(center);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference
	Plane plane;
	plane.axis = true;
	plane.Render();

	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe
	Sphere sphere(0.5f);
	sphere.Render();

	Sphere sphereWireframe(0.5f);
	sphere.wire = true;
	sphere.SetPos(-1, 0, 0);
	sphere.Render();

	Cylinder cylinder(0.5f, 0.5f);
	cylinder.SetPos(0, 0,-2);
	cylinder.Render();
	
	Cube cube(1, 1, 1);
	cube.SetPos(0, -2, 0);
	cube.Render();

	return UPDATE_CONTINUE;
}

