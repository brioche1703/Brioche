#include "brpch.h"

#include "VertexArray.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Brioche {

	VertexArray * VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: BR_CORE_ASSERT(false, "RenderAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}

		BR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}