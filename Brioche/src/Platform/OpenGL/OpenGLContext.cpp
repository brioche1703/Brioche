#include "brpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Brioche {

	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BR_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BR_CORE_ASSERT(status, "Failed to initialize Glad!");

		BR_CORE_INFO("OpenGL Info:");
		BR_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		BR_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		BR_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}