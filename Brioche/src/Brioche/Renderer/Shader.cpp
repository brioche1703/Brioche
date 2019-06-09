#include "brpch.h"

#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Brioche {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		BR_CORE_ASSERT(false, "RendererAPI:None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		BR_CORE_ASSERT(false, "RendererAPI:Unknown RendererAPI");
		return nullptr;
	}

}