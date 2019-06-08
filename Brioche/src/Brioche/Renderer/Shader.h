#pragma once

#include <string>

namespace Brioche {


	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind();
		void Unbind();

	private:
		uint32_t m_RendererID;
	};
}
