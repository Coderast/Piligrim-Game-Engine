#include "Config.h"

#include <GLFW/glfw3.h>
namespace piligrim{
	namespace controls {



		char Config::invalidConfigMessage[] = "Your 'controls.config' file is incorrect!";



		Config::Config()
		{

			bindings_[KeyRole::Escape]  = GLFW_KEY_ESCAPE;

			bindings_[KeyRole::Up]      = GLFW_KEY_SPACE;
			bindings_[KeyRole::Down]    = GLFW_KEY_LEFT_SHIFT;

			bindings_[KeyRole::Forward] = GLFW_KEY_W;
			bindings_[KeyRole::Left]    = GLFW_KEY_A;
			bindings_[KeyRole::Back]    = GLFW_KEY_S;
			bindings_[KeyRole::Right]   = GLFW_KEY_D;

			bindings_[KeyRole::Print]   = GLFW_KEY_P;
			bindings_[KeyRole::Center]  = GLFW_KEY_C;
		}



		int Config::getKeyCode(KeyRole key) const
		{
			return bindings_[key];
		}



		void Config::load(std::string path)
		{
			std::string config = FileUtils::readFile(path);
			std::pair<KeyRole, int> binding;
			while (config.size() != 0) {
				binding = getNextBinding(config);
				bindings_[binding.first] = binding.second;
			}
		}



		std::pair<KeyRole, int> Config::getNextBinding(std::string & config)
		{
			std::pair<KeyRole, int> binding;
			unsigned int charId = 0;
			unsigned int confLength = config.size();
			std::string word = "";

			for (; charId < confLength && config[charId] != ':'; charId++) {
				word += config[charId];
			}
			charId++;
			for (; charId < confLength && config[charId] == ' '; charId++);

			if (charId >= confLength) {
				throw std::invalid_argument(invalidConfigMessage);
			}

			binding.first = parseKeyRole(word);
			word = "";

			if (charId >= confLength) {
				throw std::invalid_argument(invalidConfigMessage);
			}

			for (; charId < confLength && config[charId] != '\n'; charId++) {
				word += config[charId];
			}
			for (; charId < confLength &&(config[charId] == '\n' || config[charId] == ' ') ; charId++);

			binding.second = parseKeyCode(word);

			config = config.substr(charId, config.size() - charId);

			return binding;
		}



		KeyRole Config::parseKeyRole(const std::string & str)
		{
			if (_strcmpi(str.c_str(), "Forward") == 0) {
				return KeyRole::Forward;
			}

			if (_strcmpi(str.c_str(), "Back") == 0) {
				return KeyRole::Back;
			}

			if (_strcmpi(str.c_str(), "Left") == 0) {
				return KeyRole::Left;
			}

			if (_strcmpi(str.c_str(), "Right") == 0) {
				return KeyRole::Right;
			}

			if (_strcmpi(str.c_str(), "Up") == 0) {
				return KeyRole::Up;
			}

			if (_strcmpi(str.c_str(), "Down") == 0) {
				return KeyRole::Down;
			}

			if (_strcmpi(str.c_str(), "Escape") == 0) {
				return KeyRole::Escape;
			}

			if (_strcmpi(str.c_str(), "Center") == 0) {
				return KeyRole::Center;
			}

			if (_strcmpi(str.c_str(), "Print") == 0) {
				return KeyRole::Print;
			}

			throw std::invalid_argument(invalidConfigMessage);
		}



		int Config::parseKeyCode(const std::string & str)
		{
			if (str.size() == 1) {
				return static_cast<int>(str[0]);
			}

			if (_strcmpi(str.c_str(), "Esc") == 0) {
				return GLFW_KEY_ESCAPE;
			}

			if (_strcmpi(str.c_str(), "Space") == 0) {
				return GLFW_KEY_SPACE;
			}

			if (_strcmpi(str.c_str(), "Left Shift") == 0) {
				return GLFW_KEY_LEFT_SHIFT;
			}

			if (_strcmpi(str.c_str(), "Right Shift") == 0) {
				return GLFW_KEY_RIGHT_SHIFT;
			}

			throw std::invalid_argument(invalidConfigMessage);
		}



	}
}