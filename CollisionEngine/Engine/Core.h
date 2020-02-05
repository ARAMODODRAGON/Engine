#ifndef CORE_H
#define CORE_H

class Core { 

	// variables
	
public:
	
	Core();
	~Core() { Exit(); }

	// events
	void Init();
	void Exit();
	void Update();
	void Render();

	// starts the engine
	void Run();


};

#endif // !CORE_H