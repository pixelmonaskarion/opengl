#ifndef SPRITE_H
#define SPRITE_H
#include "mesh.h"
#include "camera.h"

class Sprite {

public:

	Sprite(Texture texture, int widthIn, int heightIn, glm::vec3 positionIn) {
		position = positionIn;
		width = widthIn;
		height = heightIn;
		Vertex TL, TR, BL, BR;
		TL.Position = glm::vec3(-0.5f, 0.5f, 0);
		TL.TexCoords = glm::vec2(0, 0);
		TR.Position = glm::vec3(0.5f, 0.5f, 0);
		TL.TexCoords = glm::vec2(1, 0);
		BL.Position = glm::vec3(-0.5f, -0.5f, 0);
		TL.TexCoords = glm::vec2(0, 1);
		BR.Position = glm::vec3(0.5f, -0.5f, 0);
		TL.TexCoords = glm::vec2(1, 1);
		vector<Vertex> vertices = {
			TL, TR, BL, BR
		};
		vector<unsigned int> indices = {
			2, 0, 1,
			2, 1, 3
		};
		vector<Texture> textures{
			texture
		};
		mesh = Mesh(vertices, indices, textures);
	}

	void Draw(Shader shader, Camera camera) {
		shader.use();
		mesh.Draw(shader, glm::vec3(position.x, position.y, 0), glm::vec3(0,0,0), glm::vec3(width, height, 1));
	}

private:
	Mesh mesh = Mesh();
	glm::vec3 position;
	unsigned int width, height;
};

#endif