#pragma once

#include <vector>


#include "../data/KeyRole.h"
#include "../data/ControlsTable.h"
#include "../Config.h"

#include "IControlsObserver.h"

class Controller
{
public:
	void addEventObserver(IControlsObserver* observer);
	void setConfig(const Config& config);

	bool isKeyActive(KeyRole key) const;
	vec2 getMousePosition() const;
	vec2 getMouseDelta() const;

	void update(double deltaTime);

private:
	std::vector<IControlsObserver*> eventObservers_;
	Config config_;
	ControlsTable controlsTable_;

	friend class Window;
};