// #include<iostream>
// #include<glad/glad.h>
// #include<GLFW/glfw3.h>
// #include<stb_image.h>
// #include<glm/glm.hpp>
// #include<glm/gtc/matrix_transform.hpp>
// #include<glm/gtc/type_ptr.hpp>
// #include"imgui/imgui.h"
// #include"imgui/imgui_impl_glfw.h"
// #include"imgui/imgui_impl_opengl3.h"

// #include "Mesh.h"
//
// #define W_HEIGHT 1080
// #define W_WIDTH 1920
//
// bool isPaused = false;
// // Vertices coordinates
// Vertex vertices[] =
// { //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
//
// 	//bottom face
// 	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
// 	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
// 	Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
// 	Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
// 	//up face
// 	Vertex{glm::vec3(-1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
// 	Vertex{glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
// 	Vertex{glm::vec3( 1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
// 	Vertex{glm::vec3( 1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
// 	//left face
// 	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
// 	Vertex{glm::vec3(-1.0f, 2.0f,  1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
// 	Vertex{glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
// 	Vertex{glm::vec3( -1.0f, 0.0f, -1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
// 	//right face
// 	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
// 	Vertex{glm::vec3(1.0f, 2.0f,  1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
// 	Vertex{glm::vec3(1.0f, 2.0f, -1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
// 	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
// 	//front face
// 	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
// 	Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
// 	Vertex{glm::vec3( 1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
// 	Vertex{glm::vec3(-1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
// 	//back face
// 	Vertex{glm::vec3(-1.0f, 0.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
// 	Vertex{glm::vec3( 1.0f, 0.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
// 	Vertex{glm::vec3( 1.0f, 2.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
// 	Vertex{glm::vec3(-1.0f, 2.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
// };
//
//
// // Indices for vertices order
// GLuint indices[] =
// {
// 	0, 1, 2,
// 	0, 2, 3,
//
// 	4, 5, 6,
// 	4, 6, 7,
//
// 	8, 9, 10,
// 	8, 10, 11,
//
// 	12, 13, 14,
// 	12, 14, 15,
//
// 	16, 17, 18,
// 	16, 18, 19,
//
// 	20, 21, 22,
// 	20, 22, 23,
//
// 	24, 25, 26,
// 	24, 26, 27
// };
//
//
//
// Vertex lightVertices[] =
// { //     COORDINATES     //
// 	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
// 	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
// 	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
// 	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
// 	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
// 	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
// 	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
// 	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
// };
//
// GLuint lightIndices[] =
// {
// 	0, 1, 2,
// 	0, 2, 3,
// 	0, 4, 7,
// 	0, 7, 3,
// 	3, 7, 6,
// 	3, 6, 2,
// 	2, 6, 5,
// 	2, 5, 1,
// 	1, 5, 4,
// 	1, 4, 0,
// 	4, 5, 6,
// 	4, 6, 7
// };
//
// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
// 	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
// 		isPaused = !isPaused;
// 	}
// }
//
//
// int main()
// {
// 	glfwInit();
//
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
// 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
// 	GLFWwindow* window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "OpenGl Window", NULL, NULL);
//
//
// 	if (window == NULL)
// 	{
// 		std::cout << "window failed" << std::endl;
// 		glfwTerminate();
// 		return -1;
// 	}
// 	glfwMakeContextCurrent(window);
//
//
// 	gladLoadGL();
//
// 	glViewport(0,0,W_WIDTH, W_HEIGHT);
//
// 	Texture textures[]{
// 		Texture("/home/osmangelmez/CLionProjects/GLFW-CMake-starter/src/planks.png", "diffuse", 0),
// 		Texture("/home/osmangelmez/CLionProjects/GLFW-CMake-starter/src/planksSpec.png", "specular", 1)
// 	};
//
// 	Shader shaderProgram;
// 	try {
// 		shaderProgram = Shader("/home/osmangelmez/CLionProjects/GLFW-CMake-starter/src/default.vert", "/home/osmangelmez/CLionProjects/GLFW-CMake-starter/src/default.frag");
// 		// continue using shader...
// 	} catch (const std::exception& e) {
// 		std::cerr << "Shader error: " << e.what() << std::endl;
// 		return -1;  // or handle as appropriate
// 	}
//
// 	std::vector<Vertex> verts(vertices,vertices+sizeof(vertices)/sizeof(Vertex));
// 	std::vector<GLuint> inds(indices,indices+sizeof(indices)/sizeof(GLuint));
// 	std::vector<Texture> tex(textures,textures+sizeof(textures)/sizeof(Texture));
//
// 	Mesh floor(verts,inds,tex);
//
//
//
// 	Shader lightShader("/home/osmangelmez/CLionProjects/GLFW-CMake-starter/src/light.vert", "/home/osmangelmez/CLionProjects/GLFW-CMake-starter/src/light.frag");
// 	std::vector<Vertex> light_verts(lightVertices,lightVertices+sizeof(lightVertices)/sizeof(Vertex));
// 	std::vector<GLuint> light_inds(lightIndices,lightIndices+sizeof(lightIndices)/sizeof(GLuint));
//
// 	Mesh light(light_verts,light_inds,tex);
//
//
//
// 	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
// 	glm::vec3 lightPos = glm::vec3(0.0f, 3.0f, 2.0f);
// 	glm::mat4 lightModel = glm::mat4(1.0f);
// 	lightModel = glm::translate(lightModel, lightPos);
//
// 	glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
// 	glm::mat4 pyramidModel = glm::mat4(1.0f);
// 	pyramidModel = glm::translate(pyramidModel, pyramidPos);
//
// 	lightShader.Activate();
// 	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
// 	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x,lightColor.y,lightColor.z,lightColor.w);
// 	shaderProgram.Activate();
// 	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
// 	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
// 	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//
// 	glEnable(GL_DEPTH_TEST);
//
// 	Camera camera(W_WIDTH, W_HEIGHT, glm::vec3(0.0f, 2.0f, 2.0f));
//
// 	IMGUI_CHECKVERSION();
// 	ImGui::CreateContext();
// 	ImGuiIO& io = ImGui::GetIO();(void)io;
// 	ImGui::StyleColorsDark();
// 	ImGui_ImplGlfw_InitForOpenGL(window, true);
// 	ImGui_ImplOpenGL3_Init("#version 330 core");
//
// 	while (!glfwWindowShouldClose(window))
// 	{
//
//
// 		glClearColor(0.3f, 0.3f, 0.5f, 1.0f);
// 		// clean the back buffer and depth buffer
// 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
// 		// imgui start functions
// 		ImGui_ImplOpenGL3_NewFrame();
// 		ImGui_ImplGlfw_NewFrame();
// 		ImGui::NewFrame();
//
//
//
//
//
//
//
// 		if (!isPaused) {
//
// 			camera.Input(window);
// 		}
// 		camera.UpdateMatrix(60.0f, 0.1f, 100.0f);
//
// 		floor.Draw(shaderProgram,camera);
// 		light.Draw(lightShader,camera);
//
//
// 		// imgui render functions
// 		ImGui::Render();
// 		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//
// 		glfwSetKeyCallback(window,key_callback);
//
// 		glfwSwapBuffers(window);
// 		// Take care of all GLFW events
// 		glfwPollEvents();
// 	}
//
// 	ImGui_ImplOpenGL3_Shutdown();
// 	ImGui_ImplGlfw_Shutdown();
// 	ImGui::DestroyContext();
// 	// Delete all the objects we've created
//
//
// 	shaderProgram.Delete();
//
// 	lightShader.Delete();
// 	// Delete window before ending the program
// 	glfwDestroyWindow(window);
// 	// Terminate GLFW before ending the program
// 	glfwTerminate();
// 	return 0;
// }

