#pragma once
#include <string>

#include <GL/glew.h>

#include <FreeImage.h>
#include "../../../utils/imageload.h"
#include "../../../utils/glcall.h"

namespace piligrim {
	namespace graphics {

		struct Texture
		{
		public:
			Texture();
			Texture(std::string fileName);

			void bind() const;
			void unbind() const;

			GLuint getId() const;
			unsigned int getWidth() const;
			unsigned int getHeight() const;

			void texDelete() const;
			void load(std::string fileName);

		public:
			unsigned int slot = 0;

		private:
			std::string fileName_;
			GLuint id_;
			unsigned int width_;
			unsigned int height_;
			BYTE* pixels_;
		};

	}
}