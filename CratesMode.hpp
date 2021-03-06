#pragma once

#include "Mode.hpp"

#include "MeshBuffer.hpp"
#include "WalkMesh.hpp"
#include "GL.hpp"
#include "Scene.hpp"
#include "Sound.hpp"

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>

// The 'CratesMode' shows scene with some crates in it:

struct CratesMode : public Mode {
	CratesMode();
	virtual ~CratesMode();

	//handle_event is called when new mouse or keyboard events are received:
	// (note that this might be many times per frame or never)
	//The function should return 'true' if it handled the event.
	virtual bool handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) override;

	//update is called at the start of a new frame, after events are handled:
	virtual void update(float elapsed) override;

	//draw is called after update:
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//starts up a 'quit/resume' pause menu:
	void show_pause_menu();

	struct {
		bool forward = false;
		bool backward = false;
		bool left = false;
		bool right = false;
	} controls;

	bool mouse_captured = false;

	WalkMesh::WalkPoint walk_point;

	Scene scene;
	Scene::Camera *camera = nullptr;

	Scene::Object *player = nullptr;
	std::map< int, Scene::Transform * > transform_dict;
	
	uint32_t timer = 1000;
	float speed = 20.0f;

	glm::vec3 old_up;
	//this 'loop' sample is played at the large crate:
	std::shared_ptr< Sound::PlayingSample > loop;
};