#include"Model.h"
#include "stb_image.h"
#define WIDTH 1920
#define HEIGHT 1080


Mesh createPlain() {
	std::vector<Vertex> vertices = {
		Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
	};

	std::vector<GLuint> indices = {
		0, 2, 1,   // first triangle
		0,3,2    // second triangle
	};

	// Empty textures (since you don’t want textures)
	std::vector<Texture> textures;

	return Mesh(vertices, indices, textures);
}
Mesh createCube() {
	std::vector<Vertex> vertices = {
			Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
		//up face
		Vertex{glm::vec3(-1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
		//left face
		Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(-1.0f, 2.0f,  1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3( -1.0f, 0.0f, -1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)},
		//right face
		Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3(1.0f, 2.0f,  1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 2.0f, -1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
		//front face
		Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(-1.0f, 2.0f,  1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
		//back face
		Vertex{glm::vec3(-1.0f, 0.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		Vertex{glm::vec3( 1.0f, 0.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3( 1.0f, 2.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{glm::vec3(-1.0f, 2.0f,  -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
	};

	std::vector<GLuint> indices = {
		0, 1, 2,
		0, 2, 3,

		4, 5, 6,
		4, 6, 7,

		8, 9, 10,
		8, 10, 11,

		12, 13, 14,
		12, 14, 15,

		16, 17, 18,
		16, 18, 19,

		20, 21, 22,
		20, 22, 23,

		24, 25, 26,
		24, 26, 27
	};

	// Empty textures (since you don’t want textures)
	std::vector<Texture> textures;

	return Mesh(vertices, indices, textures);
}


void FrameBufferElements(float vertices[]) {
	// Prepare framebuffer rectangle VBO and VAO
	unsigned int rectVAO, rectVBO;
	glGenVertexArrays(1, &rectVAO);
	glGenBuffers(1, &rectVBO);
	glBindVertexArray(rectVAO);
	glBindBuffer(GL_ARRAY_BUFFER, rectVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

	// Create Frame Buffer Object
	unsigned int FBO;
	glGenFramebuffers(1, &FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);

	// Create Framebuffer Texture
	unsigned int frameBufferTex;
	glGenTextures(1, &frameBufferTex);
	glBindTexture(GL_TEXTURE_2D, frameBufferTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Prevents edge bleeding
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, frameBufferTex, 0);

	// Create Render Buffer Object
	unsigned int RBO;
	glGenRenderbuffers(1, &RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, WIDTH, HEIGHT);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);

	// Error checking framebuffer
	auto fboStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (fboStatus != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Framebuffer error: " << fboStatus << std::endl;

	// Bind the custom framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Enable depth testing since it's disabled when drawing the framebuffer rectangle
	glEnable(GL_DEPTH_TEST);

	// Bind the default framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Draw the framebuffer rectangle
	//frameBufferProgram.Activate();
	glBindVertexArray(rectVAO);
	glDisable(GL_DEPTH_TEST); // prevents framebuffer rectangle from being discarded
	glBindTexture(GL_TEXTURE_2D, frameBufferTex);
	glDrawArrays(GL_TRIANGLES, 0, 6);

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

float rectangleVertices[] =
{
	// Coords    // texCoords
	1.0f, -1.0f,  1.0f, 0.0f,
   -1.0f, -1.0f,  0.0f, 0.0f,
   -1.0f,  1.0f,  0.0f, 1.0f,

	1.0f,  1.0f,  1.0f, 1.0f,
	1.0f, -1.0f,  1.0f, 0.0f,
   -1.0f,  1.0f,  0.0f, 1.0f
};

float skyboxVertices[] =
{
	//   Coordinates
	-1.0f, -1.0f,  1.0f,//        7--------6
	 1.0f, -1.0f,  1.0f,//       /|       /|
	 1.0f, -1.0f, -1.0f,//      4--------5 |
	-1.0f, -1.0f, -1.0f,//      | |      | |
	-1.0f,  1.0f,  1.0f,//      | 3------|-2
	 1.0f,  1.0f,  1.0f,//      |/       |/
	 1.0f,  1.0f, -1.0f,//      0--------1
	-1.0f,  1.0f, -1.0f
};

unsigned int skyboxIndices[] =
{
	// Right
	6,2,1,1,5,6,
	// Left
	7,4,0,0,3,7,
	// Top
	6,5,4,4,7,6,
	// Bottom
	2,3,0,0,1,2,
	// Back
	5,1,0,0,4,5,

	// Front
	6,7,3,3,2,6

};

float randf()
{
	return -1.0f + (rand() / (RAND_MAX / 2.0f));
}

int main()
{

	// Initialize GLFW
	glfwInit();
	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// glfwGetWindowSize(window,&width,&height);
	// glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

	std::string parentDir = "/home/osmangelmez/CLionProjects/OpenGL_proj";
	// Generates Shader object using shaders default.vert and default.frag

	Shader shaderProgram("/home/osmangelmez/CLionProjects/OpenGL_proj/shaders/default.vert", "/home/osmangelmez/CLionProjects/OpenGL_proj/shaders/default.frag");
	Shader skyboxShader("/home/osmangelmez/CLionProjects/OpenGL_proj/shaders/skybox.vert", "/home/osmangelmez/CLionProjects/OpenGL_proj/shaders/skybox.frag");
	Shader asteroidShader("/home/osmangelmez/CLionProjects/OpenGL_proj/shaders/asteroid.vert", "/home/osmangelmez/CLionProjects/OpenGL_proj/shaders/default.frag");
	// Take care of all the light related things
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.0f, 8.0f, 8.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	asteroidShader.Activate();
	glUniform4f(glGetUniformLocation(asteroidShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(asteroidShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	skyboxShader.Activate();
	glUniform1i(glGetUniformLocation(skyboxShader.ID, "skybox"), 0);

	// frameBufferProgram.Activate();
	// glUniform1i(glGetUniformLocation(frameBufferProgram.ID, "screenTexture"), 0);


	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Enables Cull Facing
	glEnable(GL_CULL_FACE);
	// Keeps front faces
	glCullFace(GL_FRONT);
	// Uses counter clock-wise standard
	glFrontFace(GL_CW);


	// Creates camera object
	Camera camera(WIDTH, HEIGHT, glm::vec3(0.0f, 3.0f, 3.0f));


	Model jupyter("/home/osmangelmez/CLionProjects/OpenGL_proj/models/jupyter/scene.gltf");
	// Variables to create periodic event for FPS displaying
	double prevTime = 0.0;
	double crntTime = 0.0;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter = 0;

	unsigned int skyboxVAO, skyboxVBO, skyboxEBO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glGenBuffers(1, &skyboxEBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, skyboxEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(skyboxIndices), &skyboxIndices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	std::string facesCubemap[6] =
	{
		"/home/osmangelmez/CLionProjects/OpenGL_proj/models/spacebox/right.png",
		"/home/osmangelmez/CLionProjects/OpenGL_proj/models/spacebox/left.png",

		"/home/osmangelmez/CLionProjects/OpenGL_proj/models/spacebox/top.png",
		"/home/osmangelmez/CLionProjects/OpenGL_proj/models/spacebox/bottom.png",
		"/home/osmangelmez/CLionProjects/OpenGL_proj/models/spacebox/front.png",
		"/home/osmangelmez/CLionProjects/OpenGL_proj/models/spacebox/back.png"
	};

	unsigned int cubemapTexture;
	glGenTextures(1, &cubemapTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// These are very important to prevent seams
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	// Cycles through all the textures and attaches them to the cubemap object
	for (unsigned int i = 0; i < 6; i++)
	{
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(false);
		unsigned char* data = stbi_load(facesCubemap[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{

			glTexImage2D
			(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0,
				GL_RGB,
				width,
				height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				data
			);

			stbi_image_free(data);
		}
		else
		{
			std::cout << "Failed to load texture: " << facesCubemap[i] << std::endl;
			stbi_image_free(data);
		}
	}

	// The number of asteroids to be created
	const unsigned int number = 15000;
	// Radius of circle around which asteroids orbit
	float radius = 100.0f;
	// How much ateroids deviate from the radius
	float radiusDeviation = 25.0f;

	// Holds all transformations for the asteroids
	std::vector <glm::mat4> instanceMatrix;

	for (unsigned int i = 0; i < number; i++)
	{
		// Generates x and y for the function x^2 + y^2 = radius^2 which is a circle
		float x = randf();
		float finalRadius = radius + randf() * radiusDeviation;
		float y = ((rand() % 2) * 2 - 1) * sqrt(1.0f - x * x);

		// Holds transformations before multiplying them
		glm::vec3 tempTranslation;
		glm::quat tempRotation;
		glm::vec3 tempScale;

		// Makes the random distribution more even
		if (randf() > 0.5f)
		{
			// Generates a translation near a circle of radius "radius"
			tempTranslation = glm::vec3(y * finalRadius, randf(), x * finalRadius);
		}
		else
		{
			// Generates a translation near a circle of radius "radius"
			tempTranslation = glm::vec3(x * finalRadius, randf(), y * finalRadius);
		}
		// Generates random rotations
		tempRotation = glm::quat(1.0f, randf(), randf(), randf());
		// Generates random scales
		tempScale = 0.1f * glm::vec3(randf(), randf(), randf());


		// Initialize matrices
		glm::mat4 trans = glm::mat4(1.0f);
		glm::mat4 rot = glm::mat4(1.0f);
		glm::mat4 sca = glm::mat4(1.0f);

		// Transform the matrices to their correct form
		trans = glm::translate(trans, tempTranslation);
		rot = glm::mat4_cast(tempRotation);
		sca = glm::scale(sca, tempScale);

		// Push matrix transformation
		instanceMatrix.push_back(trans * rot * sca);
	}
	Model asteroid("/home/osmangelmez/CLionProjects/OpenGL_proj/models/asteroid/scene.gltf",number,instanceMatrix);


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{



		// Updates counter and times
		crntTime = glfwGetTime();
		timeDiff = crntTime - prevTime;
		counter++;

		if (timeDiff >= 1.0 / 30.0)
		{
			// Creates new title
			std::string FPS = std::to_string((1.0 / timeDiff) * counter);
			std::string ms = std::to_string((timeDiff / counter) * 1000);
			std::string newTitle = "YoutubeOpenGL - " + FPS + "FPS / " + ms + "ms";
			glfwSetWindowTitle(window, newTitle.c_str());

			// Resets times and counter
			prevTime = crntTime;
			counter = 0;

			// Use this if you have disabled VSync
			//camera.Inputs(window);
		}
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Handles camera inputs
		camera.Input(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.UpdateMatrix(45.0f, 0.1f, 1000.0f);
		//glFrontFace(GL_CCW);
		// Draw the asteroids
		asteroid.Draw(asteroidShader, camera);


		// Draw jupiter
		jupyter.Draw(shaderProgram, camera);
		//Since the cubemap will always have a depth of 1.0, we need that equal sign so it doesn't get discarded
		glDepthFunc(GL_LEQUAL);

		skyboxShader.Activate();
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		// We make the mat4 into a mat3 and then a mat4 again in order to get rid of the last row and column
		// The last row and column affect the translation of the skybox (which we don't want to affect)
		view = glm::mat4(glm::mat3(glm::lookAt(camera.Position, camera.Position + camera.Direction, camera.Up)));
		projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / HEIGHT, 0.1f, 100.0f);
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		// Draws the cubemap as the last object so we can save a bit of performance by discarding all fragments
		// where an object is present (a depth of 1.0f will always fail against any object's depth value)
		glBindVertexArray(skyboxVAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Switch back to the normal depth function
		glDepthFunc(GL_LESS);






		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();

	}



	// Delete all the objects we've created
	shaderProgram.Delete();
	skyboxShader.Delete();
	glDeleteBuffers(1,&skyboxVBO);
	glDeleteBuffers(1,&skyboxEBO);
	glDeleteVertexArrays(1,&skyboxVAO);

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}
