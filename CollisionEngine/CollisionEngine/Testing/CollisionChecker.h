#ifndef CC_TEST_H
#define CC_TEST_H

#include "../Engine/Common.h"
#include "../Engine/Component.h"
#include "../Engine/Graphics/Shader.h"
#include "../Engine/Physics/Body.h"

class CollisionChecker : public Component {

	/// rendering
	color drawColor;
	Shader shader;
	GLuint VBO, VAO, EBO;
	GLuint colorLoc, posLoc;

	/// components
	Body* bd;
	class CircleCollider* cc;

public:

	CollisionChecker();
	~CollisionChecker();

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float& delta) override;
	virtual void Draw() override;
	virtual void OnCollision() override;

	void SetVelocity(vec2 vel);

};


#endif // !CC_TEST_H